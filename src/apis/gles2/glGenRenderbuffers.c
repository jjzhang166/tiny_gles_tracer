#include <stdio.h>
#include "GLEStrace.h"


#define glGenRenderbuffers_   \
    ((void (*)(GLsizei n, GLuint *renderbuffers))  \
    GLES_ENTRY_PTR(glGenRenderbuffers_Idx))


GL_APICALL void GL_APIENTRY
glGenRenderbuffers (GLsizei n, GLuint *renderbuffers)
{
    prepare_gles_tracer ();

    glGenRenderbuffers_ (n, renderbuffers);

    fprintf (g_log_fp, "glGenRenderbuffers(%d, %p);", n, renderbuffers);
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

