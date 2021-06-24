#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_DRAW_FRAMEBUFFER    : return "GL_DRAW_FRAMEBUFFER";
    case GL_READ_FRAMEBUFFER    : return "GL_READ_FRAMEBUFFER";
    case GL_FRAMEBUFFER         : return "GL_FRAMEBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE          : return "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE";
    case GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE             : return "GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE";
    case GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE       : return "GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE";
    case GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING       : return "GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING";
    case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME          : return "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME";
    case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL        : return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL";
    case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE: return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE ";
    case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER        : return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER  ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}

#define glFramebufferParameteri_   \
    ((void (*)(GLenum target, GLenum pname, GLint param))  \
    GLES_ENTRY_PTR(glFramebufferParameteri_Idx))


GL_APICALL void GL_APIENTRY
glFramebufferParameteri (GLenum target, GLenum pname, GLint param)
{
    prepare_gles_tracer ();

    glFramebufferParameteri_ (target, pname, param);

    fprintf (g_log_fp, "glFramebufferParameteri(%s, %s, %d);\n", 
             get_target_str (target), get_pname_str (pname), param);
}
