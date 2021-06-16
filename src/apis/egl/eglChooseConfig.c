#include <stdio.h>
#include "GLEStrace.h"


static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_config_attrib_name (EGLint attrib)
{
    switch (attrib)
    {
    case EGL_ALPHA_MASK_SIZE    : return "EGL_ALPHA_MASK_SIZE";
    case EGL_RED_SIZE           : return "EGL_RED_SIZE";
    case EGL_GREEN_SIZE         : return "EGL_GREEN_SIZE";
    case EGL_BLUE_SIZE          : return "EGL_BLUE_SIZE";
    case EGL_ALPHA_SIZE         : return "EGL_ALPHA_SIZE";
    case EGL_DEPTH_SIZE         : return "EGL_DEPTH_SIZE";
    case EGL_STENCIL_SIZE       : return "EGL_STENCIL_SIZE";
    case EGL_SAMPLES            : return "EGL_SAMPLES";
    case EGL_SAMPLE_BUFFERS     : return "EGL_SAMPLE_BUFFERS";
    case EGL_SURFACE_TYPE       : return "EGL_SURFACE_TYPE";
    case EGL_RENDERABLE_TYPE    : return "EGL_RENDERABLE_TYPE";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", attrib);
    return s_strbuf;
}


#define eglChooseConfig_  \
    ((EGLBoolean (*)(EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config))  \
    EGL_ENTRY_PTR(eglChooseConfig_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglChooseConfig (EGLDisplay dpy, const EGLint *attrib_list, EGLConfig *configs, EGLint config_size, EGLint *num_config)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglChooseConfig(%p, %p, %p, %d, %p);\n", dpy, attrib_list, configs, config_size, num_config);

    /* print attrib_list */
    if (attrib_list)
    {
        fprintf (g_log_fp, "EGLint attlib_list[] = {\n");
        for (int i = 0; ; i += 2)
        {
            if (attrib_list[i] == EGL_NONE)
            {
                fprintf (g_log_fp, "    EGL_NONE\n");
                break;
            }

            char *attr_str = get_config_attrib_name (attrib_list[i]);
            int  attribute = attrib_list[i+1];
            fprintf (g_log_fp, "    %-30s, %d,\n", attr_str, attribute);
        }
        fprintf (g_log_fp, "};\n");
    }

    if (eglChooseConfig_)
        return eglChooseConfig_ (dpy, attrib_list, configs, config_size, num_config);
    else
        return EGL_FALSE;
}

