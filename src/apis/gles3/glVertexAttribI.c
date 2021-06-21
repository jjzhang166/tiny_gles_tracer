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


#define glVertexAttribIPointer_   \
    ((void (*)(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer))  \
    GLES_ENTRY_PTR(glVertexAttribIPointer_Idx))

#define glVertexAttribI4i_   \
    ((void (*)(GLuint index, GLint x, GLint y, GLint z, GLint w))  \
    GLES_ENTRY_PTR(glVertexAttribI4i_Idx))

#define glVertexAttribI4ui_   \
    ((void (*)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w))  \
    GLES_ENTRY_PTR(glVertexAttribI4ui_Idx))

#define glVertexAttribI4iv_   \
    ((void (*)(GLuint index, const GLint *v))  \
    GLES_ENTRY_PTR(glVertexAttribI4iv_Idx))

#define glVertexAttribI4uiv_   \
    ((void (*)(GLuint index, const GLuint *v))  \
    GLES_ENTRY_PTR(glVertexAttribI4uiv_Idx))


GL_APICALL void GL_APIENTRY
glVertexAttribIPointer (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
{
    prepare_gles_tracer ();

    glVertexAttribIPointer_ (index, size, type, stride, pointer);

    fprintf (g_log_fp, "glVertexAttribIPointer(%d, %d, %s, %d, %p);\n",
             index, size, get_data_type_str (type), stride, pointer);
}

GL_APICALL void GL_APIENTRY
glVertexAttribI4i (GLuint index, GLint x, GLint y, GLint z, GLint w)
{
    prepare_gles_tracer ();
    glVertexAttribI4i_ (index, x, y, z, w);
    fprintf (g_log_fp, "glVertexAttribI4i(%d, %d, %d, %d, %d);\n", index, x, y, z, w);
}

GL_APICALL void GL_APIENTRY
glVertexAttribI4ui (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
    prepare_gles_tracer ();
    glVertexAttribI4ui_ (index, x, y, z, w);
    fprintf (g_log_fp, "glVertexAttribI4ui(%d, %d, %d, %d, %d);\n", index, x, y, z, w);
}

GL_APICALL void GL_APIENTRY
glVertexAttribI4iv (GLuint index, const GLint *v)
{
    prepare_gles_tracer ();
    glVertexAttribI4iv_ (index, v);
    fprintf (g_log_fp, "glVertexAttribI4iv(%d, %p);\n", index, v);
}

GL_APICALL void GL_APIENTRY
glVertexAttribI4uiv (GLuint index, const GLuint *v)
{
    prepare_gles_tracer ();
    glVertexAttribI4uiv_ (index, v);
    fprintf (g_log_fp, "glVertexAttribI4uiv(%d, %p);\n", index, v);
}

