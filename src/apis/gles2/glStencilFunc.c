#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_stencil_face_str (GLenum face)
{
    switch (face)
    {
    case GL_FRONT                       : return "GL_FRONT";
    case GL_BACK                        : return "GL_BACK";
    case GL_FRONT_AND_BACK              : return "GL_FRONT_AND_BACK";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", face);
    return s_strbuf;
}

static char *
get_stencil_func_str (GLenum func)
{
    switch (func)
    {
    case GL_NEVER                       : return "GL_NEVER";
    case GL_LESS                        : return "GL_LESS";
    case GL_LEQUAL                      : return "GL_LEQUAL";
    case GL_GREATER                     : return "GL_GREATER";
    case GL_GEQUAL                      : return "GL_GEQUAL";
    case GL_EQUAL                       : return "GL_EQUAL";
    case GL_NOTEQUAL                    : return "GL_NOTEQUAL";
    case GL_ALWAYS                      : return "GL_ALWAYS";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", func);
    return s_strbuf;
}


#define glStencilFunc_   \
    ((void (*)(GLenum func, GLint ref, GLuint mask)) \
    GLES_ENTRY_PTR(glStencilFunc_Idx))

#define glStencilFuncSeparate_   \
    ((void (*)(GLenum face, GLenum func, GLint ref, GLuint mask)) \
    GLES_ENTRY_PTR(glStencilFuncSeparate_Idx))



GL_APICALL void GL_APIENTRY
glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
    prepare_gles_tracer ();

    glStencilFunc_ (func, ref, mask);

    fprintf (g_log_fp, "glStencilFunc(%s, %d, 0x%08x);\n",
             get_stencil_func_str (func), ref, mask);
}

GL_APICALL void GL_APIENTRY
glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask)
{
    prepare_gles_tracer ();

    glStencilFuncSeparate_ (face, func, ref, mask);

    fprintf (g_log_fp, "glStencilFuncSeparate(%s, %s, %d, 0x%08x);\n",
             get_stencil_face_str (face),
             get_stencil_func_str (func), ref, mask);
}
