#include <stdio.h>
#include "GLEStrace.h"


#define glGetTransformFeedbackVarying_   \
    ((void (*)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name))  \
    GLES_ENTRY_PTR(glGetTransformFeedbackVarying_Idx))


GL_APICALL void GL_APIENTRY
glGetTransformFeedbackVarying (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
{
    prepare_gles_tracer ();

    glGetTransformFeedbackVarying_ (program, index, bufSize, length, size, type, name);

    fprintf (g_log_fp, "glGetTransformFeedbackVarying(%d, %d, %d, %p, %p, %p, %p); // ", 
                        program, index, bufSize, length, size, type, name);
    if (length) fprintf (g_log_fp, "length=%d, ", *length);
    if (size)   fprintf (g_log_fp, "size=%d, ", *size);
    if (type)   fprintf (g_log_fp, "type=0x%x, ", *type);
    if (name)   fprintf (g_log_fp, "name=%s, ", name);
    fprintf (g_log_fp, "\n");
}

