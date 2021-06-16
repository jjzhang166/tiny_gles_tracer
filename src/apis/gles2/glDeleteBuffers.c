#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteBuffers_   \
    ((void (*)(GLsizei n, const GLuint *buffers))  \
    GLES_ENTRY_PTR(glDeleteBuffers_Idx))


GL_APICALL void GL_APIENTRY
glDeleteBuffers (GLsizei n, const GLuint *buffers)
{
    prepare_gles_tracer ();

    glDeleteBuffers_ (n, buffers);

    fprintf (g_log_fp, "glDeleteBuffers(%d, %p);", n, buffers);
    fprintf (g_log_fp, " // ");
    if (buffers)
    {
        for (int i = 0; i < n; i ++)
        {
            fprintf (g_log_fp, "%d,", buffers[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

