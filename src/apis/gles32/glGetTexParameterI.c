#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_2D                       : return "GL_TEXTURE_2D";
    case GL_TEXTURE_2D_ARRAY                 : return "GL_TEXTURE_2D_ARRAY";
    case GL_TEXTURE_3D                       : return "GL_TEXTURE_3D";
    case GL_TEXTURE_CUBE_MAP                 : return "GL_TEXTURE_CUBE_MAP";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}

static char *
get_pname_str (GLenum name)
{
    switch (name)
    {
    case GL_DEPTH_STENCIL_TEXTURE_MODE              : return "GL_DEPTH_STENCIL_TEXTURE_MODE";
    case GL_TEXTURE_BASE_LEVEL                      : return "GL_TEXTURE_BASE_LEVEL";
    case GL_TEXTURE_COMPARE_FUNC                    : return "GL_TEXTURE_COMPARE_FUNC";
    case GL_TEXTURE_COMPARE_MODE                    : return "GL_TEXTURE_COMPARE_MODE";
    case GL_TEXTURE_IMMUTABLE_FORMAT                : return "GL_TEXTURE_IMMUTABLE_FORMAT";
    case GL_TEXTURE_IMMUTABLE_LEVELS                : return "GL_TEXTURE_IMMUTABLE_LEVELS";
    case GL_TEXTURE_MAG_FILTER                      : return "GL_TEXTURE_MAG_FILTER";
    case GL_TEXTURE_MAX_LEVEL                       : return "GL_TEXTURE_MAX_LEVEL";
    case GL_TEXTURE_MAX_LOD                         : return "GL_TEXTURE_MAX_LOD";
    case GL_TEXTURE_MIN_FILTER                      : return "GL_TEXTURE_MIN_FILTER";
    case GL_TEXTURE_MIN_LOD                         : return "GL_TEXTURE_MIN_LOD";
    case GL_TEXTURE_SWIZZLE_R                       : return "GL_TEXTURE_SWIZZLE_R";
    case GL_TEXTURE_SWIZZLE_G                       : return "GL_TEXTURE_SWIZZLE_G";
    case GL_TEXTURE_SWIZZLE_B                       : return "GL_TEXTURE_SWIZZLE_B";
    case GL_TEXTURE_SWIZZLE_A                       : return "GL_TEXTURE_SWIZZLE_A";
    case GL_TEXTURE_WRAP_S                          : return "GL_TEXTURE_WRAP_S";
    case GL_TEXTURE_WRAP_T                          : return "GL_TEXTURE_WRAP_T";
    case GL_TEXTURE_WRAP_R                          : return "GL_TEXTURE_WRAP_R";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetTexParameterIiv_   \
    ((void (*)(GLenum target, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetTexParameterIiv_Idx))

#define glGetTexParameterIuiv_   \
    ((void (*)(GLenum target, GLenum pname, GLuint *params))  \
    GLES_ENTRY_PTR(glGetTexParameterIuiv_Idx))


GL_APICALL void GL_APIENTRY
glGetTexParameterIiv (GLenum target, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetTexParameterIiv_ (target, pname, params);

    fprintf (g_log_fp, "glGetTexParameterIiv(%s, %s, %p);", 
             get_target_str (target),
             get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}

GL_APICALL void GL_APIENTRY
glGetTexParameterIuiv (GLenum target, GLenum pname, GLuint *params)
{
    prepare_gles_tracer ();

    glGetTexParameterIuiv_ (target, pname, params);

    fprintf (g_log_fp, "glGetTexParameterIuiv(%s, %s, %p);", 
             get_target_str (target),
             get_pname_str (pname), params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}
