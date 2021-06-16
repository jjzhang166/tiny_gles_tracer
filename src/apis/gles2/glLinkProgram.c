#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glLinkProgram_   \
    ((void (*)(GLuint program)) \
    GLES_ENTRY_PTR(glLinkProgram_Idx))


GL_APICALL void GL_APIENTRY
glLinkProgram (GLuint program)
{
    prepare_gles_tracer ();

    glLinkProgram_ (program);

    fprintf (g_log_fp, "glLinkProgram(%d);\n", program);
}
