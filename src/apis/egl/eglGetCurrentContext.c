#include <stdio.h>
#include "GLEStrace.h"

#define eglGetCurrentContext_  \
    ((EGLContext (*)(void))  \
    EGL_ENTRY_PTR(eglGetCurrentContext_Idx))


EGLAPI EGLContext EGLAPIENTRY
eglGetCurrentContext (void)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetCurrentContext(); // ");

    EGLContext ctx = EGL_NO_CONTEXT;
    if (eglGetCurrentContext_)
    {
        ctx = eglGetCurrentContext_ ();
        fprintf (g_log_fp, " ctx = %p", ctx);
    }
    fprintf (g_log_fp, "\n");

    return ctx;
}

