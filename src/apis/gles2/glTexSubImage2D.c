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
    case GL_RED                         : return "GL_RED";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", format);
    return s_strbuf;
}

static char *
get_tex_type_str (GLenum type)
{
    switch (type)
    {
    case GL_UNSIGNED_BYTE               : return "GL_UNSIGNED_BYTE";
    case GL_UNSIGNED_SHORT_5_6_5        : return "GL_UNSIGNED_SHORT_5_6_5";
    case GL_UNSIGNED_SHORT_4_4_4_4      : return "GL_UNSIGNED_SHORT_4_4_4_4";
    case GL_UNSIGNED_SHORT_5_5_5_1      : return "GL_UNSIGNED_SHORT_5_5_5_1";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}


#define glTexSubImage2D_   \
    ((void (*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)) \
    GLES_ENTRY_PTR(glTexSubImage2D_Idx))

#define glGetIntegerv_   \
    ((void (*)(GLenum pname, GLint *data))  \
    GLES_ENTRY_PTR(glGetIntegerv_Idx))


GL_APICALL void GL_APIENTRY
glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height,
                 GLenum format, GLenum type, const void *pixels)
{
    prepare_gles_tracer ();

    glTexSubImage2D_ (target, level, xoffset, yoffset, width, height, format, type, pixels);

    fprintf (g_log_fp, "glTexSubImage2D(%s, %d, %d, %d, %d, %d, %s, %s, %p);",
                        get_tex_target_str (target), level, xoffset, yoffset, width, height,
                        get_tex_format_str (format),
                        get_tex_type_str (type), pixels);

    if (pixels && g_dump_texture)
    {
        char fname[128];
        snprintf (fname, sizeof(fname), "%05d_glTexSubImage2D_%05d.tga", g_pid, s_count);

        int row_length = 0;
        glGetIntegerv_ (GL_UNPACK_ROW_LENGTH, &row_length);
        if (row_length != 0)
            width = row_length;

        if (format == GL_RGBA && type == GL_UNSIGNED_BYTE)
        {
            save_to_tga_file (fname, (void *)pixels, width, height);
            fprintf (g_log_fp, " // %s", fname);
        }

        if (format == GL_BGRA_EXT && type == GL_UNSIGNED_BYTE)
        {
            int  size = width * height * 4;
            unsigned char *imgdst = (unsigned char *)malloc (size);
            unsigned char *imgsrc = (unsigned char *)pixels;
            if (imgdst)
            {
                for (int i = 0; i < width * height; i ++)
                {
                    imgdst[i * 4 + 0] = imgsrc[i * 4 + 2];
                    imgdst[i * 4 + 1] = imgsrc[i * 4 + 1];
                    imgdst[i * 4 + 2] = imgsrc[i * 4 + 0];
                    imgdst[i * 4 + 3] = imgsrc[i * 4 + 3];
                }
                save_to_tga_file (fname, (void *)imgdst, width, height);
                fprintf (g_log_fp, "// %s", fname);
                free (imgdst);
            }
        }

        if ((format == GL_LUMINANCE && type == GL_UNSIGNED_BYTE) ||
            (format == GL_ALPHA     && type == GL_UNSIGNED_BYTE) ||
            (format == GL_RED       && type == GL_UNSIGNED_BYTE))
        {
            int  size = width * height * 4;
            unsigned char *imgdst = (unsigned char *)malloc (size);
            unsigned char *imgsrc = (unsigned char *)pixels;
            if (imgdst)
            {
                for (int i = 0; i < width * height; i ++)
                {
                    imgdst[i * 4 + 0] = imgsrc[i];
                    imgdst[i * 4 + 1] = imgsrc[i];
                    imgdst[i * 4 + 2] = imgsrc[i];
                    imgdst[i * 4 + 3] = 0xFF;
                }
                save_to_tga_file (fname, (void *)imgdst, width, height);
                fprintf (g_log_fp, "// %s", fname);
                free (imgdst);
            }
        }
    }
    fprintf (g_log_fp, "\n");

    s_count ++;
}

