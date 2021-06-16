#include <stdio.h>
#include "GLEStrace.h"


#define glGetBooleani_v_   \
    ((void (*)(GLenum target, GLuint index, GLboolean *data))  \
    GLES_ENTRY_PTR(glGetBooleani_v_Idx))


GL_APICALL void GL_APIENTRY
glGetBooleani_v (GLenum target, GLuint index, GLboolean *data)
{
    prepare_gles_tracer ();

    glGetBooleani_v_ (target, index, data);

    fprintf (g_log_fp, "glGetBooleani_v(%d, %d, %p);", target, index, data);
    if (data) fprintf (g_log_fp, " // data = %d\n", *data);
}

