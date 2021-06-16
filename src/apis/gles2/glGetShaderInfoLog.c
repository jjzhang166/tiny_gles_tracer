#include <stdio.h>
#include "GLEStrace.h"


#define glGetShaderInfoLog_   \
    ((void (*)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog))  \
    GLES_ENTRY_PTR(glGetProgramInfoLog_Idx))


GL_APICALL void GL_APIENTRY
glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
    prepare_gles_tracer ();

    glGetShaderInfoLog_ (shader, bufSize, length, infoLog);

    fprintf (g_log_fp, "glGetShaderInfoLog(%d, %d, %p, %p);\n", 
                        shader, bufSize, length, infoLog);
}

