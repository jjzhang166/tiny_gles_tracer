#include <stdio.h>
#include "GLEStrace.h"


#define glObjectPtrLabel_   \
    ((void (*)(const void *ptr, GLsizei length, const GLchar *label))  \
    GLES_ENTRY_PTR(glObjectPtrLabel_Idx))


GL_APICALL void GL_APIENTRY
glObjectPtrLabel (const void *ptr, GLsizei length, const GLchar *label)
{
    prepare_gles_tracer ();

    glObjectPtrLabel_ (ptr, length, label);

    fprintf (g_log_fp, "glObjectPtrLabel(%p, %d, %s);\n",
             ptr, length, label);
}

