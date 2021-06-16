#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_2D                  : return "GL_TEXTURE_2D";
    case GL_TEXTURE_CUBE_MAP            : return "GL_TEXTURE_CUBE_MAP";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glBindTexture_   \
    ((void (*)(GLenum target, GLuint texture))  \
    GLES_ENTRY_PTR(glBindTexture_Idx))


GL_APICALL void GL_APIENTRY
glBindTexture (GLenum target, GLuint texture)
{
    prepare_gles_tracer ();

    glBindTexture_ (target, texture);

    fprintf (g_log_fp, "glBindTexture(%s, %d);\n",
             get_target_str (target), texture);
}

