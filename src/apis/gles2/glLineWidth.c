#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glLineWidth_   \
    ((void (*)(GLfloat width)) \
    GLES_ENTRY_PTR(glLineWidth_Idx))


GL_APICALL void GL_APIENTRY
glLineWidth (GLfloat width)
{
    prepare_gles_tracer ();

    glLineWidth_ (width);

    fprintf (g_log_fp, "glLineWidth(%f);\n", width);
}
