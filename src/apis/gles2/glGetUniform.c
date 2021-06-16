#include <stdio.h>
#include "GLEStrace.h"


#define glGetUniformfv_   \
    ((void (*)(GLuint program, GLint location, GLfloat *params))  \
    GLES_ENTRY_PTR(glGetUniformfv_Idx))

#define glGetUniformiv_   \
    ((void (*)(GLuint program, GLint location, GLint *params))  \
    GLES_ENTRY_PTR(glGetUniformiv_Idx))


GL_APICALL void GL_APIENTRY
glGetUniformfv (GLuint program, GLint location, GLfloat *params)
{
    prepare_gles_tracer ();

    glGetUniformfv_ (program, location, params);

    fprintf (g_log_fp, "glGetUniformfv(%d, %d, %p);", 
             program, location, params);
    if (params) fprintf (g_log_fp, " // params = %f\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetUniformiv (GLuint program, GLint location, GLint *params)
{
    prepare_gles_tracer ();

    glGetUniformiv_ (program, location, params);

    fprintf (g_log_fp, "glGetUniformiv(%d, %d, %p);", 
             program, location, params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}
