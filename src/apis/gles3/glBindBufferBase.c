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


#define glBindBufferBase_   \
    ((void (*)(GLenum target, GLuint index, GLuint buffer))  \
    GLES_ENTRY_PTR(glBindBufferBase_Idx))


GL_APICALL void GL_APIENTRY
glBindBufferBase (GLenum target, GLuint index, GLuint buffer)
{
    prepare_gles_tracer ();

    glBindBufferBase_ (target, index, buffer);

    fprintf (g_log_fp, "glBindBufferBase(%s, %d, %d);\n",
             get_target_str (target), index, buffer);
}

