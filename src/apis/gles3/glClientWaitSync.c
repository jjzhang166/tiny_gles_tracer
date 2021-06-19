#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_flags_str (GLbitfield flags)
{
    switch (flags)
    {
    case GL_SYNC_FLUSH_COMMANDS_BIT  : return "GL_SYNC_FLUSH_COMMANDS_BIT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", flags);
    return s_strbuf;
}

static char *
get_ret_str (GLenum ret)
{
    switch (ret)
    {
    case GL_ALREADY_SIGNALED    : return "GL_ALREADY_SIGNALED";
    case GL_TIMEOUT_EXPIRED     : return "GL_TIMEOUT_EXPIRED";
    case GL_CONDITION_SATISFIED : return "GL_CONDITION_SATISFIED";
    case GL_WAIT_FAILED         : return "GL_WAIT_FAILED";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", ret);
    return s_strbuf;
}


#define glClientWaitSync_         \
    ((GLenum (*)(GLsync sync, GLbitfield flags, GLuint64 timeout))   \
    GLES_ENTRY_PTR(glClientWaitSync_Idx))


GL_APICALL GLenum GL_APIENTRY
glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    prepare_gles_tracer ();

    GLenum ret = glClientWaitSync_ (sync, flags, timeout);

    fprintf (g_log_fp, "glClientWaitSync(%p, %s, %ld); // ret=%s\n",
             sync, get_flags_str (flags), timeout, get_ret_str (ret));

    return ret;
}

