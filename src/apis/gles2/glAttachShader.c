#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glAttachShader_   \
    ((void (*)(GLuint program, GLuint shader)) \
    GLES_ENTRY_PTR(glAttachShader_Idx))


GL_APICALL void GL_APIENTRY
glAttachShader (GLuint program, GLuint shader)
{
    prepare_gles_tracer ();

    glAttachShader_ (program, shader);

    fprintf (g_log_fp, "glAttachShader(%d, %d);\n", program, shader);
}
