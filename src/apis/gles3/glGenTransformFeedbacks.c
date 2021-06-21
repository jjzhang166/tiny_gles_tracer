#include <stdio.h>
#include "GLEStrace.h"


#define glGenTransformFeedbacks_   \
    ((void (*)(GLsizei n, GLuint *ids))  \
    GLES_ENTRY_PTR(glGenTransformFeedbacks_Idx))


GL_APICALL void GL_APIENTRY
glGenTransformFeedbacks (GLsizei n, GLuint *ids)
{
    prepare_gles_tracer ();

    glGenTransformFeedbacks_ (n, ids);

    fprintf (g_log_fp, "glGenTransformFeedbacks(%d, %p);", n, ids);
    fprintf (g_log_fp, " // ");
    if (ids)
    {
        for (int i = 0; i < n; i ++)
        {
            fprintf (g_log_fp, "%d,", ids[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

