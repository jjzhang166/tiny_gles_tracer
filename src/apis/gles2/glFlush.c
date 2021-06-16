#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glFlush_   \
    ((void (*)(void)) \
    GLES_ENTRY_PTR(glFlush_Idx))


GL_APICALL void GL_APIENTRY
glFlush (void)
{
    prepare_gles_tracer ();

    glFlush_ ();

    fprintf (g_log_fp, "glFlush();\n");
}
