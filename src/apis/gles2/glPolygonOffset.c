#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glPolygonOffset_   \
    ((void (*)(GLfloat factor, GLfloat units)) \
    GLES_ENTRY_PTR(glPolygonOffset_Idx))


GL_APICALL void GL_APIENTRY
glPolygonOffset (GLfloat factor, GLfloat units)
{
    prepare_gles_tracer ();

    glPolygonOffset_ (factor, units);

    fprintf (g_log_fp, "glPolygonOffset(%f, %f);\n", factor, units);
}
