#include <stdio.h>
#include "GLEStrace.h"


#define glGetAttachedShaders_   \
    ((void (*)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders))  \
    GLES_ENTRY_PTR(glGetAttachedShaders_Idx))


GL_APICALL void GL_APIENTRY
glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
{
    prepare_gles_tracer ();

    glGetAttachedShaders_ (program, maxCount, count, shaders);

    fprintf (g_log_fp, "glGetAttachedShaders(%d, %d, %p, %p);\n",
             program, maxCount, count, shaders);
}

