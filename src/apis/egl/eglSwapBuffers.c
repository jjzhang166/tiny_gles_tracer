#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"
#include "util_image_tga.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_error_str (GLenum err)
{
    switch (err)
    {
    case GL_NO_ERROR            : return "GL_NO_ERROR";          break;
    case GL_INVALID_ENUM        : return "GL_INVALID_ENUM";      break;
    case GL_INVALID_VALUE       : return "GL_INVALID_VALUE";     break;
    case GL_INVALID_OPERATION   : return "GL_INVALID_OPERATION"; break;
    case GL_STACK_OVERFLOW      : return "GL_STACK_OVERFLOW";    break;
    case GL_STACK_UNDERFLOW     : return "GL_STACK_UNDERFLOW";   break;
    case GL_OUT_OF_MEMORY       : return "GL_OUT_OF_MEMORY";     break;
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", err);
    return s_strbuf;
}


#define eglSwapBuffers_     \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface))   \
    EGL_ENTRY_PTR(eglSwapBuffers_Idx))

#define eglQuerySurface_  \
    ((EGLBoolean (*)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint *value))  \
    EGL_ENTRY_PTR(eglQuerySurface_Idx))

#define glReadPixels_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels))  \
    GLES_ENTRY_PTR(glReadPixels_Idx))

#define glGetError_   \
    ((GLenum (*)(void))  \
    GLES_ENTRY_PTR(glGetError_Idx))


EGLAPI EGLBoolean EGLAPIENTRY
eglSwapBuffers (EGLDisplay dpy, EGLSurface surface)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglSwapBuffers(%p, %p);", dpy, surface);
    fprintf (g_log_fp, " // [%d] (%d)", gles_trace_gettid(), g_frame_counter);

    EGLBoolean ret = EGL_FALSE;
    if (eglSwapBuffers_)
    {
        if (g_capture_on_swap)
        {
            if (eglQuerySurface_ && glReadPixels_)
            {
                char fname[128];
                snprintf (fname, sizeof(fname), "%05d_eglSwapBuffers_%05d.tga", g_pid, g_frame_counter);

                EGLint w, h;
                eglQuerySurface_ (dpy, surface, EGL_WIDTH,  &w);
                eglQuerySurface_ (dpy, surface, EGL_HEIGHT, &h);

                char *imgbuf = (char *)malloc (w * h * 4);
                glReadPixels_ (0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, imgbuf);
                save_to_tga_file (fname, (void *)imgbuf, w, h);
                fprintf (g_log_fp, " %s", fname);
                free (imgbuf);
            }
        }

        ret = eglSwapBuffers_ (dpy, surface);

        if (g_geterror_on_swap)
        {
            if (glGetError_)
            {
                GLenum err = glGetError_ ();
                fprintf (g_log_fp, " [%s]\n", get_error_str (err));
            }
        }
    }
    fprintf (g_log_fp, "\n");
    fflush (g_log_fp);
    g_frame_counter ++;

    return ret;
}

