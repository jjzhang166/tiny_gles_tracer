#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_ARRAY_BUFFER                : return "GL_ARRAY_BUFFER";
    case GL_ELEMENT_ARRAY_BUFFER        : return "GL_ELEMENT_ARRAY_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glBindBufferRange_   \
    ((void (*)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size))  \
    GLES_ENTRY_PTR(glBindBufferRange_Idx))


GL_APICALL void GL_APIENTRY
glBindBufferRange (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
{
    prepare_gles_tracer ();

    glBindBufferRange_ (target, index, buffer, offset, size);

    fprintf (g_log_fp, "glBindBufferRange(%s, %d, %d, %ld, %ld);\n",
             get_target_str (target), index, buffer, offset, size);
}

