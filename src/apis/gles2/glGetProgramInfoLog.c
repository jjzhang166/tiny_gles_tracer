#include <stdio.h>
#include "GLEStrace.h"


#define glGetProgramInfoLog_   \
    ((void (*)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog))  \
    GLES_ENTRY_PTR(glGetProgramInfoLog_Idx))


GL_APICALL void GL_APIENTRY
glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
    prepare_gles_tracer ();

    glGetProgramInfoLog_ (program, bufSize, length, infoLog);

    fprintf (g_log_fp, "glGetProgramInfoLog(%d, %d, %p, %p);\n", 
                        program, bufSize, length, infoLog);
}

