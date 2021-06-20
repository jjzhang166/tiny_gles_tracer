#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteSamplers_   \
    ((void (*)(GLsizei count, const GLuint *samplers))  \
    GLES_ENTRY_PTR(glDeleteSamplers_Idx))


GL_APICALL void GL_APIENTRY
glDeleteSamplers (GLsizei count, const GLuint *samplers)
{
    prepare_gles_tracer ();

    glDeleteSamplers_ (count, samplers);

    fprintf (g_log_fp, "glDeleteSamplers(%d, %p);", count, samplers);
    fprintf (g_log_fp, " // ");
    if (samplers)
    {
        for (int i = 0; i < count; i ++)
        {
            fprintf (g_log_fp, "%d,", samplers[i]);
        }
    }
    fprintf (g_log_fp, "\n");
}

