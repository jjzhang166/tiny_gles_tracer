#include <stdio.h>
#include "GLEStrace.h"

#define eglDestroySurface_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface))  \
    EGL_ENTRY_PTR(eglDestroySurface_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglDestroySurface (EGLDisplay dpy, EGLSurface surface)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglDestroySurface(%p, %p);\n", dpy, surface);

    if (eglDestroySurface_)
        return eglDestroySurface_ (dpy, surface);
    else
        return EGL_FALSE;
}

