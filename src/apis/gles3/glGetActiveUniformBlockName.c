#include <stdio.h>
#include "GLEStrace.h"


#define glGetActiveUniformBlockName_   \
    ((void (*)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName))  \
    GLES_ENTRY_PTR(glGetActiveUniformBlockName_Idx))


GL_APICALL void GL_APIENTRY
glGetActiveUniformBlockName (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize,
                             GLsizei *length, GLchar *uniformBlockName)
{
    prepare_gles_tracer ();

    glGetActiveUniformBlockName_ (program, uniformBlockIndex, bufSize, length, uniformBlockName);

    fprintf (g_log_fp, "glGetActiveUniformBlockName(%d, %d, %d, %p, %p); // ", 
             program, uniformBlockIndex, bufSize, length, uniformBlockName);

    if (length) fprintf (g_log_fp, "length=%d, ", *length);
    if (uniformBlockName) fprintf (g_log_fp, "uniformBlockName=%s, ", uniformBlockName);

    fprintf (g_log_fp, "\n"); 
}

