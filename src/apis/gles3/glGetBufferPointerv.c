#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_ARRAY_BUFFER                : return "GL_ARRAY_BUFFER";
    case GL_COPY_READ_BUFFER            : return "GL_COPY_READ_BUFFER";
    case GL_COPY_WRITE_BUFFER           : return "GL_COPY_WRITE_BUFFER";
    case GL_ELEMENT_ARRAY_BUFFER        : return "GL_ELEMENT_ARRAY_BUFFER";
    case GL_PIXEL_PACK_BUFFER           : return "GL_PIXEL_PACK_BUFFER";
    case GL_PIXEL_UNPACK_BUFFER         : return "GL_PIXEL_UNPACK_BUFFER";
    case GL_TRANSFORM_FEEDBACK_BUFFER   : return "GL_TRANSFORM_FEEDBACK_BUFFER";
    case GL_UNIFORM_BUFFER              : return "GL_UNIFORM_BUFFER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_BUFFER_MAP_POINTER          : return "GL_BUFFER_MAP_POINTER";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glGetBufferPointerv_   \
    ((void (*)(GLenum target, GLenum pname, void **params))  \
    GLES_ENTRY_PTR(glGetBufferPointerv_Idx))


GL_APICALL void GL_APIENTRY
glGetBufferPointerv (GLenum target, GLenum pname, void **params)
{
    prepare_gles_tracer ();

    glGetBufferPointerv_ (target, pname, params);

    fprintf (g_log_fp, "glGetBufferPointerv(%s, %s, %p);\n",
             get_target_str (target), get_pname_str (pname), params);
}

