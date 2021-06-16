#include <stdio.h>
#include "GLEStrace.h"


#define glGetUniformLocation_   \
    ((GLint (*)(GLuint program, const GLchar *name))  \
    GLES_ENTRY_PTR(glGetUniformLocation_Idx))


GL_APICALL GLint GL_APIENTRY
glGetUniformLocation (GLuint program, const GLchar *name)
{
    prepare_gles_tracer ();

    GLint ret = glGetUniformLocation_ (program, name);

    fprintf (g_log_fp, "glGetUniformLocation(%d, \"%s\"); // ret=%d\n", 
             program, name, ret);

    return ret;
}

