#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_SYNC_STATUS     : return "GL_SYNC_STATUS";
    case GL_SYNC_CONDITION  : return "GL_SYNC_CONDITION";
    case GL_SYNC_FLAGS      : return "GL_SYNC_FLAGS";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetSynciv_         \
    ((void (*)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values))   \
    GLES_ENTRY_PTR(glGetSynciv_Idx))


GL_APICALL void GL_APIENTRY
glGetSynciv (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)
{
    prepare_gles_tracer ();

    glGetSynciv_ (sync, pname, bufSize, length, values);

    fprintf (g_log_fp, "glGetSynciv(%p, %s, %d, %p, %p); //",
             sync, get_pname_str (pname), bufSize, length, values);

    if (length) fprintf (g_log_fp, "length=%d ", *length);
    if (values) fprintf (g_log_fp, "values=%d ", *values);
    fprintf (g_log_fp, "\n");
}

