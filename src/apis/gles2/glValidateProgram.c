#include <stdio.h>
#include "GLEStrace.h"

#define glValidateProgram_   \
    ((void (*)(GLuint program))  \
    GLES_ENTRY_PTR(glValidateProgram_Idx))



GL_APICALL void GL_APIENTRY
glValidateProgram (GLuint program)
{
    prepare_gles_tracer ();

    glValidateProgram_ (program);

    fprintf (g_log_fp, "glValidateProgram(%d);\n", program);
}

