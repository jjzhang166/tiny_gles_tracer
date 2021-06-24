#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_attr_str (EGLint attribute)
{
    switch (attribute)
    {
    case EGL_SYNC_TYPE      : return "EGL_SYNC_TYPE";
    case EGL_SYNC_STATUS    : return "EGL_SYNC_STATUS";
    case EGL_SYNC_CONDITION : return "EGL_SYNC_CONDITION";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attribute);
    return s_strbuf;
}


#define eglGetSyncAttribKHR_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSyncKHR sync, EGLint attribute, EGLint *value))  \
    EGL_ENTRY_PTR(eglGetSyncAttribKHR_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglGetSyncAttribKHR (EGLDisplay dpy, EGLSyncKHR sync, EGLint attribute, EGLint *value)
{
    prepare_gles_tracer ();

    EGLBoolean ret = EGL_FALSE;
    if (eglGetSyncAttribKHR_)
        ret = eglGetSyncAttribKHR_ (dpy, sync, attribute, value);

    fprintf (g_log_fp, "eglGetSyncAttribKHR(%p, %p, %s, %p); // ret=%d, ",
             dpy, sync, get_attr_str (attribute), value, ret);

    if (value) fprintf (g_log_fp, "value=%d", *value);
    fprintf (g_log_fp, "\n");
    return ret;
}

