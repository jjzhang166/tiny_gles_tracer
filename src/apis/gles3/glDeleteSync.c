#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glDeleteSync_         \
    ((void (*)(GLsync sync))   \
    GLES_ENTRY_PTR(glDeleteSync_Idx))


GL_APICALL void GL_APIENTRY
glDeleteSync (GLsync sync)
{
    prepare_gles_tracer ();

    glDeleteSync_ (sync);

    fprintf (g_log_fp, "glDeleteSync(%p);\n", sync);
}

