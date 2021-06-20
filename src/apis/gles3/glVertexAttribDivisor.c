#include <stdio.h>
#include "GLEStrace.h"


#define glVertexAttribDivisor_   \
    ((void (*)(GLuint index, GLuint divisor))  \
    GLES_ENTRY_PTR(glVertexAttribDivisor_Idx))


GL_APICALL void GL_APIENTRY
glVertexAttribDivisor (GLuint index, GLuint divisor)
{
    prepare_gles_tracer ();

    glVertexAttribDivisor_ (index, divisor);

    fprintf (g_log_fp, "glVertexAttribDivisor(%d, %d);\n", index, divisor);
}

