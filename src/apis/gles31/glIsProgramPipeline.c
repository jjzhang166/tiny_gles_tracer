#include <stdio.h>
#include "GLEStrace.h"


#define glIsProgramPipeline_   \
    ((GLboolean (*)(GLuint pipeline))  \
    GLES_ENTRY_PTR(glIsProgramPipeline_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsProgramPipeline (GLuint pipeline)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsProgramPipeline_ (pipeline);

    fprintf (g_log_fp, "glIsProgramPipeline(%d); // ret=%d\n", pipeline, ret);

    return ret;
}

