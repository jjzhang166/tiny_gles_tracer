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

static char *
get_type_str (GLenum type)
{
    switch (type)
    {
    case GL_UNSIGNED_BYTE               : return "GL_UNSIGNED_BYTE";
    case GL_UNSIGNED_SHORT              : return "GL_UNSIGNED_SHORT";
    case GL_UNSIGNED_INT                : return "GL_UNSIGNED_INT";
    }
    snprintf (s_strbuf, sizeof (s_strbuf), "0x%x", type);
    return s_strbuf;
}


#define glDrawElementsInstancedBaseVertexBaseInstanceEXT_         \
    ((void (*)(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance))   \
    GLES_ENTRY_PTR(glDrawElementsInstancedBaseVertexBaseInstanceEXT_Idx))

#define glGetIntegerv_   \
    ((void (*)(GLenum pname, GLint *data))  \
    GLES_ENTRY_PTR(glGetIntegerv_Idx))

#define glReadPixels_   \
    ((void (*)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels))  \
    GLES_ENTRY_PTR(glReadPixels_Idx))


GL_APICALL void GL_APIENTRY
glDrawElementsInstancedBaseVertexBaseInstanceEXT (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "glDrawElementsInstancedBaseVertexBaseInstanceEXT(%s, %d, %s, %p, %d, %d, %d); // ",
             get_mode_str (mode), count, 
             get_type_str (type), indices, instancecount, basevertex, baseinstance);
    fprintf (g_log_fp, "cnt=%d ", g_draw_counter);

    if (g_force_line_render)
    {
        mode = GL_LINE_STRIP;
    }

    glDrawElementsInstancedBaseVertexBaseInstanceEXT_ (mode, count, type, indices, instancecount, basevertex, baseinstance);

    if (g_capture_on_draw)
    {
        char fname[128];
        snprintf (fname, sizeof(fname), "%05d_glDrawElementsInstancedBaseVertexBaseInstanceEXT_%05d_%05d.tga", g_pid, g_frame_counter, g_draw_counter);

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
