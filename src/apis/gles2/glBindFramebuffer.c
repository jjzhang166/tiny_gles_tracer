#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_FRAMEBUFFER                 : return "GL_FRAMEBUFFER";
    case GL_READ_FRAMEBUFFER            : return "GL_READ_FRAMEBUFFER";
    case GL_DRAW_FRAMEBUFFER            : return "GL_DRAW_FRAMEBUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glBindFramebuffer_   \
    ((void (*)(GLenum target, GLuint framebuffer))  \
    GLES_ENTRY_PTR(glBindFramebuffer_Idx))


GL_APICALL void GL_APIENTRY
glBindFramebuffer (GLenum target, GLuint framebuffer)
{
    prepare_gles_tracer ();

    glBindFramebuffer_ (target, framebuffer);

    fprintf (g_log_fp, "glBindFramebuffer(%s, %d);\n", 
             get_target_str (target), framebuffer);
}

