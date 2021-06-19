#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glIsSync_         \
    ((GLboolean (*)(GLsync sync))   \
    GLES_ENTRY_PTR(glIsSync_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsSync (GLsync sync)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsSync_ (sync);

    fprintf (g_log_fp, "glIsSync(%p); // ret=%d\n", sync, ret);

    return ret;
}

