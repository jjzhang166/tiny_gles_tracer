#include <stdio.h>
#include "GLEStrace.h"

#define glShaderSource_         \
    ((void (*)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length))   \
    GLES_ENTRY_PTR(glShaderSource_Idx))


GL_APICALL void GL_APIENTRY
glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glShaderSource(%d, %d, %p, %p);\n", shader, count, string, length);
    glShaderSource_ (shader, count, string, length);

    for (int i = 0; i < count; i ++)
    {
        fprintf (g_log_fp, "-----------------------------\n");
        fprintf (g_log_fp, "%s\n", string[i]);
        fprintf (g_log_fp, "-----------------------------\n\n");
    }
}

