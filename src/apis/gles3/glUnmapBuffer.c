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

#define glUnmapBuffer_   \
    ((GLboolean (*)(GLenum target))  \
    GLES_ENTRY_PTR(glUnmapBuffer_Idx))


GL_APICALL GLboolean GL_APIENTRY
glUnmapBuffer (GLenum target)
{
    prepare_gles_tracer ();

    GLboolean ret = glUnmapBuffer_ (target);

    fprintf (g_log_fp, "glUnmapBuffer(%s); // ret=%d\n",
             get_target_str (target), ret);

    return ret;
}

