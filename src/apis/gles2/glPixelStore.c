#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_PACK_ROW_LENGTH             : return "GL_PACK_ROW_LENGTH";
//  case GL_PACK_IMAGE_HEIGHT           : return "GL_PACK_IMAGE_HEIGHT";
    case GL_PACK_SKIP_PIXELS            : return "GL_PACK_SKIP_PIXELS";
    case GL_PACK_SKIP_ROWS              : return "GL_PACK_SKIP_ROWS";
//  case GL_PACK_SKIP_IMAGES            : return "GL_PACK_SKIP_IMAGES";
    case GL_PACK_ALIGNMENT              : return "GL_PACK_ALIGNMENT";

    case GL_UNPACK_ROW_LENGTH           : return "GL_UNPACK_ROW_LENGTH";
    case GL_UNPACK_IMAGE_HEIGHT         : return "GL_UNPACK_IMAGE_HEIGHT";
    case GL_UNPACK_SKIP_PIXELS          : return "GL_UNPACK_SKIP_PIXELS";
    case GL_UNPACK_SKIP_ROWS            : return "GL_UNPACK_SKIP_ROWS";
    case GL_UNPACK_SKIP_IMAGES          : return "GL_UNPACK_SKIP_IMAGES";
    case GL_UNPACK_ALIGNMENT            : return "GL_UNPACK_ALIGNMENT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glPixelStorei_   \
    ((void (*)(GLenum pname, GLint param)) \
    GLES_ENTRY_PTR(glPixelStorei_Idx))


GL_APICALL void GL_APIENTRY
glPixelStorei (GLenum pname, GLint param)
{
    prepare_gles_tracer ();

    glPixelStorei_ (pname, param);

    fprintf (g_log_fp, "glPixelStorei(%s, %d);\n",
             get_pname_str (pname), param);
}
