#include <stdio.h>
#include "GLEStrace.h"


#define glGetSamplerParameteriv_   \
    ((void (*)(GLuint sampler, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetSamplerParameteriv_Idx))

#define glGetSamplerParameterfv_   \
    ((void (*)(GLuint sampler, GLenum pname, GLfloat *params))  \
    GLES_ENTRY_PTR(glGetSamplerParameterfv_Idx))


GL_APICALL void GL_APIENTRY
glGetSamplerParameteriv (GLuint sampler, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetSamplerParameteriv_ (sampler, pname, params);

    fprintf (g_log_fp, "glGetSamplerParameteriv(%d, %d, %p);", 
             sampler, pname, params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetSamplerParameterfv (GLuint sampler, GLenum pname, GLfloat *params)
{
    prepare_gles_tracer ();

    glGetSamplerParameterfv_ (sampler, pname, params);

    fprintf (g_log_fp, "glGetSamplerParameterfv(%d, %d, %p);", 
             sampler, pname, params);
    if (params) fprintf (g_log_fp, " // params = %f\n", *params);
}
