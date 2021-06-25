#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_cap_str (GLenum cap)
{
    switch (cap)
    {
    case GL_PRIMITIVE_RESTART_FIXED_INDEX : return "GL_PRIMITIVE_RESTART_FIXED_INDEX";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", cap);
    return s_strbuf;
}

#define glDisablei_   \
    ((void (*)(GLenum target, GLuint index)) \
    GLES_ENTRY_PTR(glDisablei_Idx))


GL_APICALL void GL_APIENTRY
glDisablei (GLenum target, GLuint index)
{
    prepare_gles_tracer ();

    glDisablei_ (target, index);

    fprintf (g_log_fp, "glDisablei(%s, %d);\n", get_cap_str (target), index);
}
