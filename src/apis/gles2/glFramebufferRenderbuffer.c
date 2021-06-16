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

static char *
get_rbuftgt_str (GLenum renderbuffertarget)
{
    switch (renderbuffertarget)
    {
    case GL_RENDERBUFFER                : return "GL_RENDERBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", renderbuffertarget);
    return s_strbuf;
}


#define glFramebufferRenderbuffer_   \
    ((void (*)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer))  \
    GLES_ENTRY_PTR(glFramebufferRenderbuffer_Idx))


GL_APICALL void GL_APIENTRY
glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
    prepare_gles_tracer ();

    glFramebufferRenderbuffer_ (target, attachment, renderbuffertarget, renderbuffer);

    fprintf (g_log_fp, "glFramebufferRenderbuffer(%s, %s, %s, %d);\n",
             get_target_str (target),
             get_attachment_str(attachment),
             get_rbuftgt_str (renderbuffertarget), renderbuffer);
}

