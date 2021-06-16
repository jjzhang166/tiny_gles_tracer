#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_FRAGMENT_SHADER_DERIVATIVE_HINT : return "GL_FRAGMENT_SHADER_DERIVATIVE_HINT";
    case GL_GENERATE_MIPMAP_HINT            : return "GL_GENERATE_MIPMAP_HINT ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_mode_str (GLenum mode)
{
    switch (mode)
    {
    case GL_FASTEST                         : return "GL_FASTEST";
    case GL_NICEST                          : return "GL_NICEST";
    case GL_DONT_CARE                       : return "GL_DONT_CARE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", mode);
    return s_strbuf;
}


#define glHint_   \
    ((void (*)(GLenum target, GLenum mode))  \
    GLES_ENTRY_PTR(glHint_Idx))


GL_APICALL void GL_APIENTRY
glHint (GLenum target, GLenum mode)
{
    prepare_gles_tracer ();

    glHint_ (target, mode);

    fprintf (g_log_fp, "glHint(%s, %s);\n", 
             get_target_str (target), get_mode_str (mode));
}

