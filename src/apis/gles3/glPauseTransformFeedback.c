#include <stdio.h>
#include "GLEStrace.h"


#define glPauseTransformFeedback_   \
    ((void (*)(void))  \
    GLES_ENTRY_PTR(glPauseTransformFeedback_Idx))


GL_APICALL void GL_APIENTRY
glPauseTransformFeedback (void)
{
    prepare_gles_tracer ();

    glPauseTransformFeedback_ ();

    fprintf (g_log_fp, "glPauseTransformFeedback();\n");
}

