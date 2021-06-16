#include <stdio.h>
#include "GLEStrace.h"

#define glUniform1f_   \
    ((void (*)(GLint location, GLfloat v0))  \
    GLES_ENTRY_PTR(glUniform1f_Idx))

#define glUniform1fv_   \
    ((void (*)(GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniform1fv_Idx))

#define glUniform1i_   \
    ((void (*)(GLint location, GLint v0))  \
    GLES_ENTRY_PTR(glUniform1i_Idx))

#define glUniform1iv_   \
    ((void (*)(GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glUniform1iv_Idx))


#define glUniform2f_   \
    ((void (*)(GLint location, GLfloat v0, GLfloat v1))  \
    GLES_ENTRY_PTR(glUniform2f_Idx))

#define glUniform2fv_   \
    ((void (*)(GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniform2fv_Idx))

#define glUniform2i_   \
    ((void (*)(GLint location, GLint v0, GLint v1))  \
    GLES_ENTRY_PTR(glUniform2i_Idx))

#define glUniform2iv_   \
    ((void (*)(GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glUniform2iv_Idx))


#define glUniform3f_   \
    ((void (*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2))  \
    GLES_ENTRY_PTR(glUniform3f_Idx))

#define glUniform3fv_   \
    ((void (*)(GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniform3fv_Idx))

#define glUniform3i_   \
    ((void (*)(GLint location, GLint v0, GLint v1, GLint v2))  \
    GLES_ENTRY_PTR(glUniform3i_Idx))

#define glUniform3iv_   \
    ((void (*)(GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glUniform3iv_Idx))


#define glUniform4f_   \
    ((void (*)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3))  \
    GLES_ENTRY_PTR(glUniform4f_Idx))

#define glUniform4fv_   \
    ((void (*)(GLint location, GLsizei count, const GLfloat *value))  \
    GLES_ENTRY_PTR(glUniform4fv_Idx))

#define glUniform4i_   \
    ((void (*)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3))  \
    GLES_ENTRY_PTR(glUniform4i_Idx))

#define glUniform4iv_   \
    ((void (*)(GLint location, GLsizei count, const GLint *value))  \
    GLES_ENTRY_PTR(glUniform4iv_Idx))




GL_APICALL void GL_APIENTRY
glUniform1f (GLint location, GLfloat v0)
{
    prepare_gles_tracer ();

    glUniform1f_ (location, v0);

    fprintf (g_log_fp, "glUniform1f(%d, %f);\n", location, v0);
}

GL_APICALL void GL_APIENTRY
glUniform1fv (GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();

    glUniform1fv_ (location, count, value);

    fprintf (g_log_fp, "glUniform1fv(%d, %d, %p);\n", location, count, value);
}

GL_APICALL void GL_APIENTRY
glUniform1i (GLint location, GLint v0)
{
    prepare_gles_tracer ();

    glUniform1i_ (location, v0);

    fprintf (g_log_fp, "glUniform1i(%d, %d);\n", location, v0);
}

GL_APICALL void GL_APIENTRY
glUniform1iv (GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();

    glUniform1iv_ (location, count, value);

    fprintf (g_log_fp, "glUniform1iv(%d, %d, %p);\n", location, count, value);
}



GL_APICALL void GL_APIENTRY
glUniform2f (GLint location, GLfloat v0, GLfloat v1)
{
    prepare_gles_tracer ();

    glUniform2f_ (location, v0, v1);

    fprintf (g_log_fp, "glUniform2f(%d, %f, %f);\n", location, v0, v1);
}

GL_APICALL void GL_APIENTRY
glUniform2fv (GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();

    glUniform2fv_ (location, count, value);

    fprintf (g_log_fp, "glUniform2fv(%d, %d, %p);\n", location, count, value);
}

GL_APICALL void GL_APIENTRY
glUniform2i (GLint location, GLint v0, GLint v1)
{
    prepare_gles_tracer ();

    glUniform2i_ (location, v0, v1);

    fprintf (g_log_fp, "glUniform2i(%d, %d, %d);\n", location, v0, v1);
}

GL_APICALL void GL_APIENTRY
glUniform2iv (GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();

    glUniform2iv_ (location, count, value);

    fprintf (g_log_fp, "glUniform2iv(%d, %d, %p);\n", location, count, value);
}



GL_APICALL void GL_APIENTRY
glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
    prepare_gles_tracer ();

    glUniform3f_ (location, v0, v1, v2);

    fprintf (g_log_fp, "glUniform3f(%d, %f, %f, %f);\n", location, v0, v1, v2);
}

GL_APICALL void GL_APIENTRY
glUniform3fv (GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();

    glUniform3fv_ (location, count, value);

    fprintf (g_log_fp, "glUniform3fv(%d, %d, %p);\n", location, count, value);
}

GL_APICALL void GL_APIENTRY
glUniform3i (GLint location, GLint v0, GLint v1, GLint v2)
{
    prepare_gles_tracer ();

    glUniform3i_ (location, v0, v1, v2);

    fprintf (g_log_fp, "glUniform3i(%d, %d, %d, %d);\n", location, v0, v1, v2);
}

GL_APICALL void GL_APIENTRY
glUniform3iv (GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();

    glUniform3iv_ (location, count, value);

    fprintf (g_log_fp, "glUniform3iv(%d, %d, %p);\n", location, count, value);
}



GL_APICALL void GL_APIENTRY
glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
    prepare_gles_tracer ();

    glUniform4f_ (location, v0, v1, v2, v3);

    fprintf (g_log_fp, "glUniform4f(%d, %f, %f, %f, %f);\n", location, v0, v1, v2, v3);
}

GL_APICALL void GL_APIENTRY
glUniform4fv (GLint location, GLsizei count, const GLfloat *value)
{
    prepare_gles_tracer ();

    glUniform4fv_ (location, count, value);

    fprintf (g_log_fp, "glUniform4fv(%d, %d, %p);\n", location, count, value);
}

GL_APICALL void GL_APIENTRY
glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
    prepare_gles_tracer ();

    glUniform4i_ (location, v0, v1, v2, v3);

    fprintf (g_log_fp, "glUniform4i(%d, %d, %d, %d, %d);\n", location, v0, v1, v2, v3);
}

GL_APICALL void GL_APIENTRY
glUniform4iv (GLint location, GLsizei count, const GLint *value)
{
    prepare_gles_tracer ();

    glUniform4iv_ (location, count, value);

    fprintf (g_log_fp, "glUniform4iv(%d, %d, %p);\n", location, count, value);
}
