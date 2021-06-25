#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_RENDERBUFFER    : return "GL_RENDERBUFFER";
    case GL_TEXTURE_BUFFER  : return "GL_TEXTURE_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

#define glCopyImageSubData_   \
    ((void (*)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth))  \
    GLES_ENTRY_PTR(glCopyImageSubData_Idx))


GL_APICALL void GL_APIENTRY
glCopyImageSubData (GLuint srcName, GLenum srcTarget, GLint srcLevel,
                    GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel,
                    GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
{
    prepare_gles_tracer ();

    glCopyImageSubData_ (srcName, srcTarget, srcLevel, srcX, srcY, srcZ,
                         dstName, dstTarget, dstLevel, dstX, dstY, dstZ,
                         srcWidth, srcHeight, srcDepth);

    fprintf (g_log_fp, "glCopyImageSubData(%d, %s, %d, %d, %d, %d, %d, %s, %d, %d, %d, %d, %d, %d, %d);\n",
             srcName, get_target_str (srcTarget), srcLevel, srcX, srcY, srcZ,
             dstName, get_target_str (dstTarget), dstLevel, dstX, dstY, dstZ,
             srcWidth, srcHeight, srcDepth);
}

