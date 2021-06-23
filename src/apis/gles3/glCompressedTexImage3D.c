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
    case GL_TEXTURE_3D       : return "GL_TEXTURE_3D";
    case GL_TEXTURE_2D_ARRAY : return "GL_TEXTURE_2D_ARRAY";
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


#define glCompressedTexImage3D_   \
    ((void (*)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)) \
    GLES_ENTRY_PTR(glCompressedTexImage3D_Idx))


GL_APICALL void GL_APIENTRY
glCompressedTexImage3D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth,
                        GLint border, GLsizei imageSize, const void *data)
{
    prepare_gles_tracer ();

    glCompressedTexImage3D_ (target, level, internalformat, width, height, depth, border, imageSize, data);

    fprintf (g_log_fp, "glCompressedTexImage3D(%s, %d, %s, %d, %d, %d, %d, %d, %p);",
                get_tex_target_str (target), level, get_tex_format_str (internalformat),
                width, height, depth, border, imageSize, data);

    fprintf (g_log_fp, "\n");

    s_count ++;
}

