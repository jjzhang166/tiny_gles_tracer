#include <stdio.h>
#include "GLEStrace.h"


#define glGetSamplerParameterIiv_   \
    ((void (*)(GLuint sampler, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetSamplerParameterIiv_Idx))

#define glGetSamplerParameterIuiv_   \
    ((void (*)(GLuint sampler, GLenum pname, GLuint *params))  \
    GLES_ENTRY_PTR(glGetSamplerParameterIuiv_Idx))


GL_APICALL void GL_APIENTRY
glGetSamplerParameterIiv (GLuint sampler, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetSamplerParameterIiv_ (sampler, pname, params);

    fprintf (g_log_fp, "glGetSamplerParameterIiv(%d, %d, %p);", 
             sampler, pname, params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetSamplerParameterIuiv (GLuint sampler, GLenum pname, GLuint *params)
{
    prepare_gles_tracer ();

    glGetSamplerParameterIuiv_ (sampler, pname, params);

    fprintf (g_log_fp, "glGetSamplerParameterIuiv(%d, %d, %p);", 
             sampler, pname, params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}
