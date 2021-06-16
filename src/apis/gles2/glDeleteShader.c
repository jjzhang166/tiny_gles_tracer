#include <stdio.h>
#include "GLEStrace.h"


#define glDeleteShader_   \
    ((void (*)(GLuint shader))  \
    GLES_ENTRY_PTR(glDeleteShader_Idx))


GL_APICALL void GL_APIENTRY
glDeleteShader (GLuint shader)
{
    prepare_gles_tracer ();

    glDeleteShader_ (shader);

    fprintf (g_log_fp, "glDeleteShader(%d);\n", shader);
}

