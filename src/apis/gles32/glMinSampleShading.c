#include <stdio.h>
#include "GLEStrace.h"


#define glMinSampleShading_   \
    ((void (*)(GLfloat value))  \
    GLES_ENTRY_PTR(glMinSampleShading_Idx))


GL_APICALL void GL_APIENTRY
glMinSampleShading (GLfloat value)
{
    prepare_gles_tracer ();

    glMinSampleShading_ (value);

    fprintf (g_log_fp, "glMinSampleShading(%f);\n", value);
}

