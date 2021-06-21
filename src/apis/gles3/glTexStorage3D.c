#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_tex_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_3D                  : return "GL_TEXTURE_3D";
    case GL_TEXTURE_2D_ARRAY            : return "GL_TEXTURE_2D_ARRAY";
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
    case GL_R8                          : return "GL_R8";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", format);
    return s_strbuf;
}


#define glTexStorage3D_   \
    ((void (*)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)) \
    GLES_ENTRY_PTR(glTexStorage3D_Idx))


GL_APICALL void GL_APIENTRY
glTexStorage3D (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
    prepare_gles_tracer ();

    glTexStorage3D_ (target, levels, internalformat, width, height, depth);

    fprintf (g_log_fp, "glTexStorage3D(%s, %d, %s, %d, %d, %d);\n",
                get_tex_target_str (target), levels,
                get_tex_format_str (internalformat), width, height, depth);

}

