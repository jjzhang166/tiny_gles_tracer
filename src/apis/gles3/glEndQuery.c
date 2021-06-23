#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_ANY_SAMPLES_PASSED                   : return "GL_ANY_SAMPLES_PASSED";
    case GL_ANY_SAMPLES_PASSED_CONSERVATIVE      : return "GL_ANY_SAMPLES_PASSED_CONSERVATIVE";
    case GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN: return "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

#define glEndQuery_   \
    ((void (*)(GLenum target))  \
    GLES_ENTRY_PTR(glEndQuery_Idx))


GL_APICALL void GL_APIENTRY
glEndQuery (GLenum target)
{
    prepare_gles_tracer ();

    glEndQuery_ (target);

    fprintf (g_log_fp, "glEndQuery(%s);\n", get_target_str (target));
}

