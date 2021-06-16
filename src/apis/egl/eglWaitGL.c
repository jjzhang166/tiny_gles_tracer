#include <stdio.h>
#include "GLEStrace.h"

#define eglWaitGL_  \
    ((EGLBoolean (*)(void))  \
    EGL_ENTRY_PTR(eglWaitGL_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglWaitGL (void)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglWaitGL_)
        ret = eglWaitGL_ ();

    fprintf (g_log_fp, "eglWaitGL();\n");

    return ret;
}

