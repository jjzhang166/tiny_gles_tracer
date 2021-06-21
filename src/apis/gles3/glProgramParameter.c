#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_pname_str (GLenum pname)
{
    switch (pname)
    {
    case GL_PROGRAM_BINARY_RETRIEVABLE_HINT : return "GL_PROGRAM_BINARY_RETRIEVABLE_HINT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", pname);
    return s_strbuf;
}


#define glProgramParameteri_         \
    ((void (*)(GLuint program, GLenum pname, GLint value))   \
    GLES_ENTRY_PTR(glProgramParameteri_Idx))


GL_APICALL void GL_APIENTRY
glProgramParameteri (GLuint program, GLenum pname, GLint value)
{
    prepare_gles_tracer ();

    glProgramParameteri_ (program, pname, value);

    fprintf (g_log_fp, "glProgramParameteri(%d, %s, %d);\n",
             program, get_pname_str (pname), value);
}

