#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_2D                  : return "GL_TEXTURE_2D";
    case GL_TEXTURE_3D                  : return "GL_TEXTURE_3D";
    case GL_TEXTURE_2D_ARRAY            : return "GL_TEXTURE_2D_ARRAY ";
    case GL_TEXTURE_CUBE_MAP            : return "GL_TEXTURE_CUBE_MAP";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glGenerateMipmap_   \
    ((void (*)(GLenum target))  \
    GLES_ENTRY_PTR(glGenerateMipmap_Idx))



GL_APICALL void GL_APIENTRY
glGenerateMipmap (GLenum target)
{
    prepare_gles_tracer ();

    glGenerateMipmap_ (target);

    fprintf (g_log_fp, "glGenerateMipmap(%s);\n", get_target_str (target));
}

