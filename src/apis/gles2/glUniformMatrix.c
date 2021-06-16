#include <stdio.h>
#include "GLEStrace.h"

#define glUniformMatrix2fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix2fv_Idx))

#define glUniformMatrix3fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix3fv_Idx))

#define glUniformMatrix4fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix4fv_Idx))


GL_APICALL void GL_APIENTRY
glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();

    glUniformMatrix2fv_ (location, count, transpose, value);

    fprintf (g_log_fp, "glUniformMatrix2fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();

    glUniformMatrix3fv_ (location, count, transpose, value);

    fprintf (g_log_fp, "glUniformMatrix3fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();

    glUniformMatrix4fv_ (location, count, transpose, value);

    fprintf (g_log_fp, "glUniformMatrix4fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

