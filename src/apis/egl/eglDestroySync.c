#include <stdio.h>
#include "GLEStrace.h"


#define eglDestroySync_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSync sync))  \
    EGL_ENTRY_PTR(eglDestroySync_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglDestroySync (EGLDisplay dpy, EGLSync sync)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglDestroySync_)
        ret = eglDestroySync_ (dpy, sync);

    fprintf (g_log_fp, "eglDestroySync(%p, %p); // ret=%d\n",
             dpy, sync, ret);

    return ret;
}

