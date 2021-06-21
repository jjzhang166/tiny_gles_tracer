#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_buffer_str (GLenum target)
{
    switch (target)
    {
    case GL_COLOR           : return "GL_COLOR";
    case GL_DEPTH           : return "GL_DEPTH";
    case GL_STENCIL         : return "GL_STENCIL";
    case GL_DEPTH_STENCIL   : return "GL_DEPTH_STENCIL";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", target);
    return s_strbuf;
}


#define glClearBufferiv_   \
    ((void (*)(GLenum buffer, GLint drawbuffer, const GLint *value))  \
    GLES_ENTRY_PTR(glClearBufferiv_Idx))

#define glClearBufferuiv_   \
    ((void (*)(GLenum buffer, GLint drawbuffer, const GLuint *value))  \
    GLES_ENTRY_PTR(glClearBufferuiv_Idx))

#define glClearBufferfv_   \
    ((void (*)(GLenum buffer, GLint drawbuffer, const GLfloat *value))  \
    GLES_ENTRY_PTR(glClearBufferfv_Idx))

#define glClearBufferfi_   \
    ((void (*)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil))  \
    GLES_ENTRY_PTR(glClearBufferfi_Idx))


GL_APICALL void GL_APIENTRY
glClearBufferiv (GLenum buffer, GLint drawbuffer, const GLint *value)
{
    prepare_gles_tracer ();

    glClearBufferiv_ (buffer, drawbuffer, value);

    fprintf (g_log_fp, "glClearBufferiv(%s, %d, %p);\n",
             get_buffer_str (buffer), drawbuffer, value);
}

GL_APICALL void GL_APIENTRY
glClearBufferuiv (GLenum buffer, GLint drawbuffer, const GLuint *value)
{
    prepare_gles_tracer ();

    glClearBufferuiv_ (buffer, drawbuffer, value);

    fprintf (g_log_fp, "glClearBufferuiv(%s, %d, %p);\n",
             get_buffer_str (buffer), drawbuffer, value);
}

GL_APICALL void GL_APIENTRY
glClearBufferfv (GLenum buffer, GLint drawbuffer, const GLfloat *value)
{
    prepare_gles_tracer ();

    glClearBufferfv_ (buffer, drawbuffer, value);

    fprintf (g_log_fp, "glClearBufferfv(%s, %d, %p);\n",
             get_buffer_str (buffer), drawbuffer, value);
}

GL_APICALL void GL_APIENTRY
glClearBufferfi (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
    prepare_gles_tracer ();

    glClearBufferfi_ (buffer, drawbuffer, depth, stencil);

    fprintf (g_log_fp, "glClearBufferfi(%s, %d, %f, %d);\n",
             get_buffer_str (buffer), drawbuffer, depth, stencil);
}
