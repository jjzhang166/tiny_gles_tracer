#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_shader_type_str (GLenum shadertype)
{
    switch (shadertype)
    {
    case GL_VERTEX_SHADER                   : return "GL_VERTEX_SHADER";
    case GL_FRAGMENT_SHADER                 : return "GL_FRAGMENT_SHADER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", shadertype);
    return s_strbuf;
}

static char *
get_precision_type_str (GLenum precisiontype)
{
    switch (precisiontype)
    {
    case GL_LOW_FLOAT                       : return "GL_LOW_FLOAT";
    case GL_MEDIUM_FLOAT                    : return "GL_MEDIUM_FLOAT";
    case GL_HIGH_FLOAT                      : return "GL_HIGH_FLOAT";
    case GL_LOW_INT                         : return "GL_LOW_INT";
    case GL_MEDIUM_INT                      : return "GL_MEDIUM_INT";
    case GL_HIGH_INT                        : return "GL_HIGH_INT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", precisiontype);
    return s_strbuf;
}

#define glGetShaderPrecisionFormat_   \
    ((void (*)(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision))  \
    GLES_ENTRY_PTR(glGetShaderPrecisionFormat_Idx))


GL_APICALL void GL_APIENTRY
glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
    prepare_gles_tracer ();

    glGetShaderPrecisionFormat_ (shadertype, precisiontype, range, precision);

    fprintf (g_log_fp, "glGetShaderPrecisionFormat(%s, %s, %p, %p); // ",
                        get_shader_type_str (shadertype),
                        get_precision_type_str (precisiontype),
                        range, precision);
    if (range)     fprintf (g_log_fp, "range=%d, ",   *range);
    if (precision) fprintf (g_log_fp, "precision=%d", *precision);
    fprintf (g_log_fp, "\n");
}

