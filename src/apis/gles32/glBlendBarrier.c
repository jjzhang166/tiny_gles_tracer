#include <stdio.h>
#include "GLEStrace.h"


#define glBlendBarrier_   \
    ((void (*)(void))  \
    GLES_ENTRY_PTR(glBlendBarrier_Idx))


GL_APICALL void GL_APIENTRY
glBlendBarrier (void)
{
    prepare_gles_tracer ();

    glBlendBarrier_ ();

    fprintf (g_log_fp, "glBlendBarrier();\n");
}

