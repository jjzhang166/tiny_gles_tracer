#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glDispatchComputeIndirect_         \
    ((void (*)(GLintptr indirect))   \
    GLES_ENTRY_PTR(glDispatchComputeIndirect_Idx))


GL_APICALL void GL_APIENTRY
glDispatchComputeIndirect (GLintptr indirect)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glDispatchComputeIndirect(%ld);\n", indirect);

    glDispatchComputeIndirect_ (indirect);
}

