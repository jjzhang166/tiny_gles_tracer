#include <stdio.h>
#include "GLEStrace.h"


#define glGetnUniformfv_   \
    ((void (*)(GLuint program, GLint location, GLsizei bufSize, GLfloat *params))  \
    GLES_ENTRY_PTR(glGetnUniformfv_Idx))

#define glGetnUniformiv_   \
    ((void (*)(GLuint program, GLint location, GLsizei bufSize, GLint *params))  \
    GLES_ENTRY_PTR(glGetnUniformiv_Idx))

#define glGetnUniformuiv_   \
    ((void (*)(GLuint program, GLint location, GLsizei bufSize, GLuint *params))  \
    GLES_ENTRY_PTR(glGetnUniformuiv_Idx))


GL_APICALL void GL_APIENTRY
glGetnUniformfv (GLuint program, GLint location, GLsizei bufSize, GLfloat *params)
{
    prepare_gles_tracer ();

    glGetnUniformfv_ (program, location, bufSize, params);

    fprintf (g_log_fp, "glGetnUniformfv(%d, %d, %d, %p);", 
             program, location, bufSize, params);
    if (params) fprintf (g_log_fp, " // params = %f\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetnUniformiv (GLuint program, GLint location, GLsizei bufSize, GLint *params)
{
    prepare_gles_tracer ();

    glGetnUniformiv_ (program, location, bufSize, params);

    fprintf (g_log_fp, "glGetnUniformiv(%d, %d, %d, %p);", 
             program, location, bufSize, params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetnUniformuiv (GLuint program, GLint location, GLsizei bufSize, GLuint *params)
{
    prepare_gles_tracer ();

    glGetnUniformuiv_ (program, location, bufSize, params);

    fprintf (g_log_fp, "glGetnUniformuiv(%d, %d, %d, %p);", 
             program, location, bufSize, params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}
