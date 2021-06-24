#include <stdio.h>
#include "GLEStrace.h"


#define glGetProgramPipelineInfoLog_   \
    ((void (*)(GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog))  \
    GLES_ENTRY_PTR(glGetProgramPipelineInfoLog_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramPipelineInfoLog (GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
    prepare_gles_tracer ();

    glGetProgramPipelineInfoLog_ (pipeline, bufSize, length, infoLog);

    fprintf (g_log_fp, "glGetProgramPipelineInfoLog(%d, %d, %p, %p);\n", 
                        pipeline, bufSize, length, infoLog);
}

