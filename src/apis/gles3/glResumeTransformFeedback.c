#include <stdio.h>
#include "GLEStrace.h"


#define glResumeTransformFeedback_   \
    ((void (*)(void))  \
    GLES_ENTRY_PTR(glResumeTransformFeedback_Idx))


GL_APICALL void GL_APIENTRY
glResumeTransformFeedback (void)
{
    prepare_gles_tracer ();

    glResumeTransformFeedback_ ();

    fprintf (g_log_fp, "glResumeTransformFeedback();\n");
}

