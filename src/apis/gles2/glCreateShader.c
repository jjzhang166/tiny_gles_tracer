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
    case GL_GEOMETRY_SHADER             : return "GL_GEOMETRY_SHADER";
    case GL_TESS_CONTROL_SHADER         : return "GL_TESS_CONTROL_SHADER";
    case GL_TESS_EVALUATION_SHADER      : return "GL_TESS_EVALUATION_SHADER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}

#define glCreateShader_   \
    ((GLuint (*)(GLenum type)) \
    GLES_ENTRY_PTR(glCreateShader_Idx))


GL_APICALL GLuint GL_APIENTRY
glCreateShader (GLenum type)
{
    prepare_gles_tracer ();

    GLuint ret = glCreateShader_ (type);

    fprintf (g_log_fp, "glCreateShader(%s); // ret=%d\n",
             get_shader_type_str (type), ret);

    return ret;
}
