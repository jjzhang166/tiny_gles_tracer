#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glEnableVertexAttribArray_   \
    ((void (*)(GLuint index)) \
    GLES_ENTRY_PTR(glEnableVertexAttribArray_Idx))


GL_APICALL void GL_APIENTRY
glEnableVertexAttribArray (GLuint index)
{
    prepare_gles_tracer ();

    glEnableVertexAttribArray_ (index);

    fprintf (g_log_fp, "glEnableVertexAttribArray(%d);\n", index);
}
