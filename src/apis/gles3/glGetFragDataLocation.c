#include <stdio.h>
#include "GLEStrace.h"


#define glGetFragDataLocation_   \
    ((GLint (*)(GLuint program, const GLchar *name))  \
    GLES_ENTRY_PTR(glGetFragDataLocation_Idx))


GL_APICALL GLint GL_APIENTRY
glGetFragDataLocation (GLuint program, const GLchar *name)
{
    prepare_gles_tracer ();

    GLint ret = glGetFragDataLocation_ (program, name);

    fprintf (g_log_fp, "glGetFragDataLocation(%d, \"%s\"); // ret=%d\n", 
             program, name, ret);

    return ret;
}

