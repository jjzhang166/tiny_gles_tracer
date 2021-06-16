#include <stdio.h>
#include "GLEStrace.h"

#define glViewport_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height))  \
    GLES_ENTRY_PTR(glViewport_Idx))



GL_APICALL void GL_APIENTRY
glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glViewport(%d, %d, %d, %d);\n", x, y, width, height);
    glViewport_ (x, y, width, height);
}

