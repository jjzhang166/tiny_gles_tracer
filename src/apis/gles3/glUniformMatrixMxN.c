#include <stdio.h>
#include "GLEStrace.h"

#define glUniformMatrix2x3fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix2x3fv_Idx))

#define glUniformMatrix3x2fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix3x2fv_Idx))

#define glUniformMatrix2x4fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix2x4fv_Idx))

#define glUniformMatrix4x2fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix4x2fv_Idx))

#define glUniformMatrix3x4fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix3x4fv_Idx))

#define glUniformMatrix4x3fv_   \
    ((void (*)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniformMatrix4x3fv_Idx))


GL_APICALL void GL_APIENTRY
glUniformMatrix2x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glUniformMatrix2x3fv_ (location, count, transpose, value);
    fprintf (g_log_fp, "glUniformMatrix2x3fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glUniformMatrix3x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glUniformMatrix3x2fv_ (location, count, transpose, value);
    fprintf (g_log_fp, "glUniformMatrix3x2fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glUniformMatrix2x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glUniformMatrix2x4fv_ (location, count, transpose, value);
    fprintf (g_log_fp, "glUniformMatrix2x4fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glUniformMatrix4x2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glUniformMatrix4x2fv_ (location, count, transpose, value);
    fprintf (g_log_fp, "glUniformMatrix4x2fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glUniformMatrix3x4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glUniformMatrix3x4fv_ (location, count, transpose, value);
    fprintf (g_log_fp, "glUniformMatrix3x4fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glUniformMatrix4x3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glUniformMatrix4x3fv_ (location, count, transpose, value);
    fprintf (g_log_fp, "glUniformMatrix4x3fv(%d, %d, %d, %p);\n", location, count, transpose, value);
}
