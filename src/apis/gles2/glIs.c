#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_caps_str (GLenum cap)
{
    switch (cap)
    {
    case GL_BLEND                           : return "GL_BLEND";
    case GL_CULL_FACE                       : return "GL_CULL_FACE";
    case GL_DEPTH_TEST                      : return "GL_DEPTH_TEST";
    case GL_DITHER                          : return "GL_DITHER";
    case GL_POLYGON_OFFSET_FILL             : return "GL_POLYGON_OFFSET_FILL";
    case GL_PRIMITIVE_RESTART_FIXED_INDEX   : return "GL_PRIMITIVE_RESTART_FIXED_INDEX";
    case GL_RASTERIZER_DISCARD              : return "GL_RASTERIZER_DISCARD";
    case GL_SAMPLE_ALPHA_TO_COVERAGE        : return "GL_SAMPLE_ALPHA_TO_COVERAGE";
    case GL_SAMPLE_COVERAGE                 : return "GL_SAMPLE_COVERAGE";
    case GL_SCISSOR_TEST                    : return "GL_SCISSOR_TEST";
    case GL_STENCIL_TEST                    : return "GL_STENCIL_TEST";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", cap);
    return s_strbuf;
}


#define glIsBuffer_   \
    ((GLboolean (*)(GLuint buffer)) \
    GLES_ENTRY_PTR(glIsBuffer_Idx))

#define glIsEnabled_   \
    ((GLboolean (*)(GLenum cap)) \
    GLES_ENTRY_PTR(glIsEnabled_Idx))

#define glIsFramebuffer_   \
    ((GLboolean (*)(GLuint framebuffer)) \
    GLES_ENTRY_PTR(glIsFramebuffer_Idx))

#define glIsProgram_   \
    ((GLboolean (*)(GLuint program)) \
    GLES_ENTRY_PTR(glIsProgram_Idx))

#define glIsRenderbuffer_   \
    ((GLboolean (*)(GLuint renderbuffer)) \
    GLES_ENTRY_PTR(glIsRenderbuffer_Idx))

#define glIsShader_   \
    ((GLboolean (*)(GLuint shader)) \
    GLES_ENTRY_PTR(glIsShader_Idx))

#define glIsTexture_   \
    ((GLboolean (*)(GLuint texture)) \
    GLES_ENTRY_PTR(glIsTexture_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsBuffer (GLuint buffer)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsBuffer_ (buffer);

    fprintf (g_log_fp, "glIsBuffer(%d); // ret=%d\n", buffer, ret);

    return ret;
}

GL_APICALL GLboolean GL_APIENTRY
glIsEnabled (GLenum cap)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsEnabled_ (cap);

    fprintf (g_log_fp, "glIsEnabled(%s); // ret=%d\n",
             get_caps_str (cap), ret);

    return ret;
}

GL_APICALL GLboolean GL_APIENTRY
glIsFramebuffer (GLuint framebuffer)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsFramebuffer_ (framebuffer);

    fprintf (g_log_fp, "glIsFramebuffer(%d); // ret=%d\n", framebuffer, ret);

    return ret;
}

GL_APICALL GLboolean GL_APIENTRY
glIsProgram (GLuint program)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsProgram_ (program);

    fprintf (g_log_fp, "glIsProgram(%d); // ret=%d\n", program, ret);

    return ret;
}

GL_APICALL GLboolean GL_APIENTRY
glIsRenderbuffer (GLuint renderbuffer)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsRenderbuffer_ (renderbuffer);

    fprintf (g_log_fp, "glIsRenderbuffer(%d); // ret=%d\n", renderbuffer, ret);

    return ret;
}

GL_APICALL GLboolean GL_APIENTRY
glIsShader (GLuint shader)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsShader_ (shader);

    fprintf (g_log_fp, "glIsShader(%d); // ret=%d\n", shader, ret);

    return ret;
}

GL_APICALL GLboolean GL_APIENTRY
glIsTexture (GLuint texture)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsTexture_ (texture);

    fprintf (g_log_fp, "glIsTexture(%d); // ret=%d\n", texture, ret);

    return ret;
}
