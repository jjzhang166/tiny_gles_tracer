#include <stdio.h>
#include "GLEStrace.h"

#define eglDestroyImageKHR_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLImageKHR image))  \
    EGL_ENTRY_PTR(eglDestroyImageKHR_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglDestroyImageKHR (EGLDisplay dpy, EGLImageKHR image)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglDestroyImageKHR_)
        ret = eglDestroyImageKHR_ (dpy, image);

    fprintf (g_log_fp, "eglDestroyImageKHR(%p, %p); // ret=%d\n", dpy, image, ret);
    return ret;
}

