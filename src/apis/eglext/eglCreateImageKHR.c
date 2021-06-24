#include <stdio.h>
#include "GLEStrace.h"

#define eglCreateImageKHR_  \
    ((EGLImageKHR (*)(EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint *attrib_list))  \
    EGL_ENTRY_PTR(eglCreateImageKHR_Idx))


EGLAPI EGLImageKHR EGLAPIENTRY
eglCreateImageKHR (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint *attrib_list)
{
    prepare_gles_tracer ();

    EGLImageKHR egl_img = EGL_NO_IMAGE_KHR;
    if (eglCreateImageKHR_)
        egl_img =  eglCreateImageKHR_ (dpy, ctx, target, buffer, attrib_list);

    fprintf (g_log_fp, "eglCreateImageKHR(%p, %p, %d, %p, %p); // egl_img=%p\n",
             dpy, ctx, target, buffer, attrib_list, egl_img);

    return egl_img;
}

