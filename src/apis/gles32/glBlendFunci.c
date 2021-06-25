#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_blend_func_str (GLenum factor)
{
    switch (factor)
    {
    case GL_ZERO                        : return "GL_ZERO";
    case GL_ONE                         : return "GL_ONE";
    case GL_SRC_COLOR                   : return "GL_SRC_COLOR";
    case GL_ONE_MINUS_SRC_COLOR         : return "GL_ONE_MINUS_SRC_COLOR";
    case GL_DST_COLOR                   : return "GL_DST_COLOR";
    case GL_ONE_MINUS_DST_COLOR         : return "GL_ONE_MINUS_DST_COLOR";
    case GL_SRC_ALPHA                   : return "GL_SRC_ALPHA";
    case GL_ONE_MINUS_SRC_ALPHA         : return "GL_ONE_MINUS_SRC_ALPHA";
    case GL_DST_ALPHA                   : return "GL_DST_ALPHA";
    case GL_ONE_MINUS_DST_ALPHA         : return "GL_ONE_MINUS_DST_ALPHA";
    case GL_CONSTANT_COLOR              : return "GL_CONSTANT_COLOR";
    case GL_ONE_MINUS_CONSTANT_COLOR    : return "GL_ONE_MINUS_CONSTANT_COLOR";
    case GL_CONSTANT_ALPHA              : return "GL_CONSTANT_ALPHA";
    case GL_ONE_MINUS_CONSTANT_ALPHA    : return "GL_ONE_MINUS_CONSTANT_ALPHA";
    case GL_SRC_ALPHA_SATURATE          : return "GL_SRC_ALPHA_SATURATE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", factor);
    return s_strbuf;
}


#define glBlendFunci_   \
    ((void (*)(GLuint buf, GLenum src, GLenum dst)) \
    GLES_ENTRY_PTR(glBlendFunci_Idx))

#define glBlendFuncSeparatei_   \
    ((void (*)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)) \
    GLES_ENTRY_PTR(glBlendFuncSeparatei_Idx))



GL_APICALL void GL_APIENTRY
glBlendFunci (GLuint buf, GLenum src, GLenum dst)
{
    prepare_gles_tracer ();

    glBlendFunci_ (buf, src, dst);

    fprintf (g_log_fp, "glBlendFunci(%d, %s, %s);\n",
             buf, get_blend_func_str (src), get_blend_func_str (dst));
}

GL_APICALL void GL_APIENTRY
glBlendFuncSeparatei (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
    prepare_gles_tracer ();

    glBlendFuncSeparatei_ (buf, srcRGB, dstRGB, srcAlpha, dstAlpha);

    fprintf (g_log_fp, "glBlendFuncSeparatei(%d, %s, %s, %s, %s);\n",
             buf,
             get_blend_func_str (srcRGB),
             get_blend_func_str (dstRGB),
             get_blend_func_str (srcAlpha),
             get_blend_func_str (dstAlpha));
}
