#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_front_mode_str (GLenum mode)
{
    switch (mode)
    {
    case GL_CW                          : return "GL_CW";
    case GL_CCW                         : return "GL_CCW";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", mode);
    return s_strbuf;
}

#define glFrontFace_   \
    ((void (*)(GLenum mode)) \
    GLES_ENTRY_PTR(glFrontFace_Idx))


GL_APICALL void GL_APIENTRY
glFrontFace (GLenum mode)
{
    prepare_gles_tracer ();

    glFrontFace_ (mode);

    fprintf (g_log_fp, "glFrontFace(%s);\n", get_front_mode_str (mode));
}
