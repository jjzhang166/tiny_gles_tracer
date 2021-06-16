#include <stdio.h>
#include "GLEStrace.h"

#define eglInitialize_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLint *major, EGLint *minor))  \
    EGL_ENTRY_PTR(eglInitialize_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglInitialize (EGLDisplay dpy, EGLint *major, EGLint *minor)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglInitialize_)
        ret = eglInitialize_ (dpy, major, minor);

    fprintf (g_log_fp, "eglInitialize(%p, %p, %p);\n", dpy, major, minor);
    if (major) fprintf (g_log_fp, "    major = %d\n", *major);
    if (minor) fprintf (g_log_fp, "    minor = %d\n", *minor);

    return ret;
}

