#include <stdio.h>
#include "GLEStrace.h"


#define glVertexAttribBinding_   \
    ((void (*)(GLuint attribindex, GLuint bindingindex))  \
    GLES_ENTRY_PTR(glVertexAttribBinding_Idx))


GL_APICALL void GL_APIENTRY
glVertexAttribBinding (GLuint attribindex, GLuint bindingindex)
{
    prepare_gles_tracer ();
    glVertexAttribBinding_ (attribindex, bindingindex);
    fprintf (g_log_fp, "glVertexAttribBinding(%d, %d);\n", attribindex, bindingindex);
}
