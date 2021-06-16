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


#define glStencilMask_   \
    ((void (*)(GLuint mask)) \
    GLES_ENTRY_PTR(glStencilMask_Idx))

#define glStencilMaskSeparate_   \
    ((void (*)(GLenum face, GLuint mask)) \
    GLES_ENTRY_PTR(glStencilMaskSeparate_Idx))



GL_APICALL void GL_APIENTRY
glStencilMask (GLuint mask)
{
    prepare_gles_tracer ();

    glStencilMask_ (mask);

    fprintf (g_log_fp, "glStencilMask(0x%08x);\n", mask);
}

GL_APICALL void GL_APIENTRY
glStencilMaskSeparate (GLenum face, GLuint mask)
{
    prepare_gles_tracer ();

    glStencilMaskSeparate_ (face, mask);

    fprintf (g_log_fp, "glStencilMaskSeparate(%s, 0x%08x);\n",
                get_stencil_face_str (face), mask);
}
