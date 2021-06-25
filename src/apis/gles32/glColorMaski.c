#include <stdio.h>
#include "GLEStrace.h"


#define glColorMaski_   \
    ((void (*)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a))  \
    GLES_ENTRY_PTR(glColorMaski_Idx))


GL_APICALL void GL_APIENTRY
glColorMaski (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
    prepare_gles_tracer ();

    glColorMaski_ (index, r, g, b, a);

    fprintf (g_log_fp, "glColorMaski(%d, %d, %d, %d, %d)\n", index, r, g, b, a);
}

