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


#define eglClientWaitSyncKHR_  \
    ((EGLint (*)(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags, EGLTimeKHR timeout))  \
    EGL_ENTRY_PTR(eglClientWaitSyncKHR_Idx))


EGLAPI EGLint EGLAPIENTRY
eglClientWaitSyncKHR (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags, EGLTimeKHR timeout)
{
    prepare_gles_tracer ();

    EGLint ret = EGL_FALSE;
    if (eglClientWaitSyncKHR_)
        ret = eglClientWaitSyncKHR_ (dpy, sync, flags, timeout);

    fprintf (g_log_fp, "eglClientWaitSyncKHR(%p, %p, %s, %ld); // ret=%d\n",
             dpy, sync, get_flags_str (flags), timeout, ret);

    return ret;
}

