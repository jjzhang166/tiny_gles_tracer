#include <stdio.h>
#include "GLEStrace.h"


#define glGetFramebufferParameteriv_   \
    ((void (*)(GLenum target, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetFramebufferParameteriv_Idx))


GL_APICALL void GL_APIENTRY
glGetFramebufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetFramebufferParameteriv_ (target, pname, params);

    fprintf (g_log_fp, "glGetFramebufferParameteriv(%d, %d, %p);", 
             target, pname, params);
    if (params) fprintf (g_log_fp, " // params = %d\n", *params);
}
