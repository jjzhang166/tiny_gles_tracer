#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteVertexArrays_   \
    ((void (*)(GLsizei n, const GLuint *arrays))  \
    GLES_ENTRY_PTR(glDeleteVertexArrays_Idx))


GL_APICALL void GL_APIENTRY
glDeleteVertexArrays (GLsizei n, const GLuint *arrays)
{
    prepare_gles_tracer ();

    glDeleteVertexArrays_ (n, arrays);

    fprintf (g_log_fp, "glDeleteVertexArrays(%d, %p);", n, arrays);
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

