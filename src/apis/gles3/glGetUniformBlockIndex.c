#include <stdio.h>
#include "GLEStrace.h"


#define glGetUniformBlockIndex_   \
    ((GLuint (*)(GLuint program, const GLchar *uniformBlockName))  \
    GLES_ENTRY_PTR(glGetUniformBlockIndex_Idx))


GL_APICALL GLuint GL_APIENTRY
glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName)
{
    prepare_gles_tracer ();

    GLuint ret = glGetUniformBlockIndex_ (program, uniformBlockName);

    fprintf (g_log_fp, "glGetUniformBlockIndex(%d, \"%s\"); // ret=%d\n",
             program, uniformBlockName, ret);

    return ret;
}

