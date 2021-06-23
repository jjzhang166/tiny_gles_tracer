#include <stdio.h>
#include "GLEStrace.h"


#define glIsVertexArray_   \
    ((GLboolean (*)(GLuint array))  \
    GLES_ENTRY_PTR(glIsVertexArray_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsVertexArray (GLuint array)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsVertexArray_ (array);

    fprintf (g_log_fp, "glIsVertexArray(%d); // ret=%d\n", array, ret);

    return ret;
}

