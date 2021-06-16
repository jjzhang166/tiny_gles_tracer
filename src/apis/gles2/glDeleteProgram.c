#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteProgram_   \
    ((void (*)(GLuint program))  \
    GLES_ENTRY_PTR(glDeleteProgram_Idx))


GL_APICALL void GL_APIENTRY
glDeleteProgram (GLuint program)
{
    prepare_gles_tracer ();

    glDeleteProgram_ (program);

    fprintf (g_log_fp, "glDeleteProgram(%d);\n", program);
}

