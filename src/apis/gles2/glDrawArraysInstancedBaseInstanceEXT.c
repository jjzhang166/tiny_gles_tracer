#include <stdio.h>
#include <stdlib.h>
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


#define glDrawArraysInstancedBaseInstanceEXT_         \
    ((void (*)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance))   \
    GLES_ENTRY_PTR(glDrawArraysInstancedBaseInstanceEXT_Idx))

#define glGetIntegerv_   \
    ((void (*)(GLenum pname, GLint *data))  \
    GLES_ENTRY_PTR(glGetIntegerv_Idx))

#define glReadPixels_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels))  \
    GLES_ENTRY_PTR(glReadPixels_Idx))


GL_APICALL void GL_APIENTRY
glDrawArraysInstancedBaseInstanceEXT (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glDrawArraysInstancedBaseInstanceEXT(%s, %d, %d, %d, %d); // ",
             get_mode_str (mode), first, count, instancecount, baseinstance);
    fprintf (g_log_fp, "cnt=%d ", g_draw_counter);

    if (g_force_line_render)
    {
        mode = GL_LINE_STRIP;
    }

    glDrawArraysInstancedBaseInstanceEXT_ (mode, first, count, instancecount, baseinstance);

    if (g_capture_on_draw)
    {
        char fname[128];
        snprintf (fname, sizeof(fname), "%05d_glDrawArraysInstancedBaseInstanceEXT_%05d_%05d.tga", g_pid, g_frame_counter, g_draw_counter);

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

    fprintf (g_log_fp, "\n");
    g_draw_counter ++;
}

