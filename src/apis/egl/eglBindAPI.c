#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_api_name_str (EGLenum api)
{
    switch (api)
    {
    case EGL_OPENGL_API                 : return "EGL_OPENGL_API";
    case EGL_OPENGL_ES_API              : return "EGL_OPENGL_ES_API";
    case EGL_OPENVG_API                 : return "EGL_OPENVG_API";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", api);
    return s_strbuf;
}


#define eglBindAPI_  \
    ((EGLBoolean (*)(EGLenum api))  \
    EGL_ENTRY_PTR(eglBindAPI_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglBindAPI (EGLenum api)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglBindAPI(%s);\n", get_api_name_str (api));

    if (eglBindAPI_)
        return eglBindAPI_ (api);
    else
        return EGL_FALSE;
}

