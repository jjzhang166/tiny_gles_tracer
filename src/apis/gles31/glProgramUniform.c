#include <stdio.h>
#include "GLEStrace.h"

#define glProgramUniform1i_   \
    ((void (*)(GLuint program, GLint location, GLint v0))  \
    GLES_ENTRY_PTR(glProgramUniform1i_Idx))

#define glProgramUniform2i_   \
    ((void (*)(GLuint program, GLint location, GLint v0, GLint v1))  \
    GLES_ENTRY_PTR(glProgramUniform2i_Idx))

#define glProgramUniform3i_   \
    ((void (*)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2))  \
    GLES_ENTRY_PTR(glProgramUniform3i_Idx))

#define glProgramUniform4i_   \
    ((void (*)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3))  \
    GLES_ENTRY_PTR(glProgramUniform4i_Idx))

#define glProgramUniform1ui_   \
    ((void (*)(GLuint program, GLint location, GLuint v0))  \
    GLES_ENTRY_PTR(glProgramUniform1ui_Idx))

#define glProgramUniform2ui_   \
    ((void (*)(GLuint program, GLint location, GLuint v0, GLuint v1))  \
    GLES_ENTRY_PTR(glProgramUniform2ui_Idx))

#define glProgramUniform3ui_   \
    ((void (*)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2))  \
    GLES_ENTRY_PTR(glProgramUniform3ui_Idx))

#define glProgramUniform4ui_   \
    ((void (*)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3))  \
    GLES_ENTRY_PTR(glProgramUniform4ui_Idx))

#define glProgramUniform1f_   \
    ((void (*)(GLuint program, GLint location, GLfloat v0))  \
    GLES_ENTRY_PTR(glProgramUniform1f_Idx))

#define glProgramUniform2f_   \
    ((void (*)(GLuint program, GLint location, GLfloat v0, GLfloat v1))  \
    GLES_ENTRY_PTR(glProgramUniform2f_Idx))

#define glProgramUniform3f_   \
    ((void (*)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2))  \
    GLES_ENTRY_PTR(glProgramUniform3f_Idx))

#define glProgramUniform4f_   \
    ((void (*)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3))  \
    GLES_ENTRY_PTR(glProgramUniform4f_Idx))

#define glProgramUniform1iv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glProgramUniform1iv_Idx))

#define glProgramUniform2iv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glProgramUniform2iv_Idx))

#define glProgramUniform3iv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glProgramUniform3iv_Idx))

#define glProgramUniform4iv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glProgramUniform4iv_Idx))

#define glProgramUniform1uiv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glProgramUniform1uiv_Idx))

#define glProgramUniform2uiv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glProgramUniform2uiv_Idx))

#define glProgramUniform3uiv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glProgramUniform3uiv_Idx))

#define glProgramUniform4uiv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glProgramUniform4uiv_Idx))

#define glProgramUniform1fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniform1fv_Idx))

#define glProgramUniform2fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniform2fv_Idx))

#define glProgramUniform3fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniform3fv_Idx))

#define glProgramUniform4fv_   \
    ((void (*)(GLuint program, GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glProgramUniform4fv_Idx))


GL_APICALL void GL_APIENTRY
glProgramUniform1i (GLuint program, GLint location, GLint v0)
{
    prepare_gles_tracer ();
    glProgramUniform1i_ (program, location, v0);
    fprintf (g_log_fp, "glProgramUniform1i(%d, %d, %d);\n", program, location, v0);
}

GL_APICALL void GL_APIENTRY
glProgramUniform2i (GLuint program, GLint location, GLint v0, GLint v1)
{
    prepare_gles_tracer ();
    glProgramUniform2i_ (program, location, v0, v1);
    fprintf (g_log_fp, "glProgramUniform2i(%d, %d, %d, %d);\n", program, location, v0, v1);
}

GL_APICALL void GL_APIENTRY
glProgramUniform3i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2)
{
    prepare_gles_tracer ();
    glProgramUniform3i_ (program, location, v0, v1, v2);
    fprintf (g_log_fp, "glProgramUniform3i(%d, %d, %d, %d, %d);\n", program, location, v0, v1, v2);
}

