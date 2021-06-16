#include <stdio.h>
#include "GLEStrace.h"

#define eglCreateImage_  \
    ((EGLImage (*)(EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLAttrib *attrib_list))  \
    EGL_ENTRY_PTR(eglCreateImage_Idx))


EGLAPI EGLImage EGLAPIENTRY
eglCreateImage (EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLAttrib *attrib_list)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglCreateImage(%p, %p, %d, %p, %p);\n", dpy, ctx, target, buffer, attrib_list);

    if (eglCreateImage_)
        return eglCreateImage_ (dpy, ctx, target, buffer, attrib_list);
    else
        return EGL_NO_IMAGE;
}

