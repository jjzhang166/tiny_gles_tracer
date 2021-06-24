#include <stdio.h>
#include "GLEStrace.h"


#define eglGetPlatformDisplayEXT_  \
    ((EGLDisplay (*)(EGLenum platform, void *native_display, const EGLint *attrib_list))  \
    EGL_ENTRY_PTR(eglGetPlatformDisplayEXT_Idx))


EGLAPI EGLDisplay EGLAPIENTRY
eglGetPlatformDisplayEXT (EGLenum platform, void *native_display, const EGLint *attrib_list)
{
    prepare_gles_tracer ();

    EGLDisplay ret = EGL_NO_DISPLAY;
    if (eglGetPlatformDisplayEXT_)
        ret = eglGetPlatformDisplayEXT_ (platform, native_display, attrib_list);

    fprintf (g_log_fp, "eglGetPlatformDisplayEXT(%d, %p, %p);",
             platform, native_display, attrib_list);
    fprintf (g_log_fp, " // [%d] ret=%p", gles_trace_gettid(), ret);

    fprintf (g_log_fp, "\n");

    return ret;
}

