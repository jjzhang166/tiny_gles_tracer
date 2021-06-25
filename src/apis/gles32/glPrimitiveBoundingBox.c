#include <stdio.h>
#include "GLEStrace.h"


#define glPrimitiveBoundingBox_   \
    ((void (*)(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW))  \
    GLES_ENTRY_PTR(glPrimitiveBoundingBox_Idx))


GL_APICALL void GL_APIENTRY
glPrimitiveBoundingBox (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW)
{
    prepare_gles_tracer ();

    glPrimitiveBoundingBox_ (minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);

    fprintf (g_log_fp, "glPrimitiveBoundingBox(%f, %f, %f, %f, %f, %f, %f, %f);\n",
             minX, minY, minZ, minW, maxX, maxY, maxZ, maxW);
}

