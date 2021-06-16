#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_query_name_str (EGLint name)
{
    switch (name)
    {
    case EGL_CLIENT_APIS                : return "EGL_CLIENT_APIS";
    case EGL_VENDOR                     : return "EGL_VENDOR";
    case EGL_VERSION                    : return "EGL_VERSION";
    case EGL_EXTENSIONS                 : return "EGL_EXTENSIONS";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}


#define eglQueryString_  \
    ((const char * (*)(EGLDisplay dpy, EGLint name))  \
    EGL_ENTRY_PTR(eglQueryString_Idx))


EGLAPI const char *EGLAPIENTRY
eglQueryString (EGLDisplay dpy, EGLint name)
{
    prepare_gles_tracer ();

    const char *str = NULL;
    if (eglQueryString_)
        str = eglQueryString_ (dpy, name);

    fprintf (g_log_fp, "eglQueryString(%p, %s);", dpy, get_query_name_str (name));
    fprintf (g_log_fp, " // %s\n", str);

    return str;
}

