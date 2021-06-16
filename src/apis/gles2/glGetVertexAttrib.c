#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_CURRENT_VERTEX_ATTRIB               : return "GL_CURRENT_VERTEX_ATTRIB";
    case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING  : return "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING";
    case GL_VERTEX_ATTRIB_ARRAY_ENABLED         : return "GL_VERTEX_ATTRIB_ARRAY_ENABLED";
    case GL_VERTEX_ATTRIB_ARRAY_SIZE            : return "GL_VERTEX_ATTRIB_ARRAY_SIZE";
    case GL_VERTEX_ATTRIB_ARRAY_STRIDE          : return "GL_VERTEX_ATTRIB_ARRAY_STRIDE";
    case GL_VERTEX_ATTRIB_ARRAY_TYPE            : return "GL_VERTEX_ATTRIB_ARRAY_TYPE";
    case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED      : return "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED";
    case GL_VERTEX_ATTRIB_ARRAY_INTEGER         : return "GL_VERTEX_ATTRIB_ARRAY_INTEGER";
    case GL_VERTEX_ATTRIB_ARRAY_DIVISOR         : return "GL_VERTEX_ATTRIB_ARRAY_DIVISOR";
    case GL_VERTEX_ATTRIB_BINDING               : return "GL_VERTEX_ATTRIB_BINDING";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}

#define glGetVertexAttribfv_   \
    ((void (*)(GLuint program, GLint location, GLfloat *params))  \
    GLES_ENTRY_PTR(glGetVertexAttribfv_Idx))

#define glGetVertexAttribiv_   \
    ((void (*)(GLuint program, GLint location, GLint *params))  \
    GLES_ENTRY_PTR(glGetVertexAttribiv_Idx))


GL_APICALL void GL_APIENTRY
glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params)
{
    prepare_gles_tracer ();

    glGetVertexAttribfv_ (index, pname, params);

    fprintf (g_log_fp, "glGetUniformfv(%d, %s, %p);",
        index, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %f\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetVertexAttribiv_ (index, pname, params);

    fprintf (g_log_fp, "glGetUniformiv(%d, %s, %p);",
             index, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}
