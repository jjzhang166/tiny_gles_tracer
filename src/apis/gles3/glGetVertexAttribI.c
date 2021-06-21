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

#define glGetVertexAttribIiv_   \
    ((void (*)(GLuint index, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetVertexAttribIiv_Idx))

#define glGetVertexAttribIuiv_   \
    ((void (*)(GLuint index, GLenum pname, GLuint *params))  \
    GLES_ENTRY_PTR(glGetVertexAttribIuiv_Idx))


GL_APICALL void GL_APIENTRY
glGetVertexAttribIiv (GLuint index, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetVertexAttribIiv_ (index, pname, params);

    fprintf (g_log_fp, "glGetVertexAttribIiv(%d, %s, %p);",
             index, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params=%d\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetVertexAttribIuiv (GLuint index, GLenum pname, GLuint *params)
{
    prepare_gles_tracer ();

    glGetVertexAttribIuiv_ (index, pname, params);

    fprintf (g_log_fp, "glGetVertexAttribIuiv(%d, %s, %p);",
             index, get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params=%d\n", *params);
}
