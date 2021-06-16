#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteTextures_   \
    ((void (*)(GLsizei n, const GLuint *textures))  \
    GLES_ENTRY_PTR(glDeleteTextures_Idx))


GL_APICALL void GL_APIENTRY
glDeleteTextures (GLsizei n, const GLuint *textures)
{
    prepare_gles_tracer ();

    glDeleteTextures_ (n, textures);

    fprintf (g_log_fp, "glDeleteTextures(%d, %p);", n, textures);
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

