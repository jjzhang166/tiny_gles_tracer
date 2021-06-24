#include <stdio.h>
#include "GLEStrace.h"


#define glGenProgramPipelines_   \
    ((void (*)(GLsizei n, GLuint *pipelines))  \
    GLES_ENTRY_PTR(glGenProgramPipelines_Idx))


GL_APICALL void GL_APIENTRY
glGenProgramPipelines (GLsizei n, GLuint *pipelines)
{
    prepare_gles_tracer ();

    glGenProgramPipelines_ (n, pipelines);

    fprintf (g_log_fp, "glGenProgramPipelines(%d, %p);", n, pipelines);
    fprintf (g_log_fp, " // ");
    if (pipelines)
    {
        for (int i = 0; i < n; i ++)
        {
            fprintf (g_log_fp, "%d,", pipelines[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

