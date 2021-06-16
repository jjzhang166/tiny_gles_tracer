#include <stdio.h>
#include "GLEStrace.h"


#define glGenBuffers_   \
    ((void (*)(GLsizei n, GLuint *buffers))  \
    GLES_ENTRY_PTR(glGenBuffers_Idx))


GL_APICALL void GL_APIENTRY
glGenBuffers (GLsizei n, GLuint *buffers)
{
    prepare_gles_tracer ();

    glGenBuffers_ (n, buffers);

    fprintf (g_log_fp, "glGenBuffers(%d, %p);", n, buffers);
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

