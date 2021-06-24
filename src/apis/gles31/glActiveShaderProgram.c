#include <stdio.h>
#include "GLEStrace.h"

#define glActiveShaderProgram_   \
    ((void (*)(GLuint pipeline, GLuint program))  \
    GLES_ENTRY_PTR(glActiveShaderProgram_Idx))



GL_APICALL void GL_APIENTRY
glActiveShaderProgram (GLuint pipeline, GLuint program)
{
    prepare_gles_tracer ();

    glActiveShaderProgram_ (pipeline, program);

    fprintf (g_log_fp, "glActiveShaderProgram(%d, %d);\n", pipeline, program);
}

