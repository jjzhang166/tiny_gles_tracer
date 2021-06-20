#include <stdio.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_src_str (GLenum src)
{
    switch (src)
    {
    case GL_BACK                        : return "GL_BACK";
    case GL_NONE                        : return "GL_NONE";
    case GL_COLOR_ATTACHMENT0           : return "GL_COLOR_ATTACHMENT0";
    case GL_COLOR_ATTACHMENT1           : return "GL_COLOR_ATTACHMENT1";
    case GL_COLOR_ATTACHMENT2           : return "GL_COLOR_ATTACHMENT2";
    case GL_COLOR_ATTACHMENT3           : return "GL_COLOR_ATTACHMENT3";
    case GL_COLOR_ATTACHMENT4           : return "GL_COLOR_ATTACHMENT4";
    case GL_COLOR_ATTACHMENT5           : return "GL_COLOR_ATTACHMENT5";
    case GL_COLOR_ATTACHMENT6           : return "GL_COLOR_ATTACHMENT6";
    case GL_COLOR_ATTACHMENT7           : return "GL_COLOR_ATTACHMENT7";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", src);
    return s_strbuf;
}

#define glReadBuffer_   \
    ((void (*)(GLenum src))  \
    GLES_ENTRY_PTR(glReadBuffer_Idx))


GL_APICALL void GL_APIENTRY
glReadBuffer (GLenum src)
{
    prepare_gles_tracer ();

    glReadBuffer_ (src);

    fprintf (g_log_fp, "glReadBuffer(%s);\n", get_src_str (src));
}

