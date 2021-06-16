#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_cull_mode_str (GLenum mode)
{
    switch (mode)
    {
    case GL_FRONT                       : return "GL_FRONT";
    case GL_BACK                        : return "GL_BACK";
    case GL_FRONT_AND_BACK              : return "GL_FRONT_AND_BACK ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", mode);
    return s_strbuf;
}

#define glCullFace_   \
    ((void (*)(GLenum mode)) \
    GLES_ENTRY_PTR(glCullFace_Idx))


GL_APICALL void GL_APIENTRY
glCullFace (GLenum mode)
{
    prepare_gles_tracer ();

    glCullFace_ (mode);

    fprintf (g_log_fp, "glCullFace(%s);\n", get_cull_mode_str (mode));
}
