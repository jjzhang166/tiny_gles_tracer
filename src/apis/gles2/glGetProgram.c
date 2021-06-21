#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_ACTIVE_ATOMIC_COUNTER_BUFFERS   : return "GL_ACTIVE_ATOMIC_COUNTER_BUFFERS";
    case GL_ACTIVE_ATTRIBUTES               : return "GL_ACTIVE_ATTRIBUTES";
    case GL_ACTIVE_ATTRIBUTE_MAX_LENGTH     : return "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH";
    case GL_ACTIVE_UNIFORMS                 : return "GL_ACTIVE_UNIFORMS";
    case GL_ACTIVE_UNIFORM_BLOCKS           : return "GL_ACTIVE_UNIFORM_BLOCKS";
    case GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH: return "GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH";
    case GL_ACTIVE_UNIFORM_MAX_LENGTH       : return "GL_ACTIVE_UNIFORM_MAX_LENGTH";
    case GL_ATTACHED_SHADERS                : return "GL_ATTACHED_SHADERS";
    case GL_COMPUTE_WORK_GROUP_SIZE         : return "GL_COMPUTE_WORK_GROUP_SIZE";
    case GL_DELETE_STATUS                   : return "GL_DELETE_STATUS";
    case GL_INFO_LOG_LENGTH                 : return "GL_INFO_LOG_LENGTH";
    case GL_LINK_STATUS                     : return "GL_LINK_STATUS";
    case GL_PROGRAM_BINARY_RETRIEVABLE_HINT : return "GL_PROGRAM_BINARY_RETRIEVABLE_HINT";
    case GL_PROGRAM_SEPARABLE               : return "GL_PROGRAM_SEPARABLE";
    case GL_TRANSFORM_FEEDBACK_BUFFER_MODE  : return "GL_TRANSFORM_FEEDBACK_BUFFER_MODE";
    case GL_TRANSFORM_FEEDBACK_VARYINGS     : return "GL_TRANSFORM_FEEDBACK_VARYINGS";
    case GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH : return "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH";
    case GL_VALIDATE_STATUS                 : return "GL_VALIDATE_STATUS ";
    case GL_PROGRAM_BINARY_LENGTH           : return "GL_PROGRAM_BINARY_LENGTH";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}

#define glGetProgramiv_   \
    ((void (*)(GLuint program, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetProgramiv_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramiv (GLuint program, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetProgramiv_ (program, pname, params);

    fprintf (g_log_fp, "glGetProgramiv(%d, %s, %p);", 
                        program, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

