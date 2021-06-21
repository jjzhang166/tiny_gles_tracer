#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_flags_str (EGLint flags)
{
    switch (flags)
    {
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", flags);
    return s_strbuf;
}


#define eglWaitSync_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSync sync, EGLint flags))  \
    EGL_ENTRY_PTR(eglWaitSync_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglWaitSync (EGLDisplay dpy, EGLSync sync, EGLint flags)
{
    prepare_gles_tracer ();

    EGLint ret = EGL_FALSE;
    if (eglWaitSync_)
        ret = eglWaitSync_ (dpy, sync, flags);

    fprintf (g_log_fp, "eglWaitSync(%p, %p, %s); // ret=%d\n",
             dpy, sync, get_flags_str (flags), ret);

    return ret;
}

