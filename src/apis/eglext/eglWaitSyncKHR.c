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


#define eglWaitSyncKHR_  \
    ((EGLint (*)(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags))  \
    EGL_ENTRY_PTR(eglWaitSyncKHR_Idx))


EGLAPI EGLint EGLAPIENTRY
eglWaitSyncKHR (EGLDisplay dpy, EGLSyncKHR sync, EGLint flags)
{
    prepare_gles_tracer ();

    EGLint ret = EGL_FALSE;
    if (eglWaitSyncKHR_)
        ret = eglWaitSyncKHR_ (dpy, sync, flags);

    fprintf (g_log_fp, "eglWaitSyncKHR(%p, %p, %s); // ret=%d\n",
             dpy, sync, get_flags_str (flags), ret);

    return ret;
}

