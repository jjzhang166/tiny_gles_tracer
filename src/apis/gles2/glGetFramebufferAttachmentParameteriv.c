#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum name)
{
    switch (name)
    {
    case GL_DRAW_FRAMEBUFFER                : return "GL_DRAW_FRAMEBUFFER";
    case GL_READ_FRAMEBUFFER                : return "GL_READ_FRAMEBUFFER ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

static char *
get_attachment_str (GLenum attachment)
{
    switch (attachment)
    {
    case GL_COLOR_ATTACHMENT0               : return "GL_COLOR_ATTACHMENT0";
    case GL_COLOR_ATTACHMENT1               : return "GL_COLOR_ATTACHMENT1";
    case GL_COLOR_ATTACHMENT2               : return "GL_COLOR_ATTACHMENT2";
    case GL_COLOR_ATTACHMENT3               : return "GL_COLOR_ATTACHMENT3";
    case GL_COLOR_ATTACHMENT4               : return "GL_COLOR_ATTACHMENT4";
    case GL_COLOR_ATTACHMENT5               : return "GL_COLOR_ATTACHMENT5";
    case GL_COLOR_ATTACHMENT6               : return "GL_COLOR_ATTACHMENT6";
    case GL_COLOR_ATTACHMENT7               : return "GL_COLOR_ATTACHMENT7";
    case GL_DEPTH_ATTACHMENT                : return "GL_DEPTH_ATTACHMENT ";
    case GL_STENCIL_ATTACHMENT              : return "GL_STENCIL_ATTACHMENT ";
    case GL_DEPTH_STENCIL_ATTACHMENT        : return "GL_DEPTH_STENCIL_ATTACHMENT ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attachment);
    return s_strbuf;
}

static char *
get_pname_str (GLenum name)
{
    switch (name)
    {
    case GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE         : return "GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE";
    case GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE       : return "GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE";
    case GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE        : return "GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE";
    case GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE       : return "GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE";
    case GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE       : return "GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE";
    case GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE     : return "GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE";
    case GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE   : return "GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE";
    case GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING   : return "GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING";
    case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME      : return "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME";
    case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL    : return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL";
    case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE  : return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE ";
    case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER    : return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER  ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetFramebufferAttachmentParameteriv_   \
    ((void (*)(GLenum target, GLenum attachment, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetFramebufferAttachmentParameteriv_Idx))


GL_APICALL void GL_APIENTRY
glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetFramebufferAttachmentParameteriv_ (target, attachment, pname, params);

    fprintf (g_log_fp, "glGetFramebufferAttachmentParameteriv(%-30s, %s, %s, %p);", 
             get_target_str (target),
             get_attachment_str (attachment),
             get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

