#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glDisableVertexAttribArray_   \
    ((void (*)(GLuint index)) \
    GLES_ENTRY_PTR(glDisableVertexAttribArray_Idx))


GL_APICALL void GL_APIENTRY
glDisableVertexAttribArray (GLuint index)
{
    prepare_gles_tracer ();

    glDisableVertexAttribArray_ (index);

    fprintf (g_log_fp, "glDisableVertexAttribArray(%d);\n", index);
}
