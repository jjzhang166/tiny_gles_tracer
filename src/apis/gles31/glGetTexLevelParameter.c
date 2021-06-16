#include <stdio.h>
#include "GLEStrace.h"


#define glGetTexLevelParameteriv_   \
    ((void (*)(GLenum target, GLint level, GLenum pname, GLint *params))  \
    GLES_ENTRY_PTR(glGetTexLevelParameteriv_Idx))

#define glGetTexLevelParameterfv_   \
    ((void (*)(GLenum target, GLint level, GLenum pname, GLfloat *params))  \
    GLES_ENTRY_PTR(glGetTexLevelParameterfv_Idx))


GL_APICALL void GL_APIENTRY
glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params)
{
    prepare_gles_tracer ();

    glGetTexLevelParameteriv_ (target, level, pname, params);

    fprintf (g_log_fp, "glGetTexLevelParameteriv(%d, %d, %d, %p);", target, level, pname, params);
    if (params) fprintf (g_log_fp, " // val = %d\n", *params);
}


GL_APICALL void GL_APIENTRY
glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params)
{
    prepare_gles_tracer ();

    glGetTexLevelParameterfv_ (target, level, pname, params);

    fprintf (g_log_fp, "glGetTexLevelParameterfv(%d, %d, %d, %p);", target, level, pname, params);
    if (params) fprintf (g_log_fp, " // val = %f\n", *params);
}
