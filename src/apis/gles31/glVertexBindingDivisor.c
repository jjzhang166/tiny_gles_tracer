#include <stdio.h>
#include "GLEStrace.h"


#define glVertexBindingDivisor_   \
    ((void (*)(GLuint bindingindex, GLuint divisor))  \
    GLES_ENTRY_PTR(glVertexBindingDivisor_Idx))


GL_APICALL void GL_APIENTRY
glVertexBindingDivisor (GLuint bindingindex, GLuint divisor)
{
    prepare_gles_tracer ();
    glVertexBindingDivisor_ (bindingindex, divisor);
    fprintf (g_log_fp, "glVertexBindingDivisor(%d, %d);\n", bindingindex, divisor);
}
