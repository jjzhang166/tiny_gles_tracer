#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_binary_name_str (GLenum name)
{
    switch (name)
    {
    case GL_Z400_BINARY_AMD                 : return "GL_Z400_BINARY_AMD";
    case GL_PROGRAM_BINARY_ANGLE            : return "GL_PROGRAM_BINARY_ANGLE";
    case GL_MALI_PROGRAM_BINARY_ARM         : return "GL_MALI_PROGRAM_BINARY_ARM";
    case GL_MALI_SHADER_BINARY_ARM          : return "GL_MALI_SHADER_BINARY_ARM";
    case GL_SMAPHS30_PROGRAM_BINARY_DMP     : return "GL_SMAPHS30_PROGRAM_BINARY_DMP";
    case GL_SMAPHS_PROGRAM_BINARY_DMP       : return "GL_SMAPHS_PROGRAM_BINARY_DMP";
    case GL_DMP_PROGRAM_BINARY_DMP          : return "GL_DMP_PROGRAM_BINARY_DMP";
    case GL_SHADER_BINARY_DMP               : return "GL_SHADER_BINARY_DMP";
    case GL_GCCSO_SHADER_BINARY_FJ          : return "GL_GCCSO_SHADER_BINARY_FJ";
    case GL_SGX_PROGRAM_BINARY_IMG          : return "GL_SGX_PROGRAM_BINARY_IMG";
    case GL_SGX_BINARY_IMG                  : return "GL_SGX_BINARY_IMG";
    case GL_PROGRAM_BINARY_FORMAT_MESA      : return "GL_PROGRAM_BINARY_FORMAT_MESA";
    case GL_SHADER_BINARY_VIV               : return "GL_SHADER_BINARY_VIV";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}


#define glGetProgramBinary_         \
    ((void (*)(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary))   \
    GLES_ENTRY_PTR(glGetProgramBinary_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramBinary (GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)
{
    prepare_gles_tracer ();

    glGetProgramBinary_ (program, bufSize, length, binaryFormat, binary);

    fprintf (g_log_fp, "glGetProgramBinary(%d, %d, %p, %p, %p); // ", 
             program, bufSize, length, binaryFormat, binary);

    if (length)       fprintf (g_log_fp, "length:%d ", *length);
    if (binaryFormat) fprintf (g_log_fp, "fmt:%s ", get_binary_name_str (*binaryFormat));
    fprintf (g_log_fp, "\n");
}

