#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_READ_FRAMEBUFFER            : return "GL_READ_FRAMEBFUFFER";
    case GL_DRAW_FRAMEBUFFER            : return "GL_DRAW_FRAMEBUFFER ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glInvalidateFramebuffer_   \
    ((void (*)(GLenum target, GLsizei numAttachments, const GLenum *attachments))  \
    GLES_ENTRY_PTR(glInvalidateFramebuffer_Idx))


GL_APICALL void GL_APIENTRY
glInvalidateFramebuffer (GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glInvalidateFramebuffer(%s, %d, %p); // ",
             get_target_str (target), numAttachments, attachments);

    glInvalidateFramebuffer_ (target, numAttachments, attachments);

    fprintf (g_log_fp, "\n");
}

