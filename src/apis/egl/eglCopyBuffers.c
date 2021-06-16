#include <stdio.h>
#include "GLEStrace.h"


#define eglCopyBuffers_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target))  \
    EGL_ENTRY_PTR(eglCopyBuffers_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglCopyBuffers (EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglCopyBuffers(%p, %p, %ld);\n", dpy, surface, target);

    if (eglCopyBuffers_)
        return eglCopyBuffers_ (dpy, surface, target);
    else
        return EGL_FALSE;
}

