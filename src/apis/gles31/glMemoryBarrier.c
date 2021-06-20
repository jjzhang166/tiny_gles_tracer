#include <stdio.h>
#include "GLEStrace.h"


#define glMemoryBarrier_   \
    ((void (*)(GLbitfield barriers))  \
    GLES_ENTRY_PTR(glMemoryBarrier_Idx))


GL_APICALL void GL_APIENTRY
glMemoryBarrier (GLbitfield barriers)
{
    prepare_gles_tracer ();

    glMemoryBarrier_ (barriers);

    fprintf (g_log_fp, "glMemoryBarrier(0x%x);\n", barriers);
}

