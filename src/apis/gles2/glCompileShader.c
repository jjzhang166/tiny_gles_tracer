#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glCompileShader_   \
    ((void (*)(GLuint shader)) \
    GLES_ENTRY_PTR(glCompileShader_Idx))


GL_APICALL void GL_APIENTRY
glCompileShader (GLuint shader)
{
    prepare_gles_tracer ();

    glCompileShader_ (shader);

    fprintf (g_log_fp, "glCompileShader(%d);\n", shader);
}
