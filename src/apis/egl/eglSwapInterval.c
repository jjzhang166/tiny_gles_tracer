#include <stdio.h>
#include "GLEStrace.h"

#define eglSwapInterval_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLint interval))  \
    EGL_ENTRY_PTR(eglSwapInterval_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglSwapInterval (EGLDisplay dpy, EGLint interval)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglSwapInterval(%p, %d);\n", dpy, interval);

    if (eglSwapInterval_)
        return eglSwapInterval_ (dpy, interval);
    else
        return EGL_FALSE;
}

