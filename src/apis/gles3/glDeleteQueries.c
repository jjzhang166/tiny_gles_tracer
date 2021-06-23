#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteQueries_   \
    ((void (*)(GLsizei n, const GLuint *ids))  \
    GLES_ENTRY_PTR(glDeleteQueries_Idx))


GL_APICALL void GL_APIENTRY
glDeleteQueries (GLsizei n, const GLuint *ids)
{
    prepare_gles_tracer ();

    glDeleteQueries_ (n, ids);

    fprintf (g_log_fp, "glDeleteQueries(%d, %p);", n, ids);
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

