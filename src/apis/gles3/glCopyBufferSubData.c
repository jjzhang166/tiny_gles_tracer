#include <stdio.h>
#include "GLEStrace.h"


#define glCopyBufferSubData_   \
    ((void (*)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size))  \
    GLES_ENTRY_PTR(glCopyBufferSubData_Idx))


GL_APICALL void GL_APIENTRY
glCopyBufferSubData (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
    prepare_gles_tracer ();

    glCopyBufferSubData_ (readTarget, writeTarget, readOffset, writeOffset, size);

    fprintf (g_log_fp, "glCopyBufferSubData(%d, %d, %ld, %ld, %ld);\n",
             readTarget, writeTarget, readOffset, writeOffset, size);
}

