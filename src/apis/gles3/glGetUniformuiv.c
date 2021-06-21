#include <stdio.h>
#include "GLEStrace.h"


#define glGetUniformuiv_   \
    ((void (*)(GLuint program, GLint location, GLuint *params))  \
    GLES_ENTRY_PTR(glGetUniformuiv_Idx))


GL_APICALL void GL_APIENTRY
glGetUniformuiv (GLuint program, GLint location, GLuint *params)
{
    prepare_gles_tracer ();

    glGetUniformuiv_ (program, location, params);

    fprintf (g_log_fp, "glGetUniformuiv(%d, %d, %p); // ",
             program, location, params);
    if (params) fprintf (g_log_fp, "params=%d\n", *params);
}

