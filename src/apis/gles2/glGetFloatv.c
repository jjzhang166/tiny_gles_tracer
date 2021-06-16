#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_query_name_str (GLenum name)
{
    switch (name)
    {
    case GL_UNPACK_ALIGNMENT                : return "GL_UNPACK_ALIGNMENT";
    case GL_MAX_TEXTURE_IMAGE_UNITS         : return "GL_MAX_TEXTURE_IMAGE_UNITS";
    case GL_MAX_TEXTURE_SIZE                : return "GL_MAX_TEXTURE_SIZE";
    case GL_NUM_COMPRESSED_TEXTURE_FORMATS  : return "GL_NUM_COMPRESSED_TEXTURE_FORMATS";
    case GL_MAX_CUBE_MAP_TEXTURE_SIZE       : return "GL_MAX_CUBE_MAP_TEXTURE_SIZE";
    case GL_MAX_FRAGMENT_UNIFORM_VECTORS    : return "GL_MAX_FRAGMENT_UNIFORM_VECTORS";
    case GL_MAX_RENDERBUFFER_SIZE           : return "GL_MAX_RENDERBUFFER_SIZE";
    case GL_MAX_VARYING_VECTORS             : return "GL_MAX_VARYING_VECTORS";
    case GL_MAX_VERTEX_ATTRIBS              : return "GL_MAX_VERTEX_ATTRIBS";
    case GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS  : return "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS";
    case GL_RED_BITS                        : return "GL_RED_BITS";
    case GL_GREEN_BITS                      : return "GL_GREEN_BITS";
    case GL_BLUE_BITS                       : return "GL_BLUE_BITS";
    case GL_ALPHA_BITS                      : return "GL_ALPHA_BITS";
    case GL_DEPTH_BITS                      : return "GL_DEPTH_BITS";
    case GL_STENCIL_BITS                    : return "GL_STENCIL_BITS";
    case GL_NUM_SHADER_BINARY_FORMATS       : return "GL_NUM_SHADER_BINARY_FORMATS";
    case GL_NUM_PROGRAM_BINARY_FORMATS      : return "GL_NUM_PROGRAM_BINARY_FORMATS";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetFloatv_   \
    ((void (*)(GLenum pname, GLfloat *data))  \
    GLES_ENTRY_PTR(glGetFloatv_Idx))


GL_APICALL void GL_APIENTRY
glGetFloatv (GLenum pname, GLfloat *data)
{
    prepare_gles_tracer ();

    glGetFloatv_ (pname, data);

    fprintf (g_log_fp, "glGetFloatv(%-30s, %p);", get_query_name_str (pname), data);
    if (data) fprintf (g_log_fp, " // data = %f\n", *data);
}

