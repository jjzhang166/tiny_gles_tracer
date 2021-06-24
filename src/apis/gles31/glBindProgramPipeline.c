#include <stdio.h>
#include "GLEStrace.h"


#define glBindProgramPipeline_   \
    ((void (*)(GLuint pipeline))  \
    GLES_ENTRY_PTR(glBindProgramPipeline_Idx))


GL_APICALL void GL_APIENTRY
glBindProgramPipeline (GLuint pipeline)
{
    prepare_gles_tracer ();

    glBindProgramPipeline_ (pipeline);

    fprintf (g_log_fp, "glBindProgramPipeline(%d);\n", pipeline);
}

