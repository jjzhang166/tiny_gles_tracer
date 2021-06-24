#include <stdio.h>
#include "GLEStrace.h"


#define glMemoryBarrierByRegion_   \
    ((void (*)(GLbitfield barriers))  \
    GLES_ENTRY_PTR(glMemoryBarrierByRegion_Idx))


GL_APICALL void GL_APIENTRY
glMemoryBarrierByRegion (GLbitfield barriers)
{
    prepare_gles_tracer ();

    glMemoryBarrierByRegion_ (barriers);

    fprintf (g_log_fp, "glMemoryBarrierByRegion(0x%x);\n", barriers);
}

