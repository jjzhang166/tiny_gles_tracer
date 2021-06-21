#include <stdio.h>
#include "GLEStrace.h"

#define glUniform1ui_   \
    ((void (*)(GLint location, GLuint v0))  \
    GLES_ENTRY_PTR(glUniform1ui_Idx))

#define glUniform2ui_   \
    ((void (*)(GLint location, GLuint v0, GLuint v1))  \
    GLES_ENTRY_PTR(glUniform2ui_Idx))

#define glUniform3ui_   \
    ((void (*)(GLint location, GLuint v0, GLuint v1, GLuint v2))  \
    GLES_ENTRY_PTR(glUniform3ui_Idx))

#define glUniform4ui_   \
    ((void (*)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3))  \
    GLES_ENTRY_PTR(glUniform4ui_Idx))

#define glUniform1uiv_   \
    ((void (*)(GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glUniform1uiv_Idx))

#define glUniform2uiv_   \
    ((void (*)(GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glUniform2uiv_Idx))

#define glUniform3uiv_   \
    ((void (*)(GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glUniform3uiv_Idx))

#define glUniform4uiv_   \
    ((void (*)(GLint location, GLsizei count, const GLuint *value))  \
    GLES_ENTRY_PTR(glUniform4uiv_Idx))


GL_APICALL void GL_APIENTRY
glUniform1ui (GLint location, GLuint v0)
{
    prepare_gles_tracer ();
    glUniform1ui_ (location, v0);
    fprintf (g_log_fp, "glUniform1ui(%d, %d);\n", location, v0);
}

GL_APICALL void GL_APIENTRY
glUniform2ui (GLint location, GLuint v0, GLuint v1)
{
    prepare_gles_tracer ();
    glUniform2ui_ (location, v0, v1);
    fprintf (g_log_fp, "glUniform2ui(%d, %d, %d);\n", location, v0, v1);
}

GL_APICALL void GL_APIENTRY
glUniform3ui (GLint location, GLuint v0, GLuint v1, GLuint v2)
{
    prepare_gles_tracer ();
    glUniform3ui_ (location, v0, v1, v2);
    fprintf (g_log_fp, "glUniform3ui(%d, %d, %d, %d);\n", location, v0, v1, v2);
}

GL_APICALL void GL_APIENTRY
glUniform4ui (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
    prepare_gles_tracer ();
    glUniform4ui_ (location, v0, v1, v2, v3);
    fprintf (g_log_fp, "glUniform4ui(%d, %d, %d, %d, %d);\n", location, v0, v1, v2, v3);
}

GL_APICALL void GL_APIENTRY
glUniform1uiv (GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glUniform1uiv_ (location, count, value);
    fprintf (g_log_fp, "glUniform1uiv(%d, %d, %p);\n", location, count, value);
}

GL_APICALL void GL_APIENTRY
glUniform2uiv (GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glUniform2uiv_ (location, count, value);
    fprintf (g_log_fp, "glUniform2uiv(%d, %d, %p);\n", location, count, value);
}

GL_APICALL void GL_APIENTRY
glUniform3uiv (GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glUniform3uiv_ (location, count, value);
    fprintf (g_log_fp, "glUniform3uiv(%d, %d, %p);\n", location, count, value);
}

GL_APICALL void GL_APIENTRY
glUniform4uiv (GLint location, GLsizei count, const GLuint *value)
{
    prepare_gles_tracer ();
    glUniform4uiv_ (location, count, value);
    fprintf (g_log_fp, "glUniform4uiv(%d, %d, %p);\n", location, count, value);
}

