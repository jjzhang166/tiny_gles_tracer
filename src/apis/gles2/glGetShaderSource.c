#include <stdio.h>
#include "GLEStrace.h"


#define glGetShaderSource_   \
    ((void (*)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source))  \
    GLES_ENTRY_PTR(glGetShaderSource_Idx))


GL_APICALL void GL_APIENTRY
glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
{
    prepare_gles_tracer ();

    glGetShaderSource_ (shader, bufSize, length, source);

    fprintf (g_log_fp, "glGetShaderSource(%d, %d, %p, %p);", 
                        shader, bufSize, length, source);
}

