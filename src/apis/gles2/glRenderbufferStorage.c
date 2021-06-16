#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_RENDERBUFFER                : return "GL_RENDERBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_internalformat_str (GLenum internalformat)
{
    switch (internalformat)
    {
    case GL_RGB8                        : return "GL_RGB8";
    case GL_RGBA8                       : return "GL_RGBA8";
    case GL_RGB565                      : return "GL_RGB565";
    case GL_DEPTH_COMPONENT16           : return "GL_DEPTH_COMPONENT16";
    case GL_DEPTH_COMPONENT24           : return "GL_DEPTH_COMPONENT24";
    case GL_DEPTH24_STENCIL8            : return "GL_DEPTH24_STENCIL8";
    case GL_STENCIL_INDEX8              : return "GL_STENCIL_INDEX8";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", internalformat);
    return s_strbuf;
}


#define glRenderbufferStorage_   \
    ((void (*)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)) \
    GLES_ENTRY_PTR(glRenderbufferStorage_Idx))


GL_APICALL void GL_APIENTRY
glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
    prepare_gles_tracer ();

    glRenderbufferStorage_ (target, internalformat, width, height);

    fprintf (g_log_fp, "glRenderbufferStorage(%s, %s, %d, %d);\n",
             get_target_str (target),
             get_internalformat_str (internalformat), width, height);
}
