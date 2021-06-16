#include <stdio.h>
#include "GLEStrace.h"


#define glGetInternalformativ_   \
    ((void (*)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params))  \
    GLES_ENTRY_PTR(glGetInternalformativ_Idx))


GL_APICALL void GL_APIENTRY
glGetInternalformativ (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
{
    prepare_gles_tracer ();

    glGetInternalformativ_ (target, internalformat, pname, bufSize, params);

    fprintf (g_log_fp, "glGetInternalformativ(%d, %d, %d, %d, %p);",
             target, internalformat, pname, bufSize, params);
    if (params) fprintf (g_log_fp, " // data = %d\n", *params);
}

