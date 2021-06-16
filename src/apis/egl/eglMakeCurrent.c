#include <stdio.h>
#include "GLEStrace.h"

#define eglMakeCurrent_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx))  \
    EGL_ENTRY_PTR(eglMakeCurrent_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglMakeCurrent (EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglMakeCurrent(%p, %p, %p, %p);", dpy, draw, read, ctx);
    fprintf (g_log_fp, " // [%d]\n", gles_trace_gettid());

    EGLBoolean ret = EGL_FALSE;
    if (eglMakeCurrent_)
        ret = eglMakeCurrent_ (dpy, draw, read, ctx);
    return ret;
}

