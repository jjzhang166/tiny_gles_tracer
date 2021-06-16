#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum name)
{
    switch (name)
    {
    case GL_ARRAY_BUFFER                    : return "GL_ARRAY_BUFFER";
    case GL_ELEMENT_ARRAY_BUFFER            : return "GL_ELEMENT_ARRAY_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

static char *
get_pname_str (GLenum name)
{
    switch (name)
    {
    case GL_BUFFER_SIZE                     : return "GL_BUFFER_SIZE";
    case GL_BUFFER_USAGE                    : return "GL_BUFFER_USAGE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetBufferParameteriv_   \
    ((void (*)(GLenum target, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetBufferParameteriv_Idx))


GL_APICALL void GL_APIENTRY
glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetBufferParameteriv_ (target, pname, params);

    fprintf (g_log_fp, "glGetBufferParameteriv(%-30s, %s, %p);", 
             get_target_str (target),
             get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // data = %d\n", *params);
}

