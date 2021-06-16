#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_query_name_str (EGLint name)
{
    switch (name)
    {
    case GL_EXTENSIONS                  : return "GL_EXTENSIONS";
    case GL_VENDOR                      : return "GL_VENDOR";
    case GL_RENDERER                    : return "GL_RENDERER";
    case GL_VERSION                     : return "GL_VERSION";
    case GL_SHADING_LANGUAGE_VERSION    : return "GL_SHADING_LANGUAGE_VERSION";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetStringi_   \
    ((const GLubyte * (*)(GLenum name, GLuint index))  \
    GLES_ENTRY_PTR(glGetStringi_Idx))


GL_APICALL const GLubyte *GL_APIENTRY
glGetStringi (GLenum name, GLuint index)
{
    prepare_gles_tracer ();

    const GLubyte *str = glGetStringi_ (name, index);

    fprintf (g_log_fp, "glGetStringi(%-30s, %d);", get_query_name_str (name), index);
    fprintf (g_log_fp, " // %s", str);

    fprintf (g_log_fp, "\n");

    return str;
}

