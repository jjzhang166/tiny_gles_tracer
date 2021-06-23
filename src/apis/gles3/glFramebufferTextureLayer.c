#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_FRAMEBUFFER                 : return "GL_FRAMEBUFFER";
    case GL_DRAW_FRAMEBUFFER            : return "GL_DRAW_FRAMEBUFFER";
    case GL_READ_FRAMEBUFFER            : return "GL_READ_FRAMEBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_attachment_str (GLenum attachment)
{
    switch (attachment)
    {
    case GL_COLOR_ATTACHMENT0           : return "GL_COLOR_ATTACHMENT0";
    case GL_DEPTH_ATTACHMENT            : return "GL_DEPTH_ATTACHMENT";
    case GL_STENCIL_ATTACHMENT          : return "GL_STENCIL_ATTACHMENT ";
    case GL_DEPTH_STENCIL_ATTACHMENT    : return "GL_DEPTH_STENCIL_ATTACHMENT ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attachment);
    return s_strbuf;
}


#define glFramebufferTextureLayer_   \
    ((void (*)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer))  \
    GLES_ENTRY_PTR(glFramebufferTextureLayer_Idx))


GL_APICALL void GL_APIENTRY
glFramebufferTextureLayer (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
{
    prepare_gles_tracer ();

    glFramebufferTextureLayer_ (target, attachment, texture, level, layer);

    fprintf (g_log_fp, "glFramebufferTextureLayer(%s, %s, %d, %d, %d);\n",
             get_target_str (target),
             get_attachment_str(attachment), texture, level, layer);
}

