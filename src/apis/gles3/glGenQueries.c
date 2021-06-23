#include <stdio.h>
#include "GLEStrace.h"


#define glGenQueries_   \
    ((void (*)(GLsizei n, GLuint *ids))  \
    GLES_ENTRY_PTR(glGenQueries_Idx))


GL_APICALL void GL_APIENTRY
glGenQueries (GLsizei n, GLuint *ids)
{
    prepare_gles_tracer ();

    glGenQueries_ (n, ids);

    fprintf (g_log_fp, "glGenQueries(%d, %p);", n, ids);
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

