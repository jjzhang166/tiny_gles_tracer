#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_attr_name_str (EGLint attribute)
{
    switch (attribute)
    {
    case EGL_MIPMAP_LEVEL        : return "EGL_MIPMAP_LEVEL";
    case EGL_MULTISAMPLE_RESOLVE : return "EGL_MULTISAMPLE_RESOLVE";
    case EGL_SWAP_BEHAVIOR       : return "EGL_SWAP_BEHAVIOR";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attribute);
    return s_strbuf;
}


#define eglSurfaceAttrib_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value))  \
    EGL_ENTRY_PTR(eglSurfaceAttrib_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglSurfaceAttrib (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglSurfaceAttrib(%p, %p, %s, %d);\n",
             dpy, surface, get_attr_name_str (attribute), value);

    if (eglSurfaceAttrib_)
        return eglSurfaceAttrib_ (dpy, surface, attribute, value);
    else
        return EGL_FALSE;
}

