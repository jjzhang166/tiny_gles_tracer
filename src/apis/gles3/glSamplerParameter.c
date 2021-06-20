#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glSamplerParameterf_   \
    ((void (*)(GLuint sampler, GLenum pname, GLfloat param)) \
    GLES_ENTRY_PTR(glSamplerParameterf_Idx))

#define glSamplerParameterfv_   \
    ((void (*)(GLuint sampler, GLenum pname, const GLfloat *param)) \
    GLES_ENTRY_PTR(glSamplerParameterfv_Idx))

#define glSamplerParameteri_   \
    ((void (*)(GLuint sampler, GLenum pname, GLint param)) \
    GLES_ENTRY_PTR(glSamplerParameteri_Idx))

#define glSamplerParameteriv_   \
    ((void (*)(GLuint sampler, GLenum pname, const GLint *param)) \
    GLES_ENTRY_PTR(glSamplerParameteriv_Idx))


GL_APICALL void GL_APIENTRY
glSamplerParameterf (GLuint sampler, GLenum pname, GLfloat param)
{
    prepare_gles_tracer ();

    glSamplerParameterf_ (sampler, pname, param);

    fprintf (g_log_fp, "glSamplerParameterf(%d, %d, %f);",
                sampler, pname, param);
    fprintf (g_log_fp, "\n");
}

GL_APICALL void GL_APIENTRY
glSamplerParameterfv (GLuint sampler, GLenum pname, const GLfloat *param)
{
    prepare_gles_tracer ();

    glSamplerParameterfv_ (sampler, pname, param);

    fprintf (g_log_fp, "glSamplerParameterfv(%d, %d, %p);",
                sampler, pname, param);
    fprintf (g_log_fp, "\n");
}

GL_APICALL void GL_APIENTRY
glSamplerParameteri (GLuint sampler, GLenum pname, GLint param)
{
    prepare_gles_tracer ();

    glSamplerParameteri_ (sampler, pname, param);

    fprintf (g_log_fp, "glSamplerParameteri(%d, %d, %d);",
                sampler, pname, param);
    fprintf (g_log_fp, "\n");
}

GL_APICALL void GL_APIENTRY
glSamplerParameteriv (GLuint sampler, GLenum pname, const GLint *param)
{
    prepare_gles_tracer ();

    glSamplerParameteriv_ (sampler, pname, param);

    fprintf (g_log_fp, "glSamplerParameteriv(%d, %d, %p);",
                sampler, pname, param);
    fprintf (g_log_fp, "\n");
}

