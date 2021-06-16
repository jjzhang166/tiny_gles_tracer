#include <stdio.h>
#include "GLEStrace.h"


#define glGenTextures_   \
    ((void (*)(GLsizei n, GLuint *textures))  \
    GLES_ENTRY_PTR(glGenTextures_Idx))


GL_APICALL void GL_APIENTRY
glGenTextures (GLsizei n, GLuint *textures)
{
    prepare_gles_tracer ();

    glGenTextures_ (n, textures);

    fprintf (g_log_fp, "glGenTextures(%d, %p);", n, textures);
    fprintf (g_log_fp, " // ");
    if (textures)
    {
        for (int i = 0; i < n; i ++)
        {
            fprintf (g_log_fp, "%d,", textures[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

