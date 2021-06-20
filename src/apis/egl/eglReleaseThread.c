#include <stdio.h>
#include "GLEStrace.h"


#define eglReleaseThread_  \
    ((EGLBoolean (*)(void))  \
    EGL_ENTRY_PTR(eglReleaseThread_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglReleaseThread (void)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglReleaseThread(); // pid=%d\n", gles_trace_gettid());

    if (eglReleaseThread_)
        return eglReleaseThread_ ();
    else
        return EGL_FALSE;
}

