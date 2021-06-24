#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_type_str (GLenum type)
{
    switch (type)
    {
    case GL_BYTE                : return "GL_BYTE";             break;
    case GL_SHORT               : return "GL_SHORT";            break;
    case GL_INT                 : return "GL_INT";              break;
    case GL_FIXED               : return "GL_FIXED";            break;
    case GL_FLOAT               : return "GL_FLOAT";            break;
    case GL_HALF_FLOAT          : return "GL_HALF_FLOAT";       break;
    case GL_UNSIGNED_BYTE       : return "GL_UNSIGNED_BYTE";    break;
    case GL_UNSIGNED_SHORT      : return "GL_UNSIGNED_SHORT";   break;
    case GL_UNSIGNED_INT        : return "GL_UNSIGNED_INT";     break;
    case GL_INT_2_10_10_10_REV  : return "GL_INT_2_10_10_10_REV";break;
    case GL_UNSIGNED_INT_2_10_10_10_REV: return "GL_UNSIGNED_INT_2_10_10_10_REV "; break;
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}


#define glVertexAttribFormat_   \
    ((void (*)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset))  \
    GLES_ENTRY_PTR(glVertexAttribFormat_Idx))


GL_APICALL void GL_APIENTRY
glVertexAttribFormat (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
{
    prepare_gles_tracer ();
    glVertexAttribFormat_ (attribindex, size, type, normalized, relativeoffset);
    fprintf (g_log_fp, "glVertexAttribFormat(%d, %d, %s, %d, %d);\n",
             attribindex, size, get_type_str (type), normalized, relativeoffset);
}
