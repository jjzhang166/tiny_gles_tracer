#include <stdio.h>
#include "GLEStrace.h"

#define glValidateProgramPipeline_   \
    ((void (*)(GLuint pipeline))  \
    GLES_ENTRY_PTR(glValidateProgramPipeline_Idx))



GL_APICALL void GL_APIENTRY
glValidateProgramPipeline (GLuint pipeline)
{
    prepare_gles_tracer ();

    glValidateProgramPipeline_ (pipeline);

    fprintf (g_log_fp, "glValidateProgramPipeline(%d);\n", pipeline);
}

