#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteProgramPipelines_   \
    ((void (*)(GLsizei n, const GLuint *pipelines))  \
    GLES_ENTRY_PTR(glDeleteProgramPipelines_Idx))


GL_APICALL void GL_APIENTRY
glDeleteProgramPipelines (GLsizei n, const GLuint *pipelines)
{
    prepare_gles_tracer ();

    glDeleteProgramPipelines_ (n, pipelines);

    fprintf (g_log_fp, "glDeleteProgramPipelines(%d, %p);", n, pipelines);
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

