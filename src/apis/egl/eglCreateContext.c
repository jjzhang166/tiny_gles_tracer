#include <stdio.h>
#include "GLEStrace.h"

static int  s_cnt = 0;
static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_attr_name_str (EGLint attr)
{
    switch (attr)
    {
    case EGL_CONTEXT_MAJOR_VERSION      : return "EGL_CONTEXT_MAJOR_VERSION";
    case EGL_CONTEXT_MINOR_VERSION      : return "EGL_CONTEXT_MINOR_VERSION";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attr);
    return s_strbuf;
}


#define eglCreateContext_  \
    ((EGLContext (*)(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list))  \
    EGL_ENTRY_PTR(eglCreateContext_Idx))


EGLAPI EGLContext EGLAPIENTRY
eglCreateContext (EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint *attrib_list)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglCreateContext(%p, %p, %p, %p);", dpy, config, share_context, attrib_list);
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

    EGLContext ctx = EGL_NO_CONTEXT;
    if (eglCreateContext_)
    {
#if 0
        EGLint attrib_list[] = {EGL_CONTEXT_MAJOR_VERSION, 3, EGL_CONTEXT_MINOR_VERSION, 0, EGL_NONE};
#endif
        ctx = eglCreateContext_ (dpy, config, share_context, attrib_list);
        fprintf (g_log_fp, "    // ctx = %p\n", ctx);
    }

    return ctx;
}

