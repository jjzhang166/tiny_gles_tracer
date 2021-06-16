#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_format_str (GLenum format)
{
    switch (format)
    {
    case GL_ALPHA                       : return "GL_ALPHA";
    case GL_RGB                         : return "GL_RGB";
    case GL_RGBA                        : return "GL_RGBA";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", format);
    return s_strbuf;
}

static char *
get_type_str (GLenum type)
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


#define glReadPixels_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels))  \
    GLES_ENTRY_PTR(glReadPixels_Idx))


GL_APICALL void GL_APIENTRY
glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)
{
    prepare_gles_tracer ();

    glReadPixels_ (x, y, width, height, format, type, pixels);

    fprintf (g_log_fp, "glReadPixels(%d, %d, %d, %d, %s, %s, %p);\n",
             x, y, width, height, get_format_str (format), get_type_str (type), pixels);
}

