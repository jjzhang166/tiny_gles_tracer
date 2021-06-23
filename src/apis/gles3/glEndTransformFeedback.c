#include <stdio.h>
#include "GLEStrace.h"


#define glEndTransformFeedback_   \
    ((void (*)(void))  \
    GLES_ENTRY_PTR(glEndTransformFeedback_Idx))


GL_APICALL void GL_APIENTRY
glEndTransformFeedback (void)
{
    prepare_gles_tracer ();

    glEndTransformFeedback_ ();

    fprintf (g_log_fp, "glEndTransformFeedback();\n");
}

