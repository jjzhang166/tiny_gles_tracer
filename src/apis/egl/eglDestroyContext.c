#include <stdio.h>
#include "GLEStrace.h"

#define eglDestroyContext_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface))  \
    EGL_ENTRY_PTR(eglDestroyContext_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglDestroyContext (EGLDisplay dpy, EGLContext ctx)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglDestroyContext(%p, %p);\n", dpy, ctx);

    if (eglDestroyContext_)
        return eglDestroyContext_ (dpy, ctx);
    else
        return EGL_FALSE;
}

