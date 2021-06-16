#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_config_attrib_name (EGLint attribute)
{
    switch (attribute)
    {
    case EGL_ALPHA_SIZE         : return "EGL_ALPHA_SIZE";
    case EGL_ALPHA_MASK_SIZE    : return "EGL_ALPHA_MASK_SIZE";
    case EGL_BLUE_SIZE          : return "EGL_BLUE_SIZE";
    case EGL_BUFFER_SIZE        : return "EGL_BUFFER_SIZE";
    case EGL_CONFIG_ID          : return "EGL_CONFIG_ID";
    case EGL_DEPTH_SIZE         : return "EGL_DEPTH_SIZE";
    case EGL_GREEN_SIZE         : return "EGL_GREEN_SIZE";
    case EGL_MAX_SWAP_INTERVAL  : return "EGL_MAX_SWAP_INTERVAL";
    case EGL_MIN_SWAP_INTERVAL  : return "EGL_MIN_SWAP_INTERVAL";
    case EGL_RED_SIZE           : return "EGL_RED_SIZE";
    case EGL_RENDERABLE_TYPE    : return "EGL_RENDERABLE_TYPE";
    case EGL_SAMPLE_BUFFERS     : return "EGL_SAMPLE_BUFFERS";
    case EGL_SAMPLES            : return "EGL_SAMPLES";
    case EGL_STENCIL_SIZE       : return "EGL_STENCIL_SIZE";
    case EGL_SURFACE_TYPE       : return "EGL_SURFACE_TYPE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attribute);
    return s_strbuf;
}


#define eglGetConfigAttrib_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value))  \
    EGL_ENTRY_PTR(eglGetConfigAttrib_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglGetConfigAttrib (EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint *value)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetConfigAttrib(%p, %p, %-20s, %p);",
             dpy, config, get_config_attrib_name (attribute), value);
    fprintf (g_log_fp, " // [%d]", gles_trace_gettid());

    EGLBoolean ret = EGL_FALSE;
    if (eglGetConfigAttrib_)
    {
        ret = eglGetConfigAttrib_ (dpy, config, attribute, value);
        if (value) fprintf (g_log_fp, " value = %d", *value);
    }
    fprintf (g_log_fp, "\n");

    return ret;
}

