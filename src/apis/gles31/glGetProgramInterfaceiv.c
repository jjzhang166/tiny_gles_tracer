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

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_ACTIVE_RESOURCES            : return "GL_ACTIVE_RESOURCES";
    case GL_MAX_NAME_LENGTH             : return "GL_MAX_NAME_LENGTH";
    case GL_MAX_NUM_ACTIVE_VARIABLES    : return "GL_MAX_NUM_ACTIVE_VARIABLES";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetProgramInterfaceiv_   \
    ((void (*)(GLuint program, GLenum programInterface, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetProgramInterfaceiv_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramInterfaceiv (GLuint program, GLenum programInterface, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetProgramInterfaceiv_ (program, programInterface, pname, params);

    fprintf (g_log_fp, "glGetProgramInterfaceiv(%d, %s, %s, %p);", 
             program, get_if_str (programInterface), get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params=%d\n", *params);
    fprintf (g_log_fp, "\n");
}
