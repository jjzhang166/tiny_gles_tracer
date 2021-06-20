#include <stdio.h>
#include "GLEStrace.h"


#define glGenSamplers_   \
    ((void (*)(GLsizei count, GLuint *samplers))  \
    GLES_ENTRY_PTR(glGenSamplers_Idx))


GL_APICALL void GL_APIENTRY
glGenSamplers (GLsizei count, GLuint *samplers)
{
    prepare_gles_tracer ();

    glGenSamplers_ (count, samplers);

    fprintf (g_log_fp, "glGenSamplers(%d, %p);", count, samplers);
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

