#include <stdio.h>
#include "GLEStrace.h"

static int  s_cnt = 0;
static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_buftype_str (EGLenum buftype)
{
    switch (buftype)
    {
    case EGL_OPENVG_IMAGE : return "EGL_OPENVG_IMAGE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", buftype);
    return s_strbuf;
}

static char *
get_attr_name_str (EGLint attr)
{
    switch (attr)
    {
    case EGL_CLIENT_APIS                : return "EGL_CLIENT_APIS";
    case EGL_VENDOR                     : return "EGL_VENDOR";
    case EGL_VERSION                    : return "EGL_VERSION";
    case EGL_EXTENSIONS                 : return "EGL_EXTENSIONS";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attr);
    return s_strbuf;
}

#define eglCreatePbufferFromClientBuffer_  \
    ((EGLSurface (*)(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list))  \
    EGL_ENTRY_PTR(eglCreatePbufferFromClientBuffer_Idx))

#define eglQuerySurface_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value))  \
    EGL_ENTRY_PTR(eglQuerySurface_Idx))


EGLAPI EGLSurface EGLAPIENTRY
eglCreatePbufferFromClientBuffer (EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint *attrib_list)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglCreatePbufferFromClientBuffer(%p, %s, %p, %p, %p);",
             dpy, get_buftype_str (buftype), buffer, config, attrib_list);
    fprintf (g_log_fp, " // [%d] (%d)\n", gles_trace_gettid(), s_cnt++);

    /* print attrib_list */
    if (attrib_list)
    {
        fprintf (g_log_fp, "EGLint attlib_list[] = {\n");
        for (int i = 0; ; i += 2)
        {
            if (attrib_list[i] == EGL_NONE)
            {
                fprintf (g_log_fp, "    EGL_NONE\n");
                break;
            }

            char *attr_str = get_attr_name_str (attrib_list[i]);
            int  attribute = attrib_list[i+1];
            fprintf (g_log_fp, "    %-30s, %d,\n", attr_str, attribute);
        }
        fprintf (g_log_fp, "};\n");
    }

    EGLSurface sfc = EGL_NO_SURFACE;
    if (eglCreatePbufferFromClientBuffer_)
    {
        sfc = eglCreatePbufferFromClientBuffer_ (dpy, buftype, buffer, config, attrib_list);

        EGLint w, h;
        if (eglQuerySurface_)
        {
            eglQuerySurface_ (dpy, sfc, EGL_WIDTH,  &w);
            eglQuerySurface_ (dpy, sfc, EGL_HEIGHT, &h);
        }
        fprintf (g_log_fp, "    // sfc = %p (%dx%d)\n", sfc, w, h);
    }
    return sfc;
}

