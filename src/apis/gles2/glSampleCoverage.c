#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glSampleCoverage_   \
    ((void (*)(GLfloat value, GLboolean invert)) \
    GLES_ENTRY_PTR(glSampleCoverage_Idx))


GL_APICALL void GL_APIENTRY
glSampleCoverage (GLfloat value, GLboolean invert)
{
    prepare_gles_tracer ();

    glSampleCoverage_ (value, invert);

    fprintf (g_log_fp, "glSampleCoverage(%f, %d);\n", value, invert);
}

