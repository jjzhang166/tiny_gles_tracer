#include <stdio.h>
#include "GLEStrace.h"


#define glGenFramebuffers_   \
    ((void (*)(GLsizei n, GLuint *framebuffers))  \
    GLES_ENTRY_PTR(glGenFramebuffers_Idx))


GL_APICALL void GL_APIENTRY
glGenFramebuffers (GLsizei n, GLuint *framebuffers)
{
    prepare_gles_tracer ();

    glGenFramebuffers_ (n, framebuffers);

    fprintf (g_log_fp, "glGenFramebuffers(%d, %p);", n, framebuffers);
    fprintf (g_log_fp, " // ");
    if (framebuffers)
    {
        for (int i = 0; i < n; i ++)
        {
            fprintf (g_log_fp, "%d,", framebuffers[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

