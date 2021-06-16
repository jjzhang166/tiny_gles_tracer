#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_blend_mode_str (GLenum mode)
{
    switch (mode)
    {
    case GL_FUNC_ADD                    : return "GL_FUNC_ADD";
    case GL_FUNC_SUBTRACT               : return "GL_FUNC_SUBTRACT";
    case GL_FUNC_REVERSE_SUBTRACT       : return "GL_FUNC_REVERSE_SUBTRACT";
    case GL_MIN                         : return "GL_MIN";
    case GL_MAX                         : return "GL_MAX";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", mode);
    return s_strbuf;
}


#define glBlendEquation_   \
    ((void (*)(GLenum mode)) \
    GLES_ENTRY_PTR(glBlendEquation_Idx))

#define glBlendEquationSeparate_   \
    ((void (*)(GLenum modeRGB, GLenum modeAlpha)) \
    GLES_ENTRY_PTR(glBlendEquationSeparate_Idx))



GL_APICALL void GL_APIENTRY
glBlendEquation (GLenum mode)
{
    prepare_gles_tracer ();

    glBlendEquation_ (mode);

    fprintf (g_log_fp, "glBlendEquation(%s);\n", get_blend_mode_str (mode));
}

GL_APICALL void GL_APIENTRY
glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha)
{
    prepare_gles_tracer ();

    glBlendEquationSeparate_ (modeRGB, modeAlpha);

    fprintf (g_log_fp, "glBlendEquationSeparate(%s, %s);\n",
             get_blend_mode_str (modeRGB),
             get_blend_mode_str (modeAlpha));
}
