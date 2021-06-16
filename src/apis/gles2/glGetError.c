#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_error_str (GLenum err)
{
    switch (err)
    {
    case GL_NO_ERROR            : return "GL_NO_ERROR";          break;
    case GL_INVALID_ENUM        : return "GL_INVALID_ENUM";      break;
    case GL_INVALID_VALUE       : return "GL_INVALID_VALUE";     break;
    case GL_INVALID_OPERATION   : return "GL_INVALID_OPERATION"; break;
    case GL_STACK_OVERFLOW      : return "GL_STACK_OVERFLOW";    break;
    case GL_STACK_UNDERFLOW     : return "GL_STACK_UNDERFLOW";   break;
    case GL_OUT_OF_MEMORY       : return "GL_OUT_OF_MEMORY";     break;
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", err);
    return s_strbuf;
}

#define glGetError_   \
    ((GLenum (*)(void))  \
    GLES_ENTRY_PTR(glGetError_Idx))


GL_APICALL GLenum GL_APIENTRY
glGetError (void)
{
    prepare_gles_tracer ();

    GLenum err = glGetError_ ();

    fprintf (g_log_fp, "glGetError();");
    fprintf (g_log_fp, " // %s\n", get_error_str (err));

    return err;
}

