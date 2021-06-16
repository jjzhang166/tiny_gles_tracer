#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_readdraw_str (EGLint readdraw)
{
    switch (readdraw)
    {
    case EGL_READ   : return "EGL_READ";
    case EGL_DRAW   : return "EGL_DRAW";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", readdraw);
    return s_strbuf;
}


#define eglGetCurrentSurface_  \
    ((EGLSurface (*)(EGLint readdraw))  \
    EGL_ENTRY_PTR(eglGetCurrentSurface_Idx))


EGLAPI EGLSurface EGLAPIENTRY
eglGetCurrentSurface (EGLint readdraw)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetCurrentSurface(%s); // ", get_readdraw_str (readdraw));

    EGLSurface sfc = EGL_NO_SURFACE;
    if (eglGetCurrentSurface_)
    {
        sfc = eglGetCurrentSurface_ (readdraw);
        fprintf (g_log_fp, " sfc = %p", sfc);
    }
    fprintf (g_log_fp, "\n");

    return sfc;
}

