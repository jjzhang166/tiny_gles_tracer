#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_data_type_str (GLenum type)
{
    switch (type)
    {
    case GL_BYTE                : return "GL_BYTE";              break;
    case GL_UNSIGNED_BYTE       : return "GL_UNSIGNED_BYTE";     break;
    case GL_SHORT               : return "GL_SHORT";             break;
    case GL_UNSIGNED_SHORT      : return "GL_UNSIGNED_SHORT";    break;
    case GL_INT                 : return "GL_INT";               break;
    case GL_UNSIGNED_INT        : return "GL_UNSIGNED_INT ";     break;
    case GL_HALF_FLOAT          : return "GL_HALF_FLOAT";        break;
    case GL_FLOAT               : return "GL_FLOAT";             break;
    case GL_FIXED               : return "GL_FIXED";             break;
    case GL_INT_2_10_10_10_REV  : return "GL_INT_2_10_10_10_REV";break;
    case GL_UNSIGNED_INT_2_10_10_10_REV           : return "GL_UNSIGNED_INT_2_10_10_10_REV ";        break;
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}


#define glVertexAttrib1f_   \
    ((void (*)(GLuint index, GLfloat x))  \
    GLES_ENTRY_PTR(glVertexAttrib1f_Idx))

#define glVertexAttrib1fv_   \
    ((void (*)(GLuint index, const GLfloat *v))  \
    GLES_ENTRY_PTR(glVertexAttrib1fv_Idx))


#define glVertexAttrib2f_   \
    ((void (*)(GLuint index, GLfloat x, GLfloat y))  \
    GLES_ENTRY_PTR(glVertexAttrib2f_Idx))

#define glVertexAttrib2fv_   \
    ((void (*)(GLuint index, const GLfloat *v))  \
    GLES_ENTRY_PTR(glVertexAttrib2fv_Idx))


#define glVertexAttrib3f_   \
    ((void (*)(GLuint index, GLfloat x, GLfloat y, GLfloat z))  \
    GLES_ENTRY_PTR(glVertexAttrib3f_Idx))

#define glVertexAttrib3fv_   \
    ((void (*)(GLuint index, const GLfloat *v))  \
    GLES_ENTRY_PTR(glVertexAttrib3fv_Idx))


#define glVertexAttrib4f_   \
    ((void (*)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w))  \
    GLES_ENTRY_PTR(glVertexAttrib4f_Idx))

#define glVertexAttrib4fv_   \
    ((void (*)(GLuint index, const GLfloat *v))  \
    GLES_ENTRY_PTR(glVertexAttrib4fv_Idx))


#define glVertexAttribPointer_   \
    ((void (*)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer))  \
    GLES_ENTRY_PTR(glVertexAttribPointer_Idx))



GL_APICALL void GL_APIENTRY
glVertexAttrib1f (GLuint index, GLfloat x)
{
    prepare_gles_tracer ();

    glVertexAttrib1f_ (index, x);

    fprintf (g_log_fp, "glVertexAttrib1f(%d, %f);\n", index, x);
}

GL_APICALL void GL_APIENTRY
glVertexAttrib1fv (GLuint index, const GLfloat *v)
{
    prepare_gles_tracer ();

    glVertexAttrib1fv_ (index, v);

    fprintf (g_log_fp, "glVertexAttrib1fv(%d, %p);\n", index, v);
}



GL_APICALL void GL_APIENTRY
glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y)
{
    prepare_gles_tracer ();

    glVertexAttrib2f_ (index, x, y);

    fprintf (g_log_fp, "glVertexAttrib2f(%d, %f, %f);\n", index, x, y);
}

GL_APICALL void GL_APIENTRY
glVertexAttrib2fv (GLuint index, const GLfloat *v)
{
    prepare_gles_tracer ();

    glVertexAttrib2fv_ (index, v);

    fprintf (g_log_fp, "glVertexAttrib2fv(%d, %p);\n", index, v);
}



GL_APICALL void GL_APIENTRY
glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
    prepare_gles_tracer ();

    glVertexAttrib3f_ (index, x, y, z);

    fprintf (g_log_fp, "glVertexAttrib3f(%d, %f, %f, %f);\n", index, x, y, z);
}

GL_APICALL void GL_APIENTRY
glVertexAttrib3fv (GLuint index, const GLfloat *v)
{
    prepare_gles_tracer ();

    glVertexAttrib3fv_ (index, v);

    fprintf (g_log_fp, "glVertexAttrib3fv(%d, %p);\n", index, v);
}



GL_APICALL void GL_APIENTRY
glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    prepare_gles_tracer ();

    glVertexAttrib4f_ (index, x, y, z, w);

    fprintf (g_log_fp, "glVertexAttrib4f(%d, %f, %f, %f, %f);\n", index, x, y, z, w);
}

GL_APICALL void GL_APIENTRY
glVertexAttrib4fv (GLuint index, const GLfloat *v)
{
    prepare_gles_tracer ();

    glVertexAttrib4fv_ (index, v);

    fprintf (g_log_fp, "glVertexAttrib4fv(%d, %p);\n", index, v);
}



GL_APICALL void GL_APIENTRY
glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
    prepare_gles_tracer ();

    glVertexAttribPointer_ (index, size, type, normalized, stride, pointer);

    fprintf (g_log_fp, "glVertexAttribPointer(%d, %d, %s, %d, %d, %p);\n",
             index, size, get_data_type_str (type), normalized, stride, pointer);
}
