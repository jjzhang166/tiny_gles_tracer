#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_UNIFORM_TYPE            : return "GL_UNIFORM_TYPE";
    case GL_UNIFORM_SIZE            : return "GL_UNIFORM_SIZE";
    case GL_UNIFORM_NAME_LENGTH     : return "GL_UNIFORM_NAME_LENGTH";
    case GL_UNIFORM_BLOCK_INDEX     : return "GL_UNIFORM_BLOCK_INDEX";
    case GL_UNIFORM_OFFSET          : return "GL_UNIFORM_OFFSET";
    case GL_UNIFORM_ARRAY_STRIDE    : return "GL_UNIFORM_ARRAY_STRIDE";
    case GL_UNIFORM_MATRIX_STRIDE   : return "GL_UNIFORM_MATRIX_STRIDE";
    case GL_UNIFORM_IS_ROW_MAJOR    : return "GL_UNIFORM_IS_ROW_MAJOR";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetActiveUniformsiv_   \
    ((void (*)(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetActiveUniformsiv_Idx))


GL_APICALL void GL_APIENTRY
glGetActiveUniformsiv (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetActiveUniformsiv_ (program, uniformCount, uniformIndices, pname, params);

    fprintf (g_log_fp, "glGetActiveUniformsiv(%d, %d, %p, %s, %p); // ",
             program, uniformCount, uniformIndices, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, "params=%d", *params);
    
    fprintf (g_log_fp, "\n");
}

