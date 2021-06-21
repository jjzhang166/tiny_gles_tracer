#include <stdio.h>
#include "GLEStrace.h"

static int  s_cnt = 0;
static char s_strbuf[512];  // [FIXME] thread safe

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


#define eglCreatePlatformWindowSurface_  \
    ((EGLSurface (*)(EGLDisplay dpy, EGLConfig config, void *native_window, const EGLAttrib *attrib_list))  \
    EGL_ENTRY_PTR(eglCreatePlatformWindowSurface_Idx))

#define eglQuerySurface_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value))  \
    EGL_ENTRY_PTR(eglQuerySurface_Idx))


EGLAPI EGLSurface EGLAPIENTRY
eglCreatePlatformWindowSurface (EGLDisplay dpy, EGLConfig config, void *native_window, const EGLAttrib *attrib_list)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglCreatePlatformWindowSurface(%p, %p, %p, %p);", dpy, config, native_window, attrib_list);
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
    if (eglCreatePlatformWindowSurface_)
    {
        sfc = eglCreatePlatformWindowSurface_ (dpy, config, native_window, attrib_list);

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

