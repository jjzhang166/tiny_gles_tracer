#include <stdio.h>
#include "GLEStrace.h"


#define eglReleaseTexImage_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint buffer))  \
    EGL_ENTRY_PTR(eglReleaseTexImage_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglReleaseTexImage (EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglReleaseTexImage(%p, %p, %d);\n", dpy, surface, buffer);

    if (eglReleaseTexImage_)
        return eglReleaseTexImage_ (dpy, surface, buffer);
    else
        return EGL_FALSE;
}

