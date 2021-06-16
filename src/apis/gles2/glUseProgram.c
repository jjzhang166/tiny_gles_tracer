#include <stdio.h>
#include "GLEStrace.h"

#define glUseProgram_   \
    ((void (*)(GLuint program))  \
    GLES_ENTRY_PTR(glUseProgram_Idx))



GL_APICALL void GL_APIENTRY
glUseProgram (GLuint program)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glUseProgram(%d);\n", program);
    glUseProgram_ (program);
}

