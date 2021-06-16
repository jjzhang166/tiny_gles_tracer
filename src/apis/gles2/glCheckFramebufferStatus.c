#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
//  case GL_FRAMEBUFFER                 : return "GL_FRAMEBUFFER";
    case GL_DRAW_FRAMEBUFFER            : return "GL_DRAW_FRAMEBUFFER";
    case GL_READ_FRAMEBUFFER            : return "GL_READ_FRAMEBUFFER ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_status_str (GLenum status)
{
    switch (status)
    {
    case GL_FRAMEBUFFER_COMPLETE                : return "GL_FRAMEBUFFER_COMPLETE";
    case GL_FRAMEBUFFER_UNDEFINED               : return "GL_FRAMEBUFFER_UNDEFINED";
    case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT   : return "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";
    case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT : return "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";
    case GL_FRAMEBUFFER_UNSUPPORTED             : return "GL_FRAMEBUFFER_UNSUPPORTED";
    case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE  : return "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", status);
    return s_strbuf;
}


#define glCheckFramebufferStatus_   \
    ((GLenum (*)(GLenum target)) \
    GLES_ENTRY_PTR(glCheckFramebufferStatus_Idx))


GL_APICALL GLenum GL_APIENTRY
glCheckFramebufferStatus (GLenum target)
{
    prepare_gles_tracer ();

    GLenum ret = glCheckFramebufferStatus_ (target);

    fprintf (g_log_fp, "glCheckFramebufferStatus(%s); // %s\n",
                get_target_str (target), 
                get_status_str (ret));
    return ret;
}
