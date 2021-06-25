#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_caps_str (GLenum cap)
{
    switch (cap)
    {
    case GL_PRIMITIVE_RESTART_FIXED_INDEX : return "GL_PRIMITIVE_RESTART_FIXED_INDEX";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", cap);
    return s_strbuf;
}


#define glIsEnabledi_   \
    ((GLboolean (*)(GLenum target, GLuint index)) \
    GLES_ENTRY_PTR(glIsEnabledi_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsEnabledi (GLenum target, GLuint index)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsEnabledi_ (target, index);

    fprintf (g_log_fp, "glIsEnabledi(%s, %d); // ret=%d\n",
             get_caps_str (target), index, ret);

    return ret;
}

