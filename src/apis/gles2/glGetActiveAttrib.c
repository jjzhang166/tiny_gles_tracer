#include <stdio.h>
#include "GLEStrace.h"


#define glGetActiveAttrib_   \
    ((void (*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name))  \
    GLES_ENTRY_PTR(glGetActiveAttrib_Idx))


GL_APICALL void GL_APIENTRY
glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
    prepare_gles_tracer ();

    glGetActiveAttrib_ (program, index, bufSize, length, size, type, name);

    fprintf (g_log_fp, "glGetActiveAttrib(%d, %d, %d, %p, %p, %p, %p);\n",
             program, index, bufSize, length, size, type, name);
}

