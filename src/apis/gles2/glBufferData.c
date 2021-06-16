#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static int  s_count = 0;
static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_ARRAY_BUFFER                : return "GL_ARRAY_BUFFER";
    case GL_ATOMIC_COUNTER_BUFFER       : return "GL_ATOMIC_COUNTER_BUFFER";
    case GL_COPY_READ_BUFFER            : return "GL_COPY_READ_BUFFER";
    case GL_COPY_WRITE_BUFFER           : return "GL_COPY_WRITE_BUFFER";
    case GL_DRAW_INDIRECT_BUFFER        : return "GL_DRAW_INDIRECT_BUFFER";
    case GL_DISPATCH_INDIRECT_BUFFER    : return "GL_DISPATCH_INDIRECT_BUFFER";
    case GL_ELEMENT_ARRAY_BUFFER        : return "GL_ELEMENT_ARRAY_BUFFER";
    case GL_PIXEL_PACK_BUFFER           : return "GL_PIXEL_PACK_BUFFER";
    case GL_PIXEL_UNPACK_BUFFER         : return "GL_PIXEL_UNPACK_BUFFER";
    case GL_SHADER_STORAGE_BUFFER       : return "GL_SHADER_STORAGE_BUFFER";
    case GL_TRANSFORM_FEEDBACK_BUFFER   : return "GL_TRANSFORM_FEEDBACK_BUFFER";
    case GL_UNIFORM_BUFFER              : return "GL_UNIFORM_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_usage_str (GLenum usage)
{
    switch (usage)
    {
    case GL_STREAM_DRAW                 : return "GL_STREAM_DRAW";
    case GL_STREAM_READ                 : return "GL_STREAM_READ";
    case GL_STREAM_COPY                 : return "GL_STREAM_COPY";
    case GL_STATIC_DRAW                 : return "GL_STATIC_DRAW";
    case GL_STATIC_READ                 : return "GL_STATIC_READ";
    case GL_STATIC_COPY                 : return "GL_STATIC_COPY";
    case GL_DYNAMIC_DRAW                : return "GL_DYNAMIC_DRAW";
    case GL_DYNAMIC_READ                : return "GL_DYNAMIC_READ";
    case GL_DYNAMIC_COPY                : return "GL_DYNAMIC_COPY";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", usage);
    return s_strbuf;
}



#define glBufferData_   \
    ((void (*)(GLenum target, GLsizeiptr size, const void *data, GLenum usage)) \
    GLES_ENTRY_PTR(glBufferData_Idx))

#define glBufferSubData_   \
    ((void (*)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data)) \
    GLES_ENTRY_PTR(glBufferSubData_Idx))


GL_APICALL void GL_APIENTRY
glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
    prepare_gles_tracer ();

    glBufferData_ (target, size, data, usage);

    fprintf (g_log_fp, "glBufferData(%s, %ld, %p, %s);\n",
                get_target_str (target), size, data,
                get_usage_str (usage));

    s_count ++;
}

GL_APICALL void GL_APIENTRY
glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
{
    prepare_gles_tracer ();

    glBufferSubData_ (target, offset, size, data);

    fprintf (g_log_fp, "glBufferSubData(%s, %ld, %ld, %p);\n",
                get_target_str (target), offset, size, data);

    s_count ++;
}

