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


#define eglCreateSync_  \
    ((EGLSync (*)(EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list))  \
    EGL_ENTRY_PTR(eglCreateSync_Idx))


EGLAPI EGLSync EGLAPIENTRY
eglCreateSync (EGLDisplay dpy, EGLenum type, const EGLAttrib *attrib_list)
{
    prepare_gles_tracer ();

    EGLSync ret = EGL_NO_SYNC;
    if (eglCreateSync_)
        ret = eglCreateSync_ (dpy, type, attrib_list);

    fprintf (g_log_fp, "eglCreateSync(%p, %s, %p); // ret=%p\n",
             dpy, get_type_name_str (type), attrib_list, ret);

    return ret;
}

