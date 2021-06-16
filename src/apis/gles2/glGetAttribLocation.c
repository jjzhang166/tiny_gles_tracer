#include <stdio.h>
#include "GLEStrace.h"


#define glGetAttribLocation_   \
    ((GLint (*)(GLuint program, const GLchar *name))  \
    GLES_ENTRY_PTR(glGetAttribLocation_Idx))


GL_APICALL GLint GL_APIENTRY
glGetAttribLocation (GLuint program, const GLchar *name)
{
    prepare_gles_tracer ();

    GLint ret = glGetAttribLocation_ (program, name);

    fprintf (g_log_fp, "glGetAttribLocation(%d, \"%s\"); // ret=%d\n", 
             program, name, ret);

    return ret;
}

