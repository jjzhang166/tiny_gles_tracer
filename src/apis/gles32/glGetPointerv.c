#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_DEBUG_CALLBACK_FUNCTION     : return "GL_DEBUG_CALLBACK_FUNCTION ";
    case GL_DEBUG_CALLBACK_USER_PARAM   : return "GL_DEBUG_CALLBACK_USER_PARAM";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}

#define glGetPointerv_   \
    ((void (*)(GLenum pname, void **params))  \
    GLES_ENTRY_PTR(glGetPointerv_Idx))


GL_APICALL void GL_APIENTRY
glGetPointerv (GLenum pname, void **params)
{
    prepare_gles_tracer ();

    glGetPointerv_ (pname, params);

    fprintf (g_log_fp, "glGetPointerv(%s, %p);\n", get_pname_str (pname), params);
}

