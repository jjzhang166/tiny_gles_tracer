#include <stdio.h>
#include "GLEStrace.h"


#define glClear_   \
    ((void (*)(GLbitfield mask))  \
    GLES_ENTRY_PTR(glClear_Idx))

#define glClearColor_   \
    ((void (*)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha))  \
    GLES_ENTRY_PTR(glClearColor_Idx))

#define glClearDepthf_   \
    ((void (*)(GLfloat d))  \
    GLES_ENTRY_PTR(glClearDepthf_Idx))

#define glClearStencil_   \
    ((void (*)(GLint s))  \
    GLES_ENTRY_PTR(glClearStencil_Idx))


GL_APICALL void GL_APIENTRY
glClear (GLbitfield mask)
{
    prepare_gles_tracer ();

    glClear_ (mask);

    fprintf (g_log_fp, "glClear(");
    if (mask && GL_COLOR_BUFFER_BIT)   fprintf (g_log_fp, "GL_COLOR_BUFFER | ");
    if (mask && GL_DEPTH_BUFFER_BIT)   fprintf (g_log_fp, "GL_DEPTH_BUFFER | ");
    if (mask && GL_STENCIL_BUFFER_BIT) fprintf (g_log_fp, "GL_STENCIL_BUFFER");
    fprintf (g_log_fp, ")\n");
}


GL_APICALL void GL_APIENTRY
glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    prepare_gles_tracer ();

    glClearColor_ (red, green, blue, alpha);

    fprintf (g_log_fp, "glClearColor(%f, %f, %f, %f)\n", red, green, blue, alpha);
}


GL_APICALL void GL_APIENTRY
glClearDepthf (GLfloat d)
{
    prepare_gles_tracer ();

    glClearDepthf_ (d);

    fprintf (g_log_fp, "glClearDepthf(%f)\n", d);
}


GL_APICALL void GL_APIENTRY
glClearStencil (GLint s)
{
    prepare_gles_tracer ();

    glClearStencil_ (s);

    fprintf (g_log_fp, "glClearStencil(%d)\n", s);
}
