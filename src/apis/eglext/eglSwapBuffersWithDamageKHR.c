#include <stdio.h>
#include "GLEStrace.h"


#define eglSwapBuffersWithDamageKHR_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects))  \
    EGL_ENTRY_PTR(eglSwapBuffersWithDamageKHR_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglSwapBuffersWithDamageKHR (EGLDisplay dpy, EGLSurface surface, EGLint *rects, EGLint n_rects)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglSwapBuffersWithDamageKHR_)
        ret = eglSwapBuffersWithDamageKHR_ (dpy, surface, rects, n_rects);

    fprintf (g_log_fp, "eglSwapBuffersWithDamageKHR(%p, %p, %p, %d); // ret=%d",
             dpy, surface, rects, n_rects, ret);
    if (rects)
    {
        for (int i = 0; i < n_rects; i ++)
        {
            fprintf (g_log_fp, "(%d, %d, %d, %d)", 
                rects[4*i+0], rects[4*i+1], rects[4*i+2], rects[4*i+3]);
        }
    }
    fprintf (g_log_fp, "\n");

    return ret;
}

