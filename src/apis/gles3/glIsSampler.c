#include <stdio.h>
#include "GLEStrace.h"


#define glIsSampler_   \
    ((GLboolean (*)(GLuint sampler))  \
    GLES_ENTRY_PTR(glIsSampler_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsSampler (GLuint sampler)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsSampler_ (sampler);

    fprintf (g_log_fp, "glIsSampler(%d); // ret=%d\n", sampler, ret);

    return ret;
}

