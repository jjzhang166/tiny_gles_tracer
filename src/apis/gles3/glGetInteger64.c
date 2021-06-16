#include <stdio.h>
#include "GLEStrace.h"


#define glGetInteger64v_   \
    ((void (*)(GLenum pname, GLint64 *data))  \
    GLES_ENTRY_PTR(glGetInteger64v_Idx))

#define glGetInteger64i_v_   \
    ((void (*)(GLenum target, GLuint index, GLint64 *data))  \
    GLES_ENTRY_PTR(glGetInteger64i_v_Idx))


GL_APICALL void GL_APIENTRY
glGetInteger64v (GLenum pname, GLint64 *data)
{
    prepare_gles_tracer ();

    glGetInteger64v_ (pname, data);

    fprintf (g_log_fp, "glGetInteger64v(%d, %p);", pname, data);
    if (data) fprintf (g_log_fp, " // data = %ld\n", *data);
}


GL_APICALL void GL_APIENTRY
glGetInteger64i_v (GLenum target, GLuint index, GLint64 *data)
{
    prepare_gles_tracer ();

    glGetInteger64i_v_ (target, index, data);

    fprintf (g_log_fp, "glGetInteger64i_v(%d, %d, %p);", target, index, data);
    if (data) fprintf (g_log_fp, " // data = %ld\n", *data);
}
