#include <stdio.h>
#include "GLEStrace.h"


#define eglDestroySyncKHR_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSyncKHR sync))  \
    EGL_ENTRY_PTR(eglDestroySyncKHR_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglDestroySyncKHR (EGLDisplay dpy, EGLSyncKHR sync)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglDestroySyncKHR_)
        ret = eglDestroySyncKHR_ (dpy, sync);

    fprintf (g_log_fp, "eglDestroySyncKHR(%p, %p); // ret=%d\n",
             dpy, sync, ret);

    return ret;
}

