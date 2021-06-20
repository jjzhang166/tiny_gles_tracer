#include <stdio.h>
#include "GLEStrace.h"


#define glBindSampler_   \
    ((void (*)(GLuint unit, GLuint sampler))  \
    GLES_ENTRY_PTR(glBindSampler_Idx))


GL_APICALL void GL_APIENTRY
glBindSampler (GLuint unit, GLuint sampler)
{
    prepare_gles_tracer ();

    glBindSampler_ (unit, sampler);

    fprintf (g_log_fp, "glBindSampler(%d, %d);\n", unit, sampler);
}

