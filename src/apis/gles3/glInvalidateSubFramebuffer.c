#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_READ_FRAMEBUFFER            : return "GL_READ_FRAMEBUFFER";
    case GL_DRAW_FRAMEBUFFER            : return "GL_DRAW_FRAMEBUFFER ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glInvalidateSubFramebuffer_   \
    ((void (*)(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height))  \
    GLES_ENTRY_PTR(glInvalidateSubFramebuffer_Idx))


GL_APICALL void GL_APIENTRY
glInvalidateSubFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glInvalidateSubFramebuffer(%s, %d, %p, %d, %d, %d, %d); // ",
             get_target_str (target), numAttachments, attachments, x, y, width, height);

    glInvalidateSubFramebuffer_ (target, numAttachments, attachments, x, y, width, height);

    fprintf (g_log_fp, "\n");
}

