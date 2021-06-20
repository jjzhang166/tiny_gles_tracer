#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_BUFFER              : return "GL_TEXTURE_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_tex_format_str (GLint format)
{
    switch (format)
    {
    case GL_ALPHA                       : return "GL_ALPHA";
    case GL_RGB                         : return "GL_RGB";
    case GL_RGBA                        : return "GL_RGBA";
    case GL_LUMINANCE                   : return "GL_LUMINANCE";
    case GL_LUMINANCE_ALPHA             : return "GL_LUMINANCE_ALPHA";
    case GL_BGRA_EXT                    : return "GL_BGRA_EXT";
    case GL_RED                         : return "GL_RED";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", format);
    return s_strbuf;
}


#define glTexBuffer_   \
    ((void (*)(GLenum target, GLenum internalformat, GLuint buffer))  \
    GLES_ENTRY_PTR(glTexBuffer_Idx))


GL_APICALL void GL_APIENTRY
glTexBuffer (GLenum target, GLenum internalformat, GLuint buffer)
{
    prepare_gles_tracer ();

    glTexBuffer_ (target, internalformat, buffer);

    fprintf (g_log_fp, "glTexBuffer(%s, %s, %d);\n",
             get_target_str (target), 
             get_tex_format_str (internalformat), buffer);
}

