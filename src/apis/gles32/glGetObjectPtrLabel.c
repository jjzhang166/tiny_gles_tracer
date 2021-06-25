#include <stdio.h>
#include "GLEStrace.h"


#define glGetObjectPtrLabel_   \
    ((void (*)(const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label))  \
    GLES_ENTRY_PTR(glGetObjectPtrLabel_Idx))


GL_APICALL void GL_APIENTRY
glGetObjectPtrLabel (const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label)
{
    prepare_gles_tracer ();

    glGetObjectPtrLabel_ (ptr, bufSize, length, label);

    fprintf (g_log_fp, "glGetObjectPtrLabel(%p, %d, %p, %p); // ",
             ptr, bufSize, length, label);
    if (length) fprintf (g_log_fp, "length=%d, ", *length);
    if (label)  fprintf (g_log_fp, "label=%s, ", label);
    fprintf (g_log_fp, "\n");
}

