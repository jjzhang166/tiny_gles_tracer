#include <stdio.h>
#include "GLEStrace.h"


#define glGetActiveUniform_   \
    ((void (*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name))  \
    GLES_ENTRY_PTR(glGetActiveUniform_Idx))


GL_APICALL void GL_APIENTRY
glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
    prepare_gles_tracer ();

    glGetActiveUniform_ (program, index, bufSize, length, size, type, name);

    fprintf (g_log_fp, "glGetActiveUniform(%d, %d, %d, %p, %p, %p, %p);\n",
             program, index, bufSize, length, size, type, name);
}

