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
    case GL_MAX_SAMPLES                     : return "GL_MAX_SAMPLES";
    case GL_RED_BITS                        : return "GL_RED_BITS";
    case GL_GREEN_BITS                      : return "GL_GREEN_BITS";
    case GL_BLUE_BITS                       : return "GL_BLUE_BITS";
    case GL_ALPHA_BITS                      : return "GL_ALPHA_BITS";
    case GL_DEPTH_BITS                      : return "GL_DEPTH_BITS";
    case GL_STENCIL_BITS                    : return "GL_STENCIL_BITS";
    case GL_NUM_SHADER_BINARY_FORMATS       : return "GL_NUM_SHADER_BINARY_FORMATS";
    case GL_NUM_PROGRAM_BINARY_FORMATS      : return "GL_NUM_PROGRAM_BINARY_FORMATS";
    case GL_CURRENT_PROGRAM                 : return "GL_CURRENT_PROGRAM";
    case GL_ACTIVE_TEXTURE                  : return "GL_ACTIVE_TEXTURE";
    case GL_TEXTURE_BINDING_2D              : return "GL_TEXTURE_BINDING_2D";
    case GL_FRAMEBUFFER_BINDING             : return "GL_FRAMEBUFFER_BINDING";
    case GL_ARRAY_BUFFER_BINDING            : return "GL_ARRAY_BUFFER_BINDING";
    case GL_VIEWPORT                        : return "GL_VIEWPORT";
    case GL_SCISSOR_BOX                     : return "GL_SCISSOR_BOX";
    case GL_DEPTH_WRITEMASK                 : return "GL_DEPTH_WRITEMASK";
    case GL_COLOR_WRITEMASK                 : return "GL_COLOR_WRITEMASK";
    case GL_BLEND_DST_RGB                   : return "GL_BLEND_DST_RGB";
    case GL_BLEND_SRC_RGB                   : return "GL_BLEND_SRC_RGB";
    case GL_BLEND_DST_ALPHA                 : return "GL_BLEND_DST_ALPHA";
    case GL_BLEND_SRC_ALPHA                 : return "GL_BLEND_SRC_ALPHA";
    case GL_BLEND_EQUATION                  : return "GL_BLEND_EQUATION";
    case GL_BLEND_EQUATION_ALPHA            : return "GL_BLEND_EQUATION_ALPHA";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetIntegeri_v_   \
    ((void (*)(GLenum target, GLuint index, GLint *data))  \
    GLES_ENTRY_PTR(glGetIntegeri_v_Idx))


GL_APICALL void GL_APIENTRY
glGetIntegeri_v (GLenum target, GLuint index, GLint *data)
{
    prepare_gles_tracer ();

    glGetIntegeri_v_ (target, index, data);

    fprintf (g_log_fp, "glGetIntegeri_v(%s, %d, %p);", get_query_name_str (target), index, data);
    if (data) fprintf (g_log_fp, " // data = %d\n", *data);
}

