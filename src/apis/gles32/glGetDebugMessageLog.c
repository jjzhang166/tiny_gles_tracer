#include <stdio.h>
#include "GLEStrace.h"


#define glGetDebugMessageLog_   \
    ((GLuint (*)(GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog))  \
    GLES_ENTRY_PTR(glGetDebugMessageLog_Idx))


GL_APICALL GLuint GL_APIENTRY
glGetDebugMessageLog (GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog)
{
    prepare_gles_tracer ();

    GLuint ret = glGetDebugMessageLog_ (count, bufSize, sources, types, ids, severities, lengths, messageLog);

    fprintf (g_log_fp, "glGetDebugMessageLog(%d, %d, %p, %p, %p, %p, %p, %p); // ret=%d\n", 
             count, bufSize, sources, types, ids, severities, lengths, messageLog, ret);

    return ret;
}

