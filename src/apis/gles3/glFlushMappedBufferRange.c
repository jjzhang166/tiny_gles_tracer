#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_ARRAY_BUFFER                : return "GL_ARRAY_BUFFER";
    case GL_COPY_READ_BUFFER            : return "GL_COPY_READ_BUFFER";
    case GL_COPY_WRITE_BUFFER           : return "GL_COPY_WRITE_BUFFER";
    case GL_ELEMENT_ARRAY_BUFFER        : return "GL_ELEMENT_ARRAY_BUFFER";
    case GL_PIXEL_PACK_BUFFER           : return "GL_PIXEL_PACK_BUFFER";
    case GL_PIXEL_UNPACK_BUFFER         : return "GL_PIXEL_UNPACK_BUFFER";
    case GL_TRANSFORM_FEEDBACK_BUFFER   : return "GL_TRANSFORM_FEEDBACK_BUFFER";
    case GL_UNIFORM_BUFFER              : return "GL_UNIFORM_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

#define glFlushMappedBufferRange_   \
    ((void (*)(GLenum target, GLintptr offset, GLsizeiptr length))  \
    GLES_ENTRY_PTR(glFlushMappedBufferRange_Idx))


GL_APICALL void GL_APIENTRY
glFlushMappedBufferRange (GLenum target, GLintptr offset, GLsizeiptr length)
{
    prepare_gles_tracer ();

    glFlushMappedBufferRange_ (target, offset, length);

    fprintf (g_log_fp, "glFlushMappedBufferRange(%s, %ld, %ld);\n",
             get_target_str (target), offset, length);
}

