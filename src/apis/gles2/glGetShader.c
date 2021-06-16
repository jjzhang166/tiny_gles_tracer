#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_SHADER_TYPE                     : return "GL_SHADER_TYPE";
    case GL_DELETE_STATUS                   : return "GL_DELETE_STATUS";
    case GL_COMPILE_STATUS                  : return "GL_COMPILE_STATUS";
    case GL_INFO_LOG_LENGTH                 : return "GL_INFO_LOG_LENGTH";
    case GL_SHADER_SOURCE_LENGTH            : return "GL_SHADER_SOURCE_LENGTH";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}

#define glGetShaderiv_   \
    ((void (*)(GLuint shader, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetShaderiv_Idx))


GL_APICALL void GL_APIENTRY
glGetShaderiv (GLuint shader, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetShaderiv_ (shader, pname, params);

    fprintf (g_log_fp, "glGetShaderiv(%d, %s, %p);", 
                        shader, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

