#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glFinish_   \
    ((void (*)(void)) \
    GLES_ENTRY_PTR(glFinish_Idx))


GL_APICALL void GL_APIENTRY
glFinish (void)
{
    prepare_gles_tracer ();

    glFinish_ ();

    fprintf (g_log_fp, "glFinish();\n");
}
