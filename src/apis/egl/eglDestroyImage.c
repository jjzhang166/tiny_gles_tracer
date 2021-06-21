#include <stdio.h>
#include "GLEStrace.h"

#define eglDestroyImage_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLImage image))  \
    EGL_ENTRY_PTR(eglDestroyImage_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglDestroyImage (EGLDisplay dpy, EGLImage image)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglDestroyImage_)
        ret = eglDestroyImage_ (dpy, image);

    fprintf (g_log_fp, "eglDestroyImage(%p, %p); // ret=%d\n", dpy, image, ret);
    return ret;
}

