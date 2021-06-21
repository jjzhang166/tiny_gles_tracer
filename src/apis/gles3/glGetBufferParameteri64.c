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

#define glGetBufferParameteri64v_   \
    ((void (*)(GLenum target, GLenum pname, GLint64 *params))  \
    GLES_ENTRY_PTR(glGetBufferParameteri64v_Idx))


GL_APICALL void GL_APIENTRY
glGetBufferParameteri64v (GLenum target, GLenum pname, GLint64 *params)
{
    prepare_gles_tracer ();

    glGetBufferParameteri64v_ (target, pname, params);

    fprintf (g_log_fp, "glGetBufferParameteri64v(%-30s, %s, %p);", 
             get_target_str (target),
             get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // data = %ld\n", *params);
}

