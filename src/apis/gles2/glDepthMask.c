#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glDepthMask_   \
    ((void (*)(GLboolean flag)) \
    GLES_ENTRY_PTR(glDepthMask_Idx))


GL_APICALL void GL_APIENTRY
glDepthMask (GLboolean flag)
{
    prepare_gles_tracer ();

    glDepthMask_ (flag);

    fprintf (g_log_fp, "glDepthMask(%d);\n", flag);
}
