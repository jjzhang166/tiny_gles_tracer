#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteRenderbuffers_   \
    ((void (*)(GLsizei n, const GLuint *renderbuffers))  \
    GLES_ENTRY_PTR(glDeleteRenderbuffers_Idx))


GL_APICALL void GL_APIENTRY
glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers)
{
    prepare_gles_tracer ();

    glDeleteRenderbuffers_ (n, renderbuffers);

    fprintf (g_log_fp, "glDeleteRenderbuffers(%d, %p);", n, renderbuffers);
    fprintf (g_log_fp, " // ");
    if (renderbuffers)
    {
        for (int i = 0; i < n; i ++)
        {
            fprintf (g_log_fp, "%d,", renderbuffers[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

