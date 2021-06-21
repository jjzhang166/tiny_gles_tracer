#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_UNIFORM_BLOCK_BINDING                    : return "GL_UNIFORM_BLOCK_BINDING";
    case GL_UNIFORM_BLOCK_DATA_SIZE                  : return "GL_UNIFORM_BLOCK_DATA_SIZE";
    case GL_UNIFORM_BLOCK_NAME_LENGTH                : return "GL_UNIFORM_BLOCK_NAME_LENGTH";
    case GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS            : return "GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS";
    case GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES     : return "GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES";
    case GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER: return "GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetActiveUniformBlockiv_   \
    ((void (*)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetActiveUniformBlockiv_Idx))


GL_APICALL void GL_APIENTRY
glGetActiveUniformBlockiv (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetActiveUniformBlockiv_ (program, uniformBlockIndex, pname, params);

    fprintf (g_log_fp, "glGetActiveUniformBlockiv(%d, %d, %s, %p); // ", 
             program, uniformBlockIndex, get_pname_str (pname), params);

    if (params) fprintf (g_log_fp, "params=%d, ", *params);

    fprintf (g_log_fp, "\n"); 
}

