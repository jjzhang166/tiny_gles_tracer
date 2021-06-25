#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_FRAMEBUFFER                 : return "GL_FRAMEBUFFER";
#if defined (GL_DRAW_FRAMEBUFFER)
    case GL_DRAW_FRAMEBUFFER            : return "GL_DRAW_FRAMEBUFFER";
    case GL_READ_FRAMEBUFFER            : return "GL_READ_FRAMEBUFFER";
#endif
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
#if defined (GL_DEPTH_STENCIL_ATTACHMENT)
    case GL_DEPTH_STENCIL_ATTACHMENT    : return "GL_DEPTH_STENCIL_ATTACHMENT ";
#endif
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attachment);
    return s_strbuf;
}


#define glFramebufferTexture_   \
    ((void (*)(GLenum target, GLenum attachment, GLuint texture, GLint level))  \
    GLES_ENTRY_PTR(glFramebufferTexture_Idx))


GL_APICALL void GL_APIENTRY
glFramebufferTexture (GLenum target, GLenum attachment, GLuint texture, GLint level)
{
    prepare_gles_tracer ();

    glFramebufferTexture_ (target, attachment, texture, level);

    fprintf (g_log_fp, "glFramebufferTexture2D(%s, %s, %d, %d);\n",
             get_target_str (target),
             get_attachment_str(attachment),
             texture, level);
}

