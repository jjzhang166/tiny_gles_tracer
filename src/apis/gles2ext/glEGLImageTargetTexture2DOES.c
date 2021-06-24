#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_target_str (GLenum target)
{
    switch (target)
    {
    case GL_TEXTURE_2D                  : return "GL_TEXTURE_2D";
    case GL_TEXTURE_CUBE_MAP            : return "GL_TEXTURE_CUBE_MAP";
    case GL_TEXTURE_EXTERNAL_OES        : return "GL_TEXTURE_EXTERNAL_OES";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glEGLImageTargetTexture2DOES_   \
    ((void (*)(GLenum target, GLeglImageOES image))  \
    GLES_ENTRY_PTR(glEGLImageTargetTexture2DOES_Idx))


GL_APICALL void GL_APIENTRY
glEGLImageTargetTexture2DOES (GLenum target, GLeglImageOES image)
{
    prepare_gles_tracer ();

    glEGLImageTargetTexture2DOES_ (target, image);

    fprintf (g_log_fp, "glEGLImageTargetTexture2DOES(%s, %p);\n",
             get_target_str (target), image);
}

