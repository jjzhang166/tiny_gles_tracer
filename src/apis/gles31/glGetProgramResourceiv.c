#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_if_str (GLenum programInterface)
{
    switch (programInterface)
    {
    case GL_UNIFORM                     : return "GL_UNIFORM";
    case GL_UNIFORM_BLOCK               : return "GL_UNIFORM_BLOCK";
    case GL_ATOMIC_COUNTER_BUFFER       : return "GL_ATOMIC_COUNTER_BUFFER";
    case GL_PROGRAM_INPUT               : return "GL_PROGRAM_INPUT";
    case GL_PROGRAM_OUTPUT              : return "GL_PROGRAM_OUTPUT";
    case GL_TRANSFORM_FEEDBACK_VARYING  : return "GL_TRANSFORM_FEEDBACK_VARYING";
    case GL_BUFFER_VARIABLE             : return "GL_BUFFER_VARIABLE";
    case GL_SHADER_STORAGE_BLOCK        : return "GL_SHADER_STORAGE_BLOCK";
    case GL_TRANSFORM_FEEDBACK_BUFFER   : return "GL_TRANSFORM_FEEDBACK_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", programInterface);
    return s_strbuf;
}


#define glGetProgramResourceiv_   \
    ((GLuint (*)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params))  \
    GLES_ENTRY_PTR(glGetProgramResourceiv_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramResourceiv (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props,
                        GLsizei bufSize, GLsizei *length, GLint *params)
{
    prepare_gles_tracer ();

    glGetProgramResourceiv_ (program, programInterface, index, propCount, props, bufSize, length, params);

    fprintf (g_log_fp, "glGetProgramResourceiv(%d, %s, %d, %d, %p, %d, %p, %p); // ",
             program, get_if_str (programInterface), index, propCount, props, bufSize, length, params);

    if (length) fprintf (g_log_fp, "length=%d, ", *length);
    if (params) fprintf (g_log_fp, "params=%d, ", *params);
    fprintf (g_log_fp, "\n");
}
