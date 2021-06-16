#include <stdio.h>
#include "GLEStrace.h"

#define eglWaitNative_  \
    ((EGLBoolean (*)(EGLint engine))  \
    EGL_ENTRY_PTR(eglWaitNative_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglWaitNative (EGLint engine)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglWaitNative_)
        ret = eglWaitNative_ (engine);

    fprintf (g_log_fp, "eglWaitNative(%d);\n", engine);

    return ret;
}

