#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glBindAttribLocation_   \
    ((void (*)(GLuint program, GLuint index, const GLchar *name)) \
    GLES_ENTRY_PTR(glBindAttribLocation_Idx))


GL_APICALL void GL_APIENTRY
glBindAttribLocation (GLuint program, GLuint index, const GLchar *name)
{
    prepare_gles_tracer ();

    glBindAttribLocation_ (program, index, name);

    fprintf (g_log_fp, "glBindAttribLocation(%d, %d, \"%s\");\n", program, index, name);
}
