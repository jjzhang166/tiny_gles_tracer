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
get_textarget_str (GLenum textarget)
{
    switch (textarget)
    {
    case GL_TEXTURE_2D                  : return "GL_TEXTURE_2D";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", textarget);
    return s_strbuf;
}


#define glFramebufferTexture2D_   \
    ((void (*)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level))  \
    GLES_ENTRY_PTR(glFramebufferTexture2D_Idx))


GL_APICALL void GL_APIENTRY
glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
    prepare_gles_tracer ();

    glFramebufferTexture2D_ (target, attachment, textarget, texture, level);

    fprintf (g_log_fp, "glFramebufferTexture2D(%s, %s, %s, %d, %d);\n",
             get_target_str (target),
             get_attachment_str(attachment),
             get_textarget_str (textarget), 
             texture, level);
}

