#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_PATCH_VERTICES : return "GL_PATCH_VERTICES ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glPatchParameteri_   \
    ((void (*)(GLenum pname, GLint value))  \
    GLES_ENTRY_PTR(glPatchParameteri_Idx))


GL_APICALL void GL_APIENTRY
glPatchParameteri (GLenum pname, GLint value)
{
    prepare_gles_tracer ();

    glPatchParameteri_ (pname, value);

    fprintf (g_log_fp, "glPatchParameteri(%s, %d);\n",
             get_pname_str (pname), value);
}

