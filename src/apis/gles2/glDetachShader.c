#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glDetachShader_   \
    ((void (*)(GLuint program, GLuint shader)) \
    GLES_ENTRY_PTR(glDetachShader_Idx))


GL_APICALL void GL_APIENTRY
glDetachShader (GLuint program, GLuint shader)
{
    prepare_gles_tracer ();

    glDetachShader_ (program, shader);

    fprintf (g_log_fp, "glDetachShader(%d, %d);\n", program, shader);
}
