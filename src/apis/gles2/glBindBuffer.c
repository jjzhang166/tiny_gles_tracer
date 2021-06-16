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


#define glBindBuffer_   \
    ((void (*)(GLenum target, GLuint buffer))  \
    GLES_ENTRY_PTR(glBindBuffer_Idx))


GL_APICALL void GL_APIENTRY
glBindBuffer (GLenum target, GLuint buffer)
{
    prepare_gles_tracer ();

    glBindBuffer_ (target, buffer);

    fprintf (g_log_fp, "glBindBuffer(%s, %d);\n",
             get_target_str (target), buffer);
}

