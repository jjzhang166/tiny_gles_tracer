#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_RENDERBUFFER                : return "GL_RENDERBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glBindRenderbuffer_   \
    ((void (*)(GLenum target, GLuint renderbuffer))  \
    GLES_ENTRY_PTR(glBindRenderbuffer_Idx))


GL_APICALL void GL_APIENTRY
glBindRenderbuffer (GLenum target, GLuint renderbuffer)
{
    prepare_gles_tracer ();

    glBindRenderbuffer_ (target, renderbuffer);

    fprintf (g_log_fp, "glBindRenderbuffer(%s, %d);\n", 
             get_target_str (target), renderbuffer);
}

