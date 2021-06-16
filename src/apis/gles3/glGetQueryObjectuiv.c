#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glGetQueryObjectuiv_   \
    ((void (*)(GLuint id, GLenum pname, GLuint *params)) \
    GLES_ENTRY_PTR(glGetQueryObjectuiv_Idx))


GL_APICALL void GL_APIENTRY
glGetQueryObjectuiv (GLuint id, GLenum pname, GLuint *params)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glGetQueryObjectuiv(%d, %d, %p);\n", id, pname, params);

    glGetQueryObjectuiv_ (id, pname, params);
}
