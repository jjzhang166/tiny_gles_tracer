#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_cap_str (GLenum cap)
{
    switch (cap)
    {
    case GL_BLEND                       : return "GL_BLEND";
    case GL_CULL_FACE                   : return "GL_CULL_FACE";
    case GL_DEPTH_TEST                  : return "GL_DEPTH_TEST";
    case GL_DITHER                      : return "GL_DITHER";
    case GL_SCISSOR_TEST                : return "GL_SCISSOR_TEST";
    case GL_STENCIL_TEST                : return "GL_STENCIL_TEST";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", cap);
    return s_strbuf;
}

#define glEnable_   \
    ((void (*)(GLenum cap)) \
    GLES_ENTRY_PTR(glEnable_Idx))


GL_APICALL void GL_APIENTRY
glEnable (GLenum cap)
{
    prepare_gles_tracer ();

    glEnable_ (cap);

    fprintf (g_log_fp, "glEnable(%s);\n", get_cap_str (cap));
}
