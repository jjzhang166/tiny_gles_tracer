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


#define glCopyTexSubImage3D_   \
    ((void (*)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)) \
    GLES_ENTRY_PTR(glCopyTexSubImage3D_Idx))


GL_APICALL void GL_APIENTRY
glCopyTexSubImage3D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, 
                     GLint x, GLint y, GLsizei width, GLsizei height)
{
    prepare_gles_tracer ();

    glCopyTexSubImage3D_ (target, level, xoffset, yoffset, zoffset, x, y, width, height);

    fprintf (g_log_fp, "glCopyTexSubImage3D(%s, %d, %d, %d, %d, %d, %d, %d, %d);\n",
                get_tex_target_str (target), level, xoffset, yoffset, zoffset, x, y, width, height);

    s_count ++;
}

