#include <stdio.h>
#include "GLEStrace.h"

#define eglGetDisplay_  \
    ((EGLDisplay (*)(EGLNativeDisplayType display_id))  \
    EGL_ENTRY_PTR(eglGetDisplay_Idx))


EGLAPI EGLDisplay EGLAPIENTRY
eglGetDisplay (EGLNativeDisplayType display_id)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetDisplay(%p);", display_id);
    fprintf (g_log_fp, " // [%d]", gles_trace_gettid());

    EGLDisplay dpy = EGL_NO_DISPLAY;
    if (eglGetDisplay_)
    {
        dpy = eglGetDisplay_ (display_id);
        fprintf (g_log_fp, " dpy = %p", dpy);
    }
    fprintf (g_log_fp, "\n");

    return dpy;
}

