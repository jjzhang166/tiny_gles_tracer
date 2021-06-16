#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glCreateProgram_   \
    ((GLuint (*)(void)) \
    GLES_ENTRY_PTR(glCreateProgram_Idx))


GL_APICALL GLuint GL_APIENTRY
glCreateProgram (void)
{
    prepare_gles_tracer ();

    GLuint ret = glCreateProgram_ ();

    fprintf (g_log_fp, "glCreateProgram(); // ret=%d\n", ret);

    return ret;
}
