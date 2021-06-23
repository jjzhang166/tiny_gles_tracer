#include <stdio.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_primmove_str (GLenum bufferMode)
{
    switch (bufferMode)
    {
    case GL_POINTS      : return "GL_POINTS";
    case GL_LINES       : return "GL_LINES";
    case GL_TRIANGLES   : return "GL_TRIANGLES";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", bufferMode);
    return s_strbuf;
}


#define glBeginTransformFeedback_   \
    ((void (*)(GLenum primitiveMode))  \
    GLES_ENTRY_PTR(glBeginTransformFeedback_Idx))


GL_APICALL void GL_APIENTRY
glBeginTransformFeedback (GLenum primitiveMode)
{
    prepare_gles_tracer ();

    glBeginTransformFeedback_ (primitiveMode);

    fprintf (g_log_fp, "glBeginTransformFeedback(%s);\n", get_primmove_str (primitiveMode));
}

