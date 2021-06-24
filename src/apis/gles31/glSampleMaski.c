#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glSampleMaski_   \
    ((void (*)(GLuint maskNumber, GLbitfield mask)) \
    GLES_ENTRY_PTR(glSampleMaski_Idx))


GL_APICALL void GL_APIENTRY
glSampleMaski (GLuint maskNumber, GLbitfield mask)
{
    prepare_gles_tracer ();

    glSampleMaski_ (maskNumber, mask);

    fprintf (g_log_fp, "glSampleMaski(%d, %d);\n", maskNumber, mask);
}

