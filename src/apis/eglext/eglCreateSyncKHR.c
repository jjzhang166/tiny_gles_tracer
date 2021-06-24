#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_type_name_str (EGLenum type)
{
    switch (type)
    {
    case EGL_SYNC_FENCE                 : return "EGL_SYNC_FENCE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}


#define eglCreateSyncKHR_  \
    ((EGLSyncKHR (*)(EGLDisplay dpy, EGLenum type, const EGLint *attrib_list))  \
    EGL_ENTRY_PTR(eglCreateSyncKHR_Idx))


EGLAPI EGLSyncKHR EGLAPIENTRY
eglCreateSyncKHR (EGLDisplay dpy, EGLenum type, const EGLint *attrib_list)
{
    prepare_gles_tracer ();

    EGLSyncKHR ret = EGL_NO_SYNC;
    if (eglCreateSyncKHR_)
        ret = eglCreateSyncKHR_ (dpy, type, attrib_list);

    fprintf (g_log_fp, "eglCreateSyncKHR(%p, %s, %p); // ret=%p\n",
             dpy, get_type_name_str (type), attrib_list, ret);

    return ret;
}

