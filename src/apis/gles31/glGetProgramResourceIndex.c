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


#define glGetProgramResourceIndex_   \
    ((GLuint (*)(GLuint program, GLenum programInterface, const GLchar *name))  \
    GLES_ENTRY_PTR(glGetProgramResourceIndex_Idx))


GL_APICALL GLuint GL_APIENTRY
glGetProgramResourceIndex (GLuint program, GLenum programInterface, const GLchar *name)
{
    prepare_gles_tracer ();

    GLuint ret = glGetProgramResourceIndex_ (program, programInterface, name);

    fprintf (g_log_fp, "glGetProgramResourceIndex(%d, %s, %s); // ret=%d\n",
             program, get_if_str (programInterface), name, ret);

    return ret;
}
