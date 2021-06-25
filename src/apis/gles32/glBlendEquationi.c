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


#define glBlendEquationi_   \
    ((void (*)(GLuint buf, GLenum mode)) \
    GLES_ENTRY_PTR(glBlendEquationi_Idx))

#define glBlendEquationSeparatei_   \
    ((void (*)(GLuint buf, GLenum modeRGB, GLenum modeAlpha)) \
    GLES_ENTRY_PTR(glBlendEquationSeparatei_Idx))



GL_APICALL void GL_APIENTRY
glBlendEquationi (GLuint buf, GLenum mode)
{
    prepare_gles_tracer ();

    glBlendEquationi_ (buf, mode);

    fprintf (g_log_fp, "glBlendEquationi(%d, %s);\n", buf, get_blend_mode_str (mode));
}

GL_APICALL void GL_APIENTRY
glBlendEquationSeparatei (GLuint buf, GLenum modeRGB, GLenum modeAlpha)
{
    prepare_gles_tracer ();

    glBlendEquationSeparatei_ (buf, modeRGB, modeAlpha);

    fprintf (g_log_fp, "glBlendEquationSeparatei(%d, %s, %s);\n",
             buf,
             get_blend_mode_str (modeRGB),
             get_blend_mode_str (modeAlpha));
}
