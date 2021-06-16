#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"
#include "util_image_tga.h"


static int  s_count = 0;
static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_tex_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_2D                  : return "GL_TEXTURE_2D";
    case GL_TEXTURE_CUBE_MAP_POSITIVE_X : return "GL_TEXTURE_CUBE_MAP_POSITIVE_X";
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Y : return "GL_TEXTURE_CUBE_MAP_POSITIVE_Y";
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Z : return "GL_TEXTURE_CUBE_MAP_POSITIVE_Z";
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_X : return "GL_TEXTURE_CUBE_MAP_NEGATIVE_X";
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y : return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y";
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z : return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z";
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
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", format);
    return s_strbuf;
}


#define glCompressedTexSubImage2D_   \
    ((void (*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)) \
    GLES_ENTRY_PTR(glCompressedTexSubImage2D_Idx))


GL_APICALL void GL_APIENTRY
glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
                           GLenum format, GLsizei imageSize, const void *data)
{
    prepare_gles_tracer ();

    glCompressedTexSubImage2D_ (target, level, xoffset, yoffset, width, height, format, imageSize, data);

    fprintf (g_log_fp, "glCompressedTexImage2D(%s, %d, %d, %d, %d, %d, %s, %d, %p);",
                get_tex_target_str (target), level, xoffset, yoffset,
                width, height, get_tex_format_str (format),
                imageSize, data);

    fprintf (g_log_fp, "\n");

    s_count ++;
}

