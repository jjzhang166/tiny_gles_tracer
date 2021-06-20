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


#define eglQueryAPI_  \
    ((EGLenum (*)(void))  \
    EGL_ENTRY_PTR(eglQueryAPI_Idx))


EGLAPI EGLenum EGLAPIENTRY
eglQueryAPI (void)
{
    prepare_gles_tracer ();

    EGLenum ret = EGL_NONE;
    if (eglQueryAPI_)
        ret = eglQueryAPI_ ();

    fprintf (g_log_fp, "eglQueryAPI(); // ret=%s\n", get_api_name_str (ret));

    return ret;
}

