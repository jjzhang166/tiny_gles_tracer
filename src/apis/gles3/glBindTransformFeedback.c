#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TRANSFORM_FEEDBACK : return "GL_TRANSFORM_FEEDBACK";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

#define glBindTransformFeedback_   \
    ((void (*)(GLenum target, GLuint id))  \
    GLES_ENTRY_PTR(glBindTransformFeedback_Idx))


GL_APICALL void GL_APIENTRY
glBindTransformFeedback (GLenum target, GLuint id)
{
    prepare_gles_tracer ();

    glBindTransformFeedback_ (target, id);

    fprintf (g_log_fp, "glBindTransformFeedback(%s, %d);\n",
             get_target_str (target), id);
}

