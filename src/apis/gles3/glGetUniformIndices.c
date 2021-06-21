#include <stdio.h>
#include "GLEStrace.h"


#define glGetUniformIndices_   \
    ((void (*)(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices))  \
    GLES_ENTRY_PTR(glGetUniformIndices_Idx))


GL_APICALL void GL_APIENTRY
glGetUniformIndices (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices)
{
    prepare_gles_tracer ();

    glGetUniformIndices_ (program, uniformCount, uniformNames, uniformIndices);

    fprintf (g_log_fp, "glGetUniformIndices(%d, %d, %p, %p);\n",
             program, uniformCount, uniformNames, uniformIndices);
}

