#include <stdio.h>
#include "GLEStrace.h"


#define glColorMask_   \
    ((void (*)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha))  \
    GLES_ENTRY_PTR(glColorMask_Idx))


GL_APICALL void GL_APIENTRY
glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    prepare_gles_tracer ();

    glColorMask_ (red, green, blue, alpha);

    fprintf (g_log_fp, "glColorMask(%d, %d, %d, %d)\n", red, green, blue, alpha);
}

