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


#define glWaitSync_         \
    ((void (*)(GLsync sync, GLbitfield flags, GLuint64 timeout))   \
    GLES_ENTRY_PTR(glWaitSync_Idx))


GL_APICALL void GL_APIENTRY
glWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout)
{
    prepare_gles_tracer ();

    glWaitSync_ (sync, flags, timeout);

    fprintf (g_log_fp, "glWaitSync(%p, %s, %ld);\n",
             sync, get_flags_str (flags), timeout);
}

