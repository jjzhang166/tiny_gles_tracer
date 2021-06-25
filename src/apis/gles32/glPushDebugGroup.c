#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_src_str (GLenum source)
{
    switch (source)
    {
    case GL_DEBUG_SOURCE_API                : return "GL_DEBUG_SOURCE_API";
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM      : return "GL_DEBUG_SOURCE_WINDOW_SYSTEM";
    case GL_DEBUG_SOURCE_SHADER_COMPILER    : return "GL_DEBUG_SOURCE_SHADER_COMPILER";
    case GL_DEBUG_SOURCE_THIRD_PARTY        : return "GL_DEBUG_SOURCE_THIRD_PARTY";
    case GL_DEBUG_SOURCE_APPLICATION        : return "GL_DEBUG_SOURCE_APPLICATION";
    case GL_DEBUG_SOURCE_OTHER              : return "GL_DEBUG_SOURCE_OTHER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", source);
    return s_strbuf;
}


#define glPushDebugGroup_   \
    ((void (*)(GLenum source, GLuint id, GLsizei length, const GLchar *message))  \
    GLES_ENTRY_PTR(glPushDebugGroup_Idx))


GL_APICALL void GL_APIENTRY
glPushDebugGroup (GLenum source, GLuint id, GLsizei length, const GLchar *message)
{
    prepare_gles_tracer ();

    glPushDebugGroup_ (source, id, length, message);

    fprintf (g_log_fp, "glPushDebugGroup(%s, %d, %d, %s);\n",
             get_src_str (source), id, length, message);
}

