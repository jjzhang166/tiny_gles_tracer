#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_stat_str (GLenum stat)
{
    switch (stat)
    {
    case GL_NO_ERROR                : return "GL_NO_ERROR";
    case GL_GUILTY_CONTEXT_RESET    : return "GL_GUILTY_CONTEXT_RESET";
    case GL_INNOCENT_CONTEXT_RESET  : return "GL_INNOCENT_CONTEXT_RESET";
    case GL_UNKNOWN_CONTEXT_RESET   : return "GL_UNKNOWN_CONTEXT_RESET";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", stat);
    return s_strbuf;
}

#define glGetGraphicsResetStatus_   \
    ((GLenum (*)(void))  \
    GLES_ENTRY_PTR(glGetGraphicsResetStatus_Idx))


GL_APICALL GLenum GL_APIENTRY
glGetGraphicsResetStatus (void)
{
    prepare_gles_tracer ();

    GLenum ret = glGetGraphicsResetStatus_ ();

    fprintf (g_log_fp, "glGetGraphicsResetStatus();");
    if (ret) fprintf (g_log_fp, " // ret=%s\n", get_stat_str (ret));

    return ret;
}

