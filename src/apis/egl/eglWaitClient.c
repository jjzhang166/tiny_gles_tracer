#include <stdio.h>
#include "GLEStrace.h"


#define eglWaitClient_  \
    ((EGLBoolean (*)(void))  \
    EGL_ENTRY_PTR(eglWaitClient_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglWaitClient (void)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglWaitClient();\n");

    if (eglWaitClient_)
        return eglWaitClient_ ();
    else
        return EGL_FALSE;
}

