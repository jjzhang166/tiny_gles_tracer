#include <stdio.h>
#include "GLEStrace.h"

#define eglGetCurrentDisplay_  \
    ((EGLDisplay (*)(void))  \
    EGL_ENTRY_PTR(eglGetCurrentDisplay_Idx))


EGLAPI EGLDisplay EGLAPIENTRY
eglGetCurrentDisplay (void)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetCurrentDisplay(); // ");

    EGLDisplay dpy = EGL_NO_DISPLAY;
    if (eglGetCurrentDisplay_)
    {
        dpy = eglGetCurrentDisplay_ ();
        fprintf (g_log_fp, " dpy = %p", dpy);
    }
    fprintf (g_log_fp, "\n");

    return dpy;
}

