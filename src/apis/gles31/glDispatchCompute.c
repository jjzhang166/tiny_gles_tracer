#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"


#define glDispatchCompute_         \
    ((void (*)(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z))   \
    GLES_ENTRY_PTR(glDispatchCompute_Idx))


GL_APICALL void GL_APIENTRY
glDispatchCompute (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glDispatchCompute(%d, %d, %d);\n",
             num_groups_x, num_groups_y, num_groups_z);

    glDispatchCompute_ (num_groups_x, num_groups_y, num_groups_z);
}

