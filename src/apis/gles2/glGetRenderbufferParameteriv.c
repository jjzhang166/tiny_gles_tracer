#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum name)
{
    switch (name)
    {
    case GL_RENDERBUFFER                    : return "GL_RENDERBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

static char *
get_pname_str (GLenum name)
{
    switch (name)
    {
    case GL_RENDERBUFFER_WIDTH                      : return "GL_RENDERBUFFER_WIDTH";
    case GL_RENDERBUFFER_HEIGHT                     : return "GL_RENDERBUFFER_HEIGHT";
    case GL_RENDERBUFFER_INTERNAL_FORMAT            : return "GL_RENDERBUFFER_INTERNAL_FORMAT";
    case GL_RENDERBUFFER_RED_SIZE                   : return "GL_RENDERBUFFER_RED_SIZE";
    case GL_RENDERBUFFER_GREEN_SIZE                 : return "GL_RENDERBUFFER_GREEN_SIZE";
    case GL_RENDERBUFFER_BLUE_SIZE                  : return "GL_RENDERBUFFER_BLUE_SIZE";
    case GL_RENDERBUFFER_ALPHA_SIZE                 : return "GL_RENDERBUFFER_ALPHA_SIZE";
    case GL_RENDERBUFFER_DEPTH_SIZE                 : return "GL_RENDERBUFFER_DEPTH_SIZE";
    case GL_RENDERBUFFER_STENCIL_SIZE               : return "GL_RENDERBUFFER_STENCIL_SIZE";
    case GL_RENDERBUFFER_SAMPLES                    : return "GL_RENDERBUFFER_SAMPLES";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetRenderbufferParameteriv_   \
    ((void (*)(GLenum target, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetRenderbufferParameteriv_Idx))


GL_APICALL void GL_APIENTRY
glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetRenderbufferParameteriv_ (target, pname, params);

    fprintf (g_log_fp, "glGetRenderbufferParameteriv(%s, %s, %p);", 
             get_target_str (target),
             get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

