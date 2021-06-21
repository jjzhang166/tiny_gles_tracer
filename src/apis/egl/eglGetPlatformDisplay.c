#include <stdio.h>
#include "GLEStrace.h"


#define eglGetPlatformDisplay_  \
    ((EGLDisplay (*)(EGLenum platform, void *native_display, const EGLAttrib *attrib_list))  \
    EGL_ENTRY_PTR(eglGetPlatformDisplay_Idx))


EGLAPI EGLDisplay EGLAPIENTRY
eglGetPlatformDisplay (EGLenum platform, void *native_display, const EGLAttrib *attrib_list)
{
    prepare_gles_tracer ();

    EGLDisplay ret = EGL_NO_DISPLAY;
    if (eglGetPlatformDisplay_)
        ret = eglGetPlatformDisplay_ (platform, native_display, attrib_list);

    fprintf (g_log_fp, "eglGetPlatformDisplay(%d, %p, %p);",
             platform, native_display, attrib_list);
    fprintf (g_log_fp, " // [%d] ret=%p", gles_trace_gettid(), ret);

    fprintf (g_log_fp, "\n");

    return ret;
}

