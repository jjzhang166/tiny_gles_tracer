#include <stdio.h>
#include "GLEStrace.h"

#define glScissor_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height))  \
    GLES_ENTRY_PTR(glScissor_Idx))



GL_APICALL void GL_APIENTRY
glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
    prepare_gles_tracer ();

    glScissor_ (x, y, width, height);

    fprintf (g_log_fp, "glScissor(%d, %d, %d, %d);\n", x, y, width, height);
}

