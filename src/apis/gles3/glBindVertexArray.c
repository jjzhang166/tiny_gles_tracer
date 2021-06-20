#include <stdio.h>
#include "GLEStrace.h"


#define glBindVertexArray_   \
    ((void (*)(GLuint array))  \
    GLES_ENTRY_PTR(glBindVertexArray_Idx))


GL_APICALL void GL_APIENTRY
glBindVertexArray (GLuint array)
{
    prepare_gles_tracer ();

    glBindVertexArray_ (array);

    fprintf (g_log_fp, "glBindVertexArray(%d);\n", array);
}

