#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteFramebuffers_   \
    ((void (*)(GLsizei n, const GLuint *framebuffers))  \
    GLES_ENTRY_PTR(glDeleteFramebuffers_Idx))


GL_APICALL void GL_APIENTRY
glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers)
{
    prepare_gles_tracer ();

    glDeleteFramebuffers_ (n, framebuffers);

    fprintf (g_log_fp, "glDeleteFramebuffers(%d, %p);", n, framebuffers);
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

