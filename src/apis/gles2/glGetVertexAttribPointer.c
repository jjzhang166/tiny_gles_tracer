#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_VERTEX_ATTRIB_ARRAY_POINTER         : return "GL_VERTEX_ATTRIB_ARRAY_POINTER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetVertexAttribPointerv_   \
    ((void (*)(GLuint index, GLenum pname, void **pointer))  \
    GLES_ENTRY_PTR(glGetVertexAttribPointerv_Idx))


GL_APICALL void GL_APIENTRY
glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer)
{
    prepare_gles_tracer ();

    glGetVertexAttribPointerv_ (index, pname, pointer);

    fprintf (g_log_fp, "glGetVertexAttribPointerv(%d, %s, %p);\n",
             index, get_pname_str (pname), pointer);
}
