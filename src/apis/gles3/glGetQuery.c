#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glGetQueryiv_   \
    ((void (*)(GLenum target, GLenum pname, GLint *params)) \
    GLES_ENTRY_PTR(glGetQueryiv_Idx))


GL_APICALL void GL_APIENTRY
glGetQueryiv (GLenum target, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glGetQueryiv(%d, %d, %p);\n", target, pname, params);

    glGetQueryiv_ (target, pname, params);
}
