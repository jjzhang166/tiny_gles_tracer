#include <stdio.h>
#include "GLEStrace.h"


#define glBindVertexBuffer_   \
    ((void (*)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride))  \
    GLES_ENTRY_PTR(glBindVertexBuffer_Idx))


GL_APICALL void GL_APIENTRY
glBindVertexBuffer (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
{
    prepare_gles_tracer ();

    glBindVertexBuffer_ (bindingindex, buffer, offset, stride);

    fprintf (g_log_fp, "glBindVertexBuffer(%d, %d, %ld, %d);\n",
             bindingindex, buffer, offset, stride);
}

