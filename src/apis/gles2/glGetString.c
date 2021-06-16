#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_query_name_str (EGLint name)
{
    switch (name)
    {
    case GL_EXTENSIONS                  : return "GL_EXTENSIONS";
    case GL_VENDOR                      : return "GL_VENDOR";
    case GL_RENDERER                    : return "GL_RENDERER";
    case GL_VERSION                     : return "GL_VERSION";
    case GL_SHADING_LANGUAGE_VERSION    : return "GL_SHADING_LANGUAGE_VERSION";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", name);
    return s_strbuf;
}

#define glGetString_   \
    ((const GLubyte * (*)(GLenum name))  \
    GLES_ENTRY_PTR(glGetString_Idx))


GL_APICALL const GLubyte *GL_APIENTRY
glGetString (GLenum name)
{
    prepare_gles_tracer ();

    const GLubyte *str = glGetString_ (name);

    fprintf (g_log_fp, "glGetString(%-30s);", get_query_name_str (name));
    fprintf (g_log_fp, " // %s", str);

    if (name == GL_VERSION && g_force_gl_version_ptr)
    {
        str = g_force_gl_version_ptr;
        fprintf (g_log_fp, " ==> %s", str);
    }
    if (name == GL_VENDOR && g_force_gl_vendor_ptr)
    {
        str = g_force_gl_vendor_ptr;
        fprintf (g_log_fp, " ==> %s", str);
    }
    if (name == GL_RENDERER && g_force_gl_renderer_ptr)
    {
        str = g_force_gl_renderer_ptr;
        fprintf (g_log_fp, " ==> %s", str);
    }
    if (name == GL_EXTENSIONS && g_force_gl_extension_ptr)
    {
        str = g_force_gl_extension_ptr;
        fprintf (g_log_fp, " ==> %s", str);
    }

    fprintf (g_log_fp, "\n");

    return str;
}

