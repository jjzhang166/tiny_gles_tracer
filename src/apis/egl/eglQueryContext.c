#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_attrib_name_str (EGLint attribute)
{
    switch (attribute)
    {
    case EGL_CONFIG_ID                  : return "EGL_CONFIG_ID";
    case EGL_CONTEXT_CLIENT_TYPE        : return "EGL_CONTEXT_CLIENT_TYPE";
    case EGL_CONTEXT_CLIENT_VERSION     : return "EGL_CONTEXT_CLIENT_VERSION";
    case EGL_RENDER_BUFFER              : return "EGL_RENDER_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attribute);
    return s_strbuf;
}


#define eglQueryContext_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value))  \
    EGL_ENTRY_PTR(eglQueryContext_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglQueryContext (EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint *value)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglQueryContext_)
        ret = eglQueryContext_ (dpy, ctx, attribute, value);

    fprintf (g_log_fp, "eglQueryContext(%p, %p, %s, %p);\n", 
                dpy, ctx, get_attrib_name_str (attribute), value);

    return ret;
}

