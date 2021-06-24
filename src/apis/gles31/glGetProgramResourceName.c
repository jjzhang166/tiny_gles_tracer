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


#define glGetProgramResourceName_   \
    ((GLuint (*)(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name))  \
    GLES_ENTRY_PTR(glGetProgramResourceName_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramResourceName (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name)
{
    prepare_gles_tracer ();

    glGetProgramResourceName_ (program, programInterface, index, bufSize, length, name);

    fprintf (g_log_fp, "glGetProgramResourceName(%d, %s, %d, %d, %p, %p); // ",
             program, get_if_str (programInterface), index, bufSize, length, name);

    if (length) fprintf (g_log_fp, "length=%d, ", *length);
    if (name)   fprintf (g_log_fp, "name=%s, ", name);
    fprintf (g_log_fp, "\n");
}
