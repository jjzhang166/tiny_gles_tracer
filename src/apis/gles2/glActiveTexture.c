#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glActiveTexture_   \
    ((void (*)(GLenum texture)) \
    GLES_ENTRY_PTR(glActiveTexture_Idx))


GL_APICALL void GL_APIENTRY
glActiveTexture (GLenum texture)
{
    prepare_gles_tracer ();

    glActiveTexture_ (texture);

    fprintf (g_log_fp, "glActiveTexture(GL_TEXTURE%d);\n", texture - GL_TEXTURE0);
}
