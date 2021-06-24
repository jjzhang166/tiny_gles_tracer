#include <stdio.h>
#include "GLEStrace.h"

#define glUseProgramStages_   \
    ((void (*)(GLuint pipeline, GLbitfield stages, GLuint program))  \
    GLES_ENTRY_PTR(glUseProgramStages_Idx))



GL_APICALL void GL_APIENTRY
glUseProgramStages (GLuint pipeline, GLbitfield stages, GLuint program)
{
    prepare_gles_tracer ();

    glUseProgramStages_ (pipeline, stages, program);

    fprintf (g_log_fp, "glUseProgramStages(%d, %d, %d);\n", pipeline, stages, program);
}

