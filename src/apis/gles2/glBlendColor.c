#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glBlendColor_   \
    ((void (*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)) \
    GLES_ENTRY_PTR(glBlendColor_Idx))


GL_APICALL void GL_APIENTRY
glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    prepare_gles_tracer ();

    glBlendColor_ (red, green, blue, alpha);

    fprintf (g_log_fp, "glBlendColor(%f, %f, %f, %f);\n", red, green, blue, alpha);
}
