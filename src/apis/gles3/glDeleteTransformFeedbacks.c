#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteTransformFeedbacks_   \
    ((void (*)(GLsizei n, const GLuint *ids))  \
    GLES_ENTRY_PTR(glDeleteTransformFeedbacks_Idx))


GL_APICALL void GL_APIENTRY
glDeleteTransformFeedbacks (GLsizei n, const GLuint *ids)
{
    prepare_gles_tracer ();

    glDeleteTransformFeedbacks_ (n, ids);

    fprintf (g_log_fp, "glDeleteTransformFeedbacks(%d, %p);", n, ids);
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

