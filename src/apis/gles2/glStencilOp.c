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
get_stencil_test_str (GLenum testmode)
{
    switch (testmode)
    {
    case GL_KEEP                        : return "GL_KEEP";
    case GL_ZERO                        : return "GL_ZERO";
    case GL_REPLACE                     : return "GL_REPLACE";
    case GL_INCR                        : return "GL_INCR";
    case GL_INCR_WRAP                   : return "GL_INCR_WRAP";
    case GL_DECR                        : return "GL_DECR";
    case GL_DECR_WRAP                   : return "GL_DECR_WRAP";
    case GL_INVERT                      : return "GL_INVERT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", testmode);
    return s_strbuf;
}


#define glStencilOp_   \
    ((void (*)(GLenum fail, GLenum zfail, GLenum zpass)) \
    GLES_ENTRY_PTR(glStencilOp_Idx))

#define glStencilOpSeparate_   \
    ((void (*)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)) \
    GLES_ENTRY_PTR(glStencilOpSeparate_Idx))



GL_APICALL void GL_APIENTRY
glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
    prepare_gles_tracer ();

    glStencilOp_ (fail, zfail, zpass);

    fprintf (g_log_fp, "glStencilOp(%s, %s, %s);",
                get_stencil_test_str (fail),
                get_stencil_test_str (zfail),
                get_stencil_test_str (zpass));
    fprintf (g_log_fp, "\n");
}

GL_APICALL void GL_APIENTRY
glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
    prepare_gles_tracer ();

    glStencilOpSeparate_ (face, sfail, dpfail, dppass);

    fprintf (g_log_fp, "glStencilOpSeparate(%s, %s, %s, %s);",
                get_stencil_face_str (face),
                get_stencil_test_str (sfail),
                get_stencil_test_str (dpfail),
                get_stencil_test_str (dppass));
    fprintf (g_log_fp, "\n");
}
