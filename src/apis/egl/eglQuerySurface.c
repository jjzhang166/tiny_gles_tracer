#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_attrib_name_str (EGLint attribute)
{
    switch (attribute)
    {
    case EGL_CONFIG_ID                  : return "EGL_CONFIG_ID";
    case EGL_HEIGHT                     : return "EGL_HEIGHT";
    case EGL_WIDTH                      : return "EGL_WIDTH";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attribute);
    return s_strbuf;
}


#define eglQuerySurface_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value))  \
    EGL_ENTRY_PTR(eglQuerySurface_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglQuerySurface (EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglQuerySurface_)
        ret = eglQuerySurface_ (dpy, surface, attribute, value);

    fprintf (g_log_fp, "eglQuerySurface(%p, %p, %s, %p);\n", 
                dpy, surface, get_attrib_name_str (attribute), value);

    return ret;
}

