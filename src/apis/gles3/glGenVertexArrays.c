#include <stdio.h>
#include "GLEStrace.h"


#define glGenVertexArrays_   \
    ((void (*)(GLsizei n, GLuint *arrays))  \
    GLES_ENTRY_PTR(glGenVertexArrays_Idx))


GL_APICALL void GL_APIENTRY
glGenVertexArrays (GLsizei n, GLuint *arrays)
{
    prepare_gles_tracer ();

    glGenVertexArrays_ (n, arrays);

    fprintf (g_log_fp, "glGenVertexArrays(%d, %p);", n, arrays);
    fprintf (g_log_fp, " // ");
    if (arrays)
    {
        for (int i = 0; i < n; i ++)
        {
            fprintf (g_log_fp, "%d,", arrays[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

