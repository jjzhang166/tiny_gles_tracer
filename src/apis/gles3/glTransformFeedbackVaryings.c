#include <stdio.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_bufmode_str (GLenum bufferMode)
{
    switch (bufferMode)
    {
    case GL_INTERLEAVED_ATTRIBS : return "GL_INTERLEAVED_ATTRIBS ";
    case GL_SEPARATE_ATTRIBS    : return "GL_SEPARATE_ATTRIBS ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", bufferMode);
    return s_strbuf;
}


#define glTransformFeedbackVaryings_   \
    ((void (*)(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode))  \
    GLES_ENTRY_PTR(glTransformFeedbackVaryings_Idx))


GL_APICALL void GL_APIENTRY
glTransformFeedbackVaryings (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)
{
    prepare_gles_tracer ();

    glTransformFeedbackVaryings_ (program, count, varyings, bufferMode);

    fprintf (g_log_fp, "glTransformFeedbackVaryings(%d, %d, %p, %s);\n",
             program, count, varyings, get_bufmode_str (bufferMode));
}

