#include <stdio.h>
#include "GLEStrace.h"


#define eglGetConfigs_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config))  \
    EGL_ENTRY_PTR(eglGetConfigs_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglGetConfigs (EGLDisplay dpy, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetConfigs(%p, %p, %d, %p);",
             dpy, configs, config_size, num_config);
    fprintf (g_log_fp, " // [%d]", gles_trace_gettid());

    EGLBoolean ret = EGL_FALSE;
    if (eglGetConfigs_)
    {
        ret = eglGetConfigs_ (dpy, configs, config_size, num_config);
        if (num_config) fprintf (g_log_fp, " num_config = %d", *num_config);
    }
    fprintf (g_log_fp, "\n");

    return ret;
}