GL_APICALL void GL_APIENTRY
glProgramUniform4i (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
    prepare_gles_tracer ();
    glProgramUniform4i_ (program, location, v0, v1, v2, v3);
    fprintf (g_log_fp, "glProgramUniform4i(%d, %d, %d, %d, %d, %d);\n", program, location, v0, v1, v2, v3);
}

GL_APICALL void GL_APIENTRY
glProgramUniform1ui (GLuint program, GLint location, GLuint v0)
{
    prepare_gles_tracer ();
    glProgramUniform1ui_ (program, location, v0);
    fprintf (g_log_fp, "glProgramUniform1ui(%d, %d, %d);\n", program, location, v0);
}

GL_APICALL void GL_APIENTRY
glProgramUniform2ui (GLuint program, GLint location, GLuint v0, GLuint v1)
{
    prepare_gles_tracer ();
    glProgramUniform2ui_ (program, location, v0, v1);
    fprintf (g_log_fp, "glProgramUniform2ui(%d, %d, %d, %d);\n", program, location, v0, v1);
}

GL_APICALL void GL_APIENTRY
glProgramUniform3ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
    prepare_gles_tracer ();
    glProgramUniform3ui_ (program, location, v0, v1, v2);
    fprintf (g_log_fp, "glProgramUniform3ui(%d, %d, %d, %d, %d);\n", program, location, v0, v1, v2);
}

GL_APICALL void GL_APIENTRY
glProgramUniform4ui (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
    prepare_gles_tracer ();
    glProgramUniform4ui_ (program, location, v0, v1, v2, v3);
    fprintf (g_log_fp, "glProgramUniform4ui(%d, %d, %d, %d, %d, %d);\n", program, location, v0, v1, v2, v3);
}

GL_APICALL void GL_APIENTRY
glProgramUniform1f (GLuint program, GLint location, GLfloat v0)
{
    prepare_gles_tracer ();
    glProgramUniform1f_ (program, location, v0);
    fprintf (g_log_fp, "glProgramUniform1f(%d, %d, %f);\n", program, location, v0);
}

GL_APICALL void GL_APIENTRY
glProgramUniform2f (GLuint program, GLint location, GLfloat v0, GLfloat v1)
{
    prepare_gles_tracer ();
    glProgramUniform2f_ (program, location, v0, v1);
    fprintf (g_log_fp, "glProgramUniform2f(%d, %d, %f, %f);\n", program, location, v0, v1);
}

GL_APICALL void GL_APIENTRY
glProgramUniform3f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
    prepare_gles_tracer ();
    glProgramUniform3f_ (program, location, v0, v1, v2);
    fprintf (g_log_fp, "glProgramUniform3f(%d, %d, %f, %f, %f);\n", program, location, v0, v1, v2);
}

GL_APICALL void GL_APIENTRY
glProgramUniform4f (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    prepare_gles_tracer ();
    glProgramUniform4f_ (program, location, v0, v1, v2, v3);
    fprintf (g_log_fp, "glProgramUniform4f(%d, %d, %f, %f, %f, %f);\n", program, location, v0, v1, v2, v3);
}

GL_APICALL void GL_APIENTRY
glProgramUniform1iv (GLuint program, GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();
    glProgramUniform1iv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform1iv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform2iv (GLuint program, GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();
    glProgramUniform2iv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform2iv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform3iv (GLuint program, GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();
    glProgramUniform3iv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform3iv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform4iv (GLuint program, GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();
    glProgramUniform4iv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform4iv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform1uiv (GLuint program, GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glProgramUniform1uiv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform1uiv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform2uiv (GLuint program, GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glProgramUniform2uiv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform2uiv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform3uiv (GLuint program, GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glProgramUniform3uiv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform3uiv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform4uiv (GLuint program, GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glProgramUniform4uiv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform4uiv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform1fv (GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniform1fv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform1fv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform2fv (GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniform2fv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform2fv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform3fv (GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniform3fv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform3fv(%d, %d, %d, %p);\n", program, location, count, value);
}

GL_APICALL void GL_APIENTRY
glProgramUniform4fv (GLuint program, GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();
    glProgramUniform4fv_ (program, location, count, value);
    fprintf (g_log_fp, "glProgramUniform4fv(%d, %d, %d, %p);\n", program, location, count, value);
}