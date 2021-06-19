#include <stdio.h>
#include <stdlib.h>
#include "GLEStrace.h"
#include "util_image_tga.h"

static char s_strbuf[512];  // [FIXME] thread safe

static char *
get_mask_str (GLbitfield mask)
{
    switch (mask)
    {
    case GL_COLOR_BUFFER_BIT            : return "GL_COLOR_BUFFER_BIT";
    case GL_DEPTH_BUFFER_BIT            : return "GL_DEPTH_BUFFER_BIT";
    case GL_STENCIL_BUFFER_BIT          : return "GL_STENCIL_BUFFER_BIT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", mask);
    return s_strbuf;
}

static char *
get_filter_str (GLenum filter)
{
    switch (filter)
    {
    case GL_NEAREST                     : return "GL_NEAREST";
    case GL_LINEAR                      : return "GL_LINEAR";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", filter);
    return s_strbuf;
}


#define glBlitFramebuffer_   \
    ((void (*)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter))  \
    GLES_ENTRY_PTR(glBlitFramebuffer_Idx))

#define glGetIntegerv_   \
    ((void (*)(GLenum pname, GLint *data))  \
    GLES_ENTRY_PTR(glGetIntegerv_Idx))

#define glReadPixels_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels))  \
    GLES_ENTRY_PTR(glReadPixels_Idx))


GL_APICALL void GL_APIENTRY
glBlitFramebuffer (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, 
                   GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glBlitFramebuffer(%d, %d, %d, %d, %d, %d, %d, %d, %s, %s); // ",
             srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, 
             get_mask_str (mask), get_filter_str (filter));
    fprintf (g_log_fp, "cnt=%d ", g_draw_counter);

    glBlitFramebuffer_ (srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);

    if (g_capture_on_draw)
    {
        char fname[128];
        snprintf (fname, sizeof(fname), "%05d_glBlitFramebuffer_%05d_%05d.tga", g_pid, g_frame_counter, g_draw_counter);

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

