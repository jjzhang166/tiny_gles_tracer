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

static char *
get_type_str (GLint type)
{
    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR                : return "GL_DEBUG_TYPE_ERROR";
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR  : return "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR";
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR   : return "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR";
    case GL_DEBUG_TYPE_PORTABILITY          : return "GL_DEBUG_TYPE_PORTABILITY";
    case GL_DEBUG_TYPE_PERFORMANCE          : return "GL_DEBUG_TYPE_PERFORMANCE";
    case GL_DEBUG_TYPE_MARKER               : return "GL_DEBUG_TYPE_MARKER";
    case GL_DEBUG_TYPE_PUSH_GROUP           : return "GL_DEBUG_TYPE_PUSH_GROUP";
    case GL_DEBUG_TYPE_POP_GROUP            : return "GL_DEBUG_TYPE_POP_GROUP";
    case GL_DEBUG_TYPE_OTHER                : return "GL_DEBUG_TYPE_OTHER";
    case GL_DONT_CARE                       : return "GL_DONT_CARE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}

static char *
get_severity_str (GLint severity)
{
    switch (severity)
    {
    case GL_DEBUG_SEVERITY_LOW              : return "GL_DEBUG_SEVERITY_LOW";
    case GL_DEBUG_SEVERITY_MEDIUM           : return "GL_DEBUG_SEVERITY_MEDIUM";
    case GL_DEBUG_SEVERITY_HIGH             : return "GL_DEBUG_SEVERITY_HIGH";
    case GL_DEBUG_SEVERITY_NOTIFICATION     : return "GL_DEBUG_SEVERITY_NOTIFICATION";
    case GL_DONT_CARE                       : return "GL_DONT_CARE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", severity);
    return s_strbuf;
}

#define glDebugMessageControl_   \
    ((void (*)(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled))  \
    GLES_ENTRY_PTR(glDebugMessageControl_Idx))


GL_APICALL void GL_APIENTRY
glDebugMessageControl (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
{
    prepare_gles_tracer ();

    glDebugMessageControl_ (source, type, severity, count, ids, enabled);

    fprintf (g_log_fp, "glDebugMessageControl(%s, %s, %s, %d, %p, %d);\n",
             get_src_str (source), get_type_str (type), get_severity_str (severity),
             count, ids, enabled);
}

