#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_shader_type_str (GLenum type)
{
    switch (type)
    {
    case GL_VERTEX_SHADER               : return "GL_VERTEX_SHADER";
    case GL_FRAGMENT_SHADER             : return "GL_FRAGMENT_SHADER";
    case GL_COMPUTE_SHADER              : return "GL_COMPUTE_SHADER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}

#define glCreateShaderProgramv_   \
    ((GLuint (*)(GLenum type, GLsizei count, const GLchar *const*strings)) \
    GLES_ENTRY_PTR(glCreateShaderProgramv_Idx))


GL_APICALL GLuint GL_APIENTRY
glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar *const*strings)
{
    prepare_gles_tracer ();

    GLuint ret = glCreateShaderProgramv_ (type, count, strings);

    fprintf (g_log_fp, "glCreateShaderProgramv(%s, %d, %p); // ret=%d\n",
             get_shader_type_str (type), count, strings, ret);

    for (int i = 0; i < count; i ++)
    {
        fprintf (g_log_fp, "-----------------------------\n");
        fprintf (g_log_fp, "%s\n", strings[i]);
        fprintf (g_log_fp, "-----------------------------\n\n");
    }

    return ret;
}
