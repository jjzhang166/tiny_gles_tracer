#include <stdio.h>
#include "GLEStrace.h"


#define eglBindTexImage_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint buffer))  \
    EGL_ENTRY_PTR(eglBindTexImage_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglBindTexImage (EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglBindTexImage(%p, %p, %d);\n", dpy, surface, buffer);

    if (eglBindTexImage_)
        return eglBindTexImage_ (dpy, surface, buffer);
    else
        return EGL_FALSE;
}

