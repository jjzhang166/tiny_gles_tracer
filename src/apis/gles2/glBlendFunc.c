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


#define glBlendFunc_   \
    ((void (*)(GLenum sfactor, GLenum dfactor)) \
    GLES_ENTRY_PTR(glBlendFunc_Idx))

#define glBlendFuncSeparate_   \
    ((void (*)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)) \
    GLES_ENTRY_PTR(glBlendFuncSeparate_Idx))



GL_APICALL void GL_APIENTRY
glBlendFunc (GLenum sfactor, GLenum dfactor)
{
    prepare_gles_tracer ();

    glBlendFunc_ (sfactor, dfactor);

    fprintf (g_log_fp, "glBlendFunc(%s, %s);\n",
             get_blend_func_str (sfactor), get_blend_func_str (dfactor));
}

GL_APICALL void GL_APIENTRY
glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    prepare_gles_tracer ();

    glBlendFuncSeparate_ (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);

    fprintf (g_log_fp, "glBlendFuncSeparate(%s, %s, %s, %s);\n",
             get_blend_func_str (sfactorRGB),
             get_blend_func_str (dfactorRGB),
             get_blend_func_str (sfactorAlpha),
             get_blend_func_str (dfactorAlpha));
}
