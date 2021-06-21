#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_flags_str (EGLint flags)
{
    switch (flags)
    {
    case EGL_SYNC_FLUSH_COMMANDS_BIT : return "EGL_SYNC_FLUSH_COMMANDS_BIT ";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", flags);
    return s_strbuf;
}


#define eglClientWaitSync_  \
    ((EGLint (*)(EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout))  \
    EGL_ENTRY_PTR(eglClientWaitSync_Idx))


EGLAPI EGLint EGLAPIENTRY
eglClientWaitSync (EGLDisplay dpy, EGLSync sync, EGLint flags, EGLTime timeout)
{
    prepare_gles_tracer ();

    EGLint ret = EGL_FALSE;
    if (eglClientWaitSync_)
        ret = eglClientWaitSync_ (dpy, sync, flags, timeout);

    fprintf (g_log_fp, "eglClientWaitSync(%p, %p, %s, %ld); // ret=%d\n",
             dpy, sync, get_flags_str (flags), timeout, ret);

    return ret;
}

