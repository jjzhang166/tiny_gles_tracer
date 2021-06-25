#include <stdio.h>
#include "GLEStrace.h"


#define glDebugMessageCallback_   \
    ((void (*)(GLDEBUGPROC callback, const void *userParam))  \
    GLES_ENTRY_PTR(glDebugMessageCallback_Idx))


GL_APICALL void GL_APIENTRY
glDebugMessageCallback (GLDEBUGPROC callback, const void *userParam)
{
    prepare_gles_tracer ();

    glDebugMessageCallback_ (callback, userParam);

    fprintf (g_log_fp, "glDebugMessageCallback(%p, %p);\n", callback, userParam);
}

