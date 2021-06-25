#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_id_str (GLenum identifier)
{
    switch (identifier)
    {
    case GL_BUFFER              : return "GL_BUFFER";
    case GL_SHADER              : return "GL_SHADER";
    case GL_PROGRAM             : return "GL_PROGRAM";
    case GL_VERTEX_ARRAY        : return "GL_VERTEX_ARRAY";
    case GL_QUERY               : return "GL_QUERY";
    case GL_PROGRAM_PIPELINE    : return "GL_PROGRAM_PIPELINE";
    case GL_TRANSFORM_FEEDBACK  : return "GL_TRANSFORM_FEEDBACK";
    case GL_SAMPLER             : return "GL_SAMPLER";
    case GL_TEXTURE             : return "GL_TEXTURE";
    case GL_RENDERBUFFER        : return "GL_RENDERBUFFER";
    case GL_FRAMEBUFFER         : return "GL_FRAMEBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", identifier);
    return s_strbuf;
}

#define glObjectLabel_   \
    ((void (*)(GLenum identifier, GLuint name, GLsizei length, const GLchar *label))  \
    GLES_ENTRY_PTR(glObjectLabel_Idx))


GL_APICALL void GL_APIENTRY
glObjectLabel (GLenum identifier, GLuint name, GLsizei length, const GLchar *label)
{
    prepare_gles_tracer ();

    glObjectLabel_ (identifier, name, length, label);

    fprintf (g_log_fp, "glObjectLabel(%s, %d, %d, %s);\n",
             get_id_str (identifier), name, length, label);
}

