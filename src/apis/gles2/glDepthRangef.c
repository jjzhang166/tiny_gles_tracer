#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glDepthRangef_   \
    ((void (*)(GLfloat n, GLfloat f)) \
    GLES_ENTRY_PTR(glDepthRangef_Idx))


GL_APICALL void GL_APIENTRY
glDepthRangef (GLfloat n, GLfloat f)
{
    prepare_gles_tracer ();

    glDepthRangef_ (n, f);

    fprintf (g_log_fp, "glDepthRangef(%f, %f);\n", n, f);
}
