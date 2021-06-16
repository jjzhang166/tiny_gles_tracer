#include <stdio.h>
#include "GLEStrace.h"

#define eglTerminate_  \
    ((EGLBoolean (*)(EGLDisplay dpy))  \
    EGL_ENTRY_PTR(eglTerminate_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglTerminate (EGLDisplay dpy)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglTerminate_)
        ret = eglTerminate_ (dpy);

    fprintf (g_log_fp, "eglTerminate(%p);\n", dpy);

    return ret;
}

