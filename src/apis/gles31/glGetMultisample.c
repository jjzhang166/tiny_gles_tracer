#include <stdio.h>
#include "GLEStrace.h"


#define glGetMultisamplefv_   \
    ((void (*)(GLenum pname, GLuint index, GLfloat *val))  \
    GLES_ENTRY_PTR(glGetMultisamplefv_Idx))


GL_APICALL void GL_APIENTRY
glGetMultisamplefv (GLenum pname, GLuint index, GLfloat *val)
{
    prepare_gles_tracer ();

    glGetMultisamplefv_ (pname, index, val);

    fprintf (g_log_fp, "glGetMultisamplefv(%d, %d, %p);", pname, index, val);
    if (val) fprintf (g_log_fp, " // val = %f\n", *val);
}

