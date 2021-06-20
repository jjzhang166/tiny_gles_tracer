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

#define glMapBufferRange_   \
    ((void * (*)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access))  \
    GLES_ENTRY_PTR(glMapBufferRange_Idx))


GL_APICALL void *GL_APIENTRY
glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
    prepare_gles_tracer ();

    void *ret = glMapBufferRange_ (target, offset, length, access);

    fprintf (g_log_fp, "glMapBufferRange(%s, %ld, %ld, 0x%x); // ret=%p\n",
             get_target_str (target), offset, length, access, ret);

    return ret;
}

