#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_tex_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_2D                  : return "GL_TEXTURE_2D";
    case GL_TEXTURE_3D                  : return "GL_TEXTURE_3D";
    case GL_TEXTURE_2D_ARRAY            : return "GL_TEXTURE_2D_ARRAY";
    case GL_TEXTURE_CUBE_MAP            : return "GL_TEXTURE_CUBE_MAP";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_tex_pname_str (GLenum type)
{
    switch (type)
    {
    case GL_DEPTH_STENCIL_TEXTURE_MODE  : return "GL_DEPTH_STENCIL_TEXTURE_MODE";
    case GL_TEXTURE_BASE_LEVEL          : return "GL_TEXTURE_BASE_LEVEL";
    case GL_TEXTURE_COMPARE_FUNC        : return "GL_TEXTURE_COMPARE_FUNC";
    case GL_TEXTURE_COMPARE_MODE        : return "GL_TEXTURE_COMPARE_MODE";
    case GL_TEXTURE_MIN_FILTER          : return "GL_TEXTURE_MIN_FILTER";
    case GL_TEXTURE_MAG_FILTER          : return "GL_TEXTURE_MAG_FILTER";
    case GL_TEXTURE_MIN_LOD             : return "GL_TEXTURE_MIN_LOD";
    case GL_TEXTURE_MAX_LOD             : return "GL_TEXTURE_MAX_LOD";
    case GL_TEXTURE_MAX_LEVEL           : return "GL_TEXTURE_MAX_LEVEL";
    case GL_TEXTURE_SWIZZLE_R           : return "GL_TEXTURE_SWIZZLE_R";
    case GL_TEXTURE_SWIZZLE_G           : return "GL_TEXTURE_SWIZZLE_G";
    case GL_TEXTURE_SWIZZLE_B           : return "GL_TEXTURE_SWIZZLE_B";
    case GL_TEXTURE_SWIZZLE_A           : return "GL_TEXTURE_SWIZZLE_A";
    case GL_TEXTURE_WRAP_S              : return "GL_TEXTURE_WRAP_S";
    case GL_TEXTURE_WRAP_T              : return "GL_TEXTURE_WRAP_T";
    case GL_TEXTURE_WRAP_R              : return "GL_TEXTURE_WRAP_R";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}

static char *
get_tex_filter_str (uint32_t filter)
{
    switch (filter)
    {
    case GL_NEAREST                     : return "GL_NEAREST";
    case GL_LINEAR                      : return "GL_LINEAR";
    case GL_NEAREST_MIPMAP_NEAREST      : return "GL_NEAREST_MIPMAP_NEAREST";
    case GL_LINEAR_MIPMAP_NEAREST       : return "GL_LINEAR_MIPMAP_NEAREST";
    case GL_NEAREST_MIPMAP_LINEAR       : return "GL_NEAREST_MIPMAP_LINEAR";
    case GL_LINEAR_MIPMAP_LINEAR        : return "GL_LINEAR_MIPMAP_LINEAR";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", filter);
    return s_strbuf;
}

static char *
get_tex_wrapmode_str (uint32_t filter)
{
    switch (filter)
    {
    case GL_CLAMP_TO_EDGE               : return "GL_CLAMP_TO_EDGE";
    case GL_MIRRORED_REPEAT             : return "GL_MIRRORED_REPEAT";
    case GL_REPEAT                      : return "GL_REPEAT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", filter);
    return s_strbuf;
}


#define glTexParameterf_   \
    ((void (*)(GLenum target, GLenum pname, GLfloat param)) \
    GLES_ENTRY_PTR(glTexParameterf_Idx))

#define glTexParameterfv_   \
    ((void (*)(GLenum target, GLenum pname, const GLfloat *params)) \
    GLES_ENTRY_PTR(glTexParameterfv_Idx))

#define glTexParameteri_   \
    ((void (*)(GLenum target, GLenum pname, GLint param)) \
    GLES_ENTRY_PTR(glTexParameteri_Idx))

#define glTexParameteriv_   \
    ((void (*)(GLenum target, GLenum pname, const GLint *params)) \
    GLES_ENTRY_PTR(glTexParameteriv_Idx))


GL_APICALL void GL_APIENTRY
glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
    prepare_gles_tracer ();

    glTexParameterf_ (target, pname, param);


    char param_str[32], *param_str_ptr;
    snprintf (param_str, sizeof(param_str), "%f", param);

    switch (pname)
    {
    case GL_TEXTURE_MIN_FILTER:
    case GL_TEXTURE_MAG_FILTER:
        param_str_ptr = get_tex_filter_str ((uint32_t)param);
        break;
    case GL_TEXTURE_WRAP_S:
    case GL_TEXTURE_WRAP_T:
    case GL_TEXTURE_WRAP_R:
        param_str_ptr = get_tex_wrapmode_str ((uint32_t)param);
        break;
    default:
        param_str_ptr = param_str;
    }
    
    fprintf (g_log_fp, "glTexParameterf(%s, %s, %s);",
                get_tex_target_str (target),
                get_tex_pname_str (pname), param_str_ptr);
    fprintf (g_log_fp, "\n");
}

GL_APICALL void GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params)
{
    prepare_gles_tracer ();

    glTexParameterfv_ (target, pname, params);

    fprintf (g_log_fp, "glTexParameterfv(%s, %s, %p);",
                get_tex_target_str (target),
                get_tex_pname_str (pname), params);
    fprintf (g_log_fp, "\n");
}

GL_APICALL void GL_APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param)
{
    prepare_gles_tracer ();

    glTexParameteri_ (target, pname, param);


    char param_str[32], *param_str_ptr;
    snprintf (param_str, sizeof(param_str), "0x%x", param);

    switch (pname)
    {
    case GL_TEXTURE_MIN_FILTER:
    case GL_TEXTURE_MAG_FILTER:
        param_str_ptr = get_tex_filter_str ((uint32_t)param);
        break;
    case GL_TEXTURE_WRAP_S:
    case GL_TEXTURE_WRAP_T:
    case GL_TEXTURE_WRAP_R:
        param_str_ptr = get_tex_wrapmode_str ((uint32_t)param);
        break;
    default:
        param_str_ptr = param_str;
    }
    
    fprintf (g_log_fp, "glTexParameteri(%s, %s, %s);",
                get_tex_target_str (target),
                get_tex_pname_str (pname), param_str_ptr);
    fprintf (g_log_fp, "\n");
}

GL_APICALL void GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params)
{
    prepare_gles_tracer ();

    glTexParameteriv_ (target, pname, params);

    fprintf (g_log_fp, "glTexParameteriv(%s, %s, %p);",
                get_tex_target_str (target),
                get_tex_pname_str (pname), params);
    fprintf (g_log_fp, "\n");
}

