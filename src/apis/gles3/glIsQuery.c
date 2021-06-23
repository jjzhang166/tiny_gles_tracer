#include <stdio.h>
#include "GLEStrace.h"


#define glIsQuery_   \
    ((GLboolean (*)(GLuint id))  \
    GLES_ENTRY_PTR(glIsQuery_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsQuery (GLuint id)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsQuery_ (id);

    fprintf (g_log_fp, "glIsQuery(%d); // ret=%d\n", id, ret);

    return ret;
}

