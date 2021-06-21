#include <stdio.h>
#include "GLEStrace.h"


#define glIsTransformFeedback_   \
    ((GLboolean (*)(GLuint id))  \
    GLES_ENTRY_PTR(glIsTransformFeedback_Idx))


GL_APICALL GLboolean GL_APIENTRY
glIsTransformFeedback (GLuint id)
{
    prepare_gles_tracer ();

    GLboolean ret = glIsTransformFeedback_ (id);

    fprintf (g_log_fp, "glIsTransformFeedback(%d); // ret=%d\n", id, ret);

    return ret;
}

