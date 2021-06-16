#include <stdlib.h>
#include <stdio.h>
#include "GLEStrace.h"
#include "util_image_tga.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_mode_str (GLenum mode)
{
    switch (mode)
    {
    case GL_POINTS                      : return "GL_POINTS";
    case GL_LINE_STRIP                  : return "GL_LINE_STRIP";
    case GL_LINE_LOOP                   : return "GL_LINE_LOOP";
    case GL_LINES                       : return "GL_LINES";
    case GL_TRIANGLE_STRIP              : return "GL_TRIANGLE_STRIP";
    case GL_TRIANGLE_FAN                : return "GL_TRIANGLE_FAN";
    case GL_TRIANGLES                   : return "GL_TRIANGLES";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", mode);
    return s_strbuf;
}

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

#define glDrawArrays_   \
    ((void (*)(GLenum mode,GLint first,GLsizei count))  \
    GLES_ENTRY_PTR(glDrawArrays_Idx))

#define glGetIntegerv_   \
    ((void (*)(GLenum pname, GLint *data))  \
    GLES_ENTRY_PTR(glGetIntegerv_Idx))

#define glReadPixels_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels))  \
    GLES_ENTRY_PTR(glReadPixels_Idx))

#define glGetError_   \
    ((GLenum (*)(void))  \
    GLES_ENTRY_PTR(glGetError_Idx))


GL_APICALL void GL_APIENTRY
glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glDrawArrays(%s, %d, %d); // ",
             get_mode_str (mode), first, count);
    fprintf (g_log_fp, "cnt=%d ", g_draw_counter);

    if (g_force_line_render)
    {
        mode = GL_LINE_STRIP;
    }

    glDrawArrays_ (mode, first, count);

    if (g_capture_on_draw)
    {
        char fname[128];
        snprintf (fname, sizeof(fname), "%05d_glDrawArrays_%05d_%05d.tga", g_pid, g_frame_counter, g_draw_counter);

        int vp[4];
        glGetIntegerv_ (GL_VIEWPORT, vp);
        int x = vp[0];
        int y = vp[1];
        int w = vp[2];
        int h = vp[3];

        char *imgbuf = (char *)malloc (w * h * 4);
        glReadPixels_ (x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, imgbuf);
        save_to_tga_file (fname, (void *)imgbuf, w, h);
        fprintf (g_log_fp, " %s", fname);
        free (imgbuf);
    }

    if (g_geterror_on_draw)
    {
        GLenum err = glGetError_ ();
        fprintf (g_log_fp, " [%s]\n", get_error_str (err));
    }

    fprintf (g_log_fp, "\n");
    g_draw_counter ++;
}

