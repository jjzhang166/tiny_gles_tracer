#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_access_str (GLenum access)
{
    switch (access)
    {
    case GL_READ_ONLY   : return "GL_READ_ONLY";
    case GL_WRITE_ONLY  : return "GL_WRITE_ONLY";
    case GL_READ_WRITE  : return "GL_READ_WRITE ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", access);
    return s_strbuf;
}

static char *
get_format_str (GLenum format)
{
    switch (format)
    {
    case GL_RGBA32F     : return "GL_RGBA32F";
    case GL_RGBA16F     : return "GL_RGBA16F";
    case GL_R32F        : return "GL_R32F";
    case GL_RGBA32UI    : return "GL_RGBA32UI";
    case GL_RGBA16UI    : return "GL_RGBA16UI";
    case GL_RGBA8UI     : return "GL_RGBA8UI";
    case GL_R32UI       : return "GL_R32UI";
    case GL_RGBA32I     : return "GL_RGBA32I";
    case GL_RGBA16I     : return "GL_RGBA16I";
    case GL_RGBA8I      : return "GL_RGBA8I";
    case GL_R32I        : return "GL_R32I";
    case GL_RGBA8       : return "GL_RGBA8";
    case GL_RGBA8_SNORM : return "GL_RGBA8_SNORM";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", format);
    return s_strbuf;
}


#define glBindImageTexture_   \
    ((void (*)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format))  \
    GLES_ENTRY_PTR(glBindImageTexture_Idx))


GL_APICALL void GL_APIENTRY
glBindImageTexture (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
{
    prepare_gles_tracer ();

    glBindImageTexture_ (unit, texture, level, layered, layer, access, format);

    fprintf (g_log_fp, "glBindImageTexture(%d, %d, %d, %d, %d, %s, %s);\n",
             unit, texture, level, layered, layer, get_access_str (access), get_format_str (format));
}

