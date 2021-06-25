#include <stdio.h>
#include "GLEStrace.h"


#define glPopDebugGroup_   \
    ((void (*)(void))  \
    GLES_ENTRY_PTR(glPopDebugGroup_Idx))


GL_APICALL void GL_APIENTRY
glPopDebugGroup (void)
{
    prepare_gles_tracer ();

    glPopDebugGroup_ ();

    fprintf (g_log_fp, "glPopDebugGroup();\n");
}

