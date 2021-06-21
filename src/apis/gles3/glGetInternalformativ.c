#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_RENDERBUFFER                : return "GL_RENDERBUFFER";
    case GL_TEXTURE_2D_MULTISAMPLE      : return "GL_TEXTURE_2D_MULTISAMPLE ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_format_str (GLenum internalformat)
{
    switch (internalformat)
    {
    case GL_RGBA8                       : return "GL_RGBA8";
    case GL_RGB8                        : return "GL_RGB8";
    case GL_RGB565                      : return "GL_RGB565";
    case GL_RGBA4                       : return "GL_RGBA4";
    case GL_R8                          : return "GL_R8";
    case GL_RG8                         : return "GL_RG8";
    case GL_RGB10_A2                    : return "GL_RGB10_A2";
    case GL_SRGB8_ALPHA8                : return "GL_SRGB8_ALPHA8";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", internalformat);
    return s_strbuf;
}

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_NUM_SAMPLE_COUNTS           : return "GL_NUM_SAMPLE_COUNTS";
    case GL_SAMPLES                     : return "GL_SAMPLES";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetInternalformativ_   \
    ((void (*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params))  \
    GLES_ENTRY_PTR(glGetInternalformativ_Idx))


GL_APICALL void GL_APIENTRY
glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
{
    prepare_gles_tracer ();

    glGetInternalformativ_ (target, internalformat, pname, bufSize, params);

    fprintf (g_log_fp, "glGetInternalformativ(%s, %-16s, %s, %d, %p);",
             get_target_str (target), get_format_str (internalformat),
             get_pname_str (pname), bufSize, params);
    if (params) fprintf (g_log_fp, " // data = %d\n", *params);
}

