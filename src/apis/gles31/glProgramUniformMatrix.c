#include <stdio.h>
#include "GLEStrace.h"

#define glProgramUniformMatrix2fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix2fv_Idx))

#define glProgramUniformMatrix3fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix3fv_Idx))

#define glProgramUniformMatrix4fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix4fv_Idx))

#define glProgramUniformMatrix2x3fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix2x3fv_Idx))

#define glProgramUniformMatrix3x2fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix3x2fv_Idx))

#define glProgramUniformMatrix2x4fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix2x4fv_Idx))

#define glProgramUniformMatrix4x2fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix4x2fv_Idx))

#define glProgramUniformMatrix3x4fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix3x4fv_Idx))

#define glProgramUniformMatrix4x3fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniformMatrix4x3fv_Idx))


GL_APICALL void GL_APIENTRY
glProgramUniformMatrix2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix2fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix2fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix3fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix3fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix4fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix4fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix2x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix2x3fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix2x3fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix3x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix3x2fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix3x2fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix2x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix2x4fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix2x4fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix4x2fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix4x2fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix4x2fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix3x4fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix3x4fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix3x4fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniformMatrix4x3fv (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniformMatrix4x3fv_ (program, location, count, transpose, value);
    fprintf (g_log_fp, "glProgramUniformMatrix4x3fv(%d, %d, %d, %d, %p);\n", program, location, count, transpose, value);
}
