#include <stdio.h>
#include "GLEStrace.h"


#define glUniformBlockBinding_   \
    ((void (*)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding))  \
    GLES_ENTRY_PTR(glUniformBlockBinding_Idx))


GL_APICALL void GL_APIENTRY
glUniformBlockBinding (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
    prepare_gles_tracer ();

    glUniformBlockBinding_ (program, uniformBlockIndex, uniformBlockBinding);

    fprintf (g_log_fp, "glUniformBlockBinding(%d, %d, %d);\n", program, uniformBlockIndex, uniformBlockBinding);
}

