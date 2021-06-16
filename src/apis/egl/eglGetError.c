#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_error_str (GLenum err)
{
    switch (err)
    {
    case EGL_SUCCESS            : return "EGL_SUCCESS";             break;
    case EGL_NOT_INITIALIZED    : return "EGL_NOT_INITIALIZED";     break;
    case EGL_BAD_ACCESS         : return "EGL_BAD_ACCESS";          break;
    case EGL_BAD_ALLOC          : return "EGL_BAD_ALLOC";           break;
    case EGL_BAD_ATTRIBUTE      : return "EGL_BAD_ATTRIBUTE";       break;
    case EGL_BAD_CONTEXT        : return "EGL_BAD_CONTEXT";         break;
    case EGL_BAD_CONFIG         : return "EGL_BAD_CONFIG";          break;
    case EGL_BAD_CURRENT_SURFACE: return "EGL_BAD_CURRENT_SURFACE"; break;
    case EGL_BAD_DISPLAY        : return "EGL_BAD_DISPLAY";         break;
    case EGL_BAD_SURFACE        : return "EGL_BAD_SURFACE";         break;
    case EGL_BAD_MATCH          : return "EGL_BAD_MATCH";           break;
    case EGL_BAD_PARAMETER      : return "EGL_BAD_PARAMETER";       break;
    case EGL_BAD_NATIVE_PIXMAP  : return "EGL_BAD_NATIVE_PIXMAP";   break;
    case EGL_BAD_NATIVE_WINDOW  : return "EGL_BAD_NATIVE_WINDOW";   break;
    case EGL_CONTEXT_LOST       : return "EGL_CONTEXT_LOST";        break;
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", err);
    return s_strbuf;
}

#define eglGetError_  \
    ((EGLint (*)(void))  \
    EGL_ENTRY_PTR(eglGetError_Idx))


EGLAPI EGLint EGLAPIENTRY
eglGetError (void)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetError();");

    EGLint ret = EGL_NOT_INITIALIZED;
    if (eglGetError_)
    {
        ret = eglGetError_ ();
        fprintf (g_log_fp, " // %s\n", get_error_str (ret));
    }
    fprintf (g_log_fp, "\n");

    return ret;
}

