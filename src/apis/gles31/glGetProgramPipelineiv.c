#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_ACTIVE_PROGRAM          : return "GL_ACTIVE_PROGRAM";
    case GL_VERTEX_SHADER           : return "GL_VERTEX_SHADER";
    case GL_FRAGMENT_SHADER         : return "GL_FRAGMENT_SHADER";
    case GL_TESS_CONTROL_SHADER     : return "GL_TESS_CONTROL_SHADER";
    case GL_TESS_EVALUATION_SHADER  : return "GL_TESS_EVALUATION_SHADER";
    case GL_GEOMETRY_SHADER         : return "GL_GEOMETRY_SHADER";
    case GL_COMPUTE_SHADER          : return "GL_COMPUTE_SHADER";
    case GL_INFO_LOG_LENGTH         : return "GL_INFO_LOG_LENGTH";
    case GL_VALIDATE_STATUS         : return "GL_VALIDATE_STATUS";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetProgramPipelineiv_   \
    ((void (*)(GLuint pipeline, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetProgramPipelineiv_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramPipelineiv (GLuint pipeline, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetProgramPipelineiv_ (pipeline, pname, params);

    fprintf (g_log_fp, "glGetProgramPipelineiv(%d, %s, %p);", 
             pipeline, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params=%d\n", *params);
    fprintf (g_log_fp, "\n");
}
