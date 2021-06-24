#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_COLOR_EXT                   : return "GL_COLOR_EXT";
    case GL_DEPTH_EXT                   : return "GL_DEPTH_EXT";
    case GL_STENCIL_EXT                 : return "GL_STENCIL_EXT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glDiscardFramebufferEXT_   \
    ((void (*)(GLenum target, GLsizei numAttachments, const GLenum *attachments))  \
    GLES_ENTRY_PTR(glDiscardFramebufferEXT_Idx))


GL_APICALL void GL_APIENTRY
glDiscardFramebufferEXT (GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
    prepare_gles_tracer ();

    glDiscardFramebufferEXT_ (target, numAttachments, attachments);

    fprintf (g_log_fp, "glDiscardFramebufferEXT(%s, %d, %p);\n",
             get_target_str (target), numAttachments, attachments);
}

