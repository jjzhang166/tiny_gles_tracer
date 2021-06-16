#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_func_str (GLenum func)
{
    switch (func)
    {
    case GL_NEVER                       : return "GL_NEVER";
    case GL_LESS                        : return "GL_LESS";
    case GL_EQUAL                       : return "GL_EQUAL";
    case GL_LEQUAL                      : return "GL_LEQUAL";
    case GL_GREATER                     : return "GL_GREATER";
    case GL_NOTEQUAL                    : return "GL_NOTEQUAL";
    case GL_GEQUAL                      : return "GL_GEQUAL";
    case GL_ALWAYS                      : return "GL_ALWAYS";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", func);
    return s_strbuf;
}

#define glDepthFunc_   \
    ((void (*)(GLenum func)) \
    GLES_ENTRY_PTR(glDepthFunc_Idx))


GL_APICALL void GL_APIENTRY
glDepthFunc (GLenum func)
{
    prepare_gles_tracer ();

    glDepthFunc_ (func);

    fprintf (g_log_fp, "glDepthFunc(%s);\n", get_func_str (func));
}
