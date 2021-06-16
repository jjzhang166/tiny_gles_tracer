#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glReleaseShaderCompiler_   \
    ((void (*)()) \
    GLES_ENTRY_PTR(glReleaseShaderCompiler_Idx))


GL_APICALL void GL_APIENTRY
glReleaseShaderCompiler (void)
{
    prepare_gles_tracer ();

    glReleaseShaderCompiler_ ();

    fprintf (g_log_fp, "glReleaseShaderCompiler();\n");
}
