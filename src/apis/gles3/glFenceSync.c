#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_condition_str (GLenum condition)
{
    switch (condition)
    {
    case GL_SYNC_GPU_COMMANDS_COMPLETE  : return "GL_SYNC_GPU_COMMANDS_COMPLETE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", condition);
    return s_strbuf;
}


#define glFenceSync_         \
    ((GLsync (*)(GLenum condition, GLbitfield flags))   \
    GLES_ENTRY_PTR(glFenceSync_Idx))


GL_APICALL GLsync GL_APIENTRY
glFenceSync (GLenum condition, GLbitfield flags)
{
    prepare_gles_tracer ();

    GLsync sync = glFenceSync_ (condition, flags);
    fprintf (g_log_fp, "glFenceSync(%s, 0x%x); // sync=%p\n",
             get_condition_str (condition), flags, sync);

    return sync;
}

