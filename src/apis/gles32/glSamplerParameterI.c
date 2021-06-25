#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glSamplerParameterIiv_   \
    ((void (*)(GLuint sampler, GLenum pname, const GLint *param)) \
    GLES_ENTRY_PTR(glSamplerParameterIiv_Idx))

#define glSamplerParameterIuiv_   \
    ((void (*)(GLuint sampler, GLenum pname, const GLuint *param)) \
    GLES_ENTRY_PTR(glSamplerParameterIuiv_Idx))


GL_APICALL void GL_APIENTRY
glSamplerParameterIiv (GLuint sampler, GLenum pname, const GLint *param)
{
    prepare_gles_tracer ();

    glSamplerParameterIiv_ (sampler, pname, param);

    fprintf (g_log_fp, "glSamplerParameterIiv(%d, %d, %p);\n",
                sampler, pname, param);
}

GL_APICALL void GL_APIENTRY
glSamplerParameterIuiv (GLuint sampler, GLenum pname, const GLuint *param)
{
    prepare_gles_tracer ();

    glSamplerParameterIuiv_ (sampler, pname, param);

    fprintf (g_log_fp, "glSamplerParameterIuiv(%d, %d, %p);\n",
                sampler, pname, param);
}
