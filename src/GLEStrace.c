#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

#define __USE_GNU
#include <dlfcn.h>
#include "GLEStrace.h"



static int      s_init_done = 0;
FILE            *g_log_fp;
pid_t           g_pid;
int             g_frame_counter     = 0;
int             g_draw_counter      = 0;
int             g_force_line_render = 0;
int             g_capture_on_draw   = 0;
int             g_capture_on_swap   = 0;
int             g_geterror_on_swap  = 0;
int             g_geterror_on_draw  = 0;

unsigned char   g_gl_version_str [64];
unsigned char   g_gl_vendor_str  [64];
unsigned char   g_gl_renderer_str[64];
unsigned char   *g_force_gl_version_ptr  = NULL;
unsigned char   *g_force_gl_vendor_ptr   = NULL;
unsigned char   *g_force_gl_renderer_ptr = NULL;
unsigned char   *g_force_gl_extension_ptr = NULL;


gles_entry_t egl_entry_table[] =
{
    {0},

    /* EGL_VERSION_1_0 */
    DECLARE_CALL_ENTRY(eglChooseConfig),
    DECLARE_CALL_ENTRY(eglCopyBuffers),
    DECLARE_CALL_ENTRY(eglCreateContext),
    DECLARE_CALL_ENTRY(eglCreatePbufferSurface),
    DECLARE_CALL_ENTRY(eglCreatePixmapSurface),
    DECLARE_CALL_ENTRY(eglCreateWindowSurface),
    DECLARE_CALL_ENTRY(eglDestroyContext),
    DECLARE_CALL_ENTRY(eglDestroySurface),
    DECLARE_CALL_ENTRY(eglGetConfigAttrib),
    DECLARE_CALL_ENTRY(eglGetConfigs),
    DECLARE_CALL_ENTRY(eglGetCurrentDisplay),
    DECLARE_CALL_ENTRY(eglGetCurrentSurface),
    DECLARE_CALL_ENTRY(eglGetDisplay),
    DECLARE_CALL_ENTRY(eglGetError),
    DECLARE_CALL_ENTRY(eglGetProcAddress),
    DECLARE_CALL_ENTRY(eglInitialize),
    DECLARE_CALL_ENTRY(eglMakeCurrent),
    DECLARE_CALL_ENTRY(eglQueryContext),
    DECLARE_CALL_ENTRY(eglQueryString),
    DECLARE_CALL_ENTRY(eglQuerySurface),
    DECLARE_CALL_ENTRY(eglSwapBuffers),
    DECLARE_CALL_ENTRY(eglTerminate),
    DECLARE_CALL_ENTRY(eglWaitGL),
    DECLARE_CALL_ENTRY(eglWaitNative),

    /* EGL_VERSION_1_1 */
    DECLARE_CALL_ENTRY(eglSwapInterval),

    /* EGL_VERSION_1_2 */
    DECLARE_CALL_ENTRY(eglBindAPI),

    /* EGL_VERSION_1_2 */
    DECLARE_CALL_ENTRY(eglGetCurrentContext),

    /* EGL_VERSION_1_5 */
    DECLARE_CALL_ENTRY(eglCreateImage),
    {0}
};


gles_entry_t gles_entry_table[] =
{
    {0},

    /* GLES */
    DECLARE_CALL_ENTRY(glActiveTexture),
    DECLARE_CALL_ENTRY(glAttachShader),
    DECLARE_CALL_ENTRY(glBindAttribLocation),
    DECLARE_CALL_ENTRY(glBindBuffer),
    DECLARE_CALL_ENTRY(glBindFramebuffer),
    DECLARE_CALL_ENTRY(glBindRenderbuffer),
    DECLARE_CALL_ENTRY(glBindTexture),
    DECLARE_CALL_ENTRY(glBlendColor),
    DECLARE_CALL_ENTRY(glBlendEquation),
    DECLARE_CALL_ENTRY(glBlendEquationSeparate),
    DECLARE_CALL_ENTRY(glBlendFunc),
    DECLARE_CALL_ENTRY(glBlendFuncSeparate),
    DECLARE_CALL_ENTRY(glBufferData),
    DECLARE_CALL_ENTRY(glBufferSubData),
    DECLARE_CALL_ENTRY(glCheckFramebufferStatus),

    DECLARE_CALL_ENTRY(glClear),
    DECLARE_CALL_ENTRY(glClearColor),
    DECLARE_CALL_ENTRY(glClearDepthf),
    DECLARE_CALL_ENTRY(glClearStencil),
    DECLARE_CALL_ENTRY(glColorMask),
    DECLARE_CALL_ENTRY(glCompileShader),
    DECLARE_CALL_ENTRY(glCompressedTexImage2D),
    DECLARE_CALL_ENTRY(glCompressedTexSubImage2D),
    DECLARE_CALL_ENTRY(glCopyTexImage2D),
    DECLARE_CALL_ENTRY(glCopyTexSubImage2D),
    DECLARE_CALL_ENTRY(glCreateProgram),
    DECLARE_CALL_ENTRY(glCreateShader),
    DECLARE_CALL_ENTRY(glCullFace),

    DECLARE_CALL_ENTRY(glDeleteBuffers),
    DECLARE_CALL_ENTRY(glDeleteFramebuffers),
    DECLARE_CALL_ENTRY(glDeleteProgram),
    DECLARE_CALL_ENTRY(glDeleteRenderbuffers),
    DECLARE_CALL_ENTRY(glDeleteShader),
    DECLARE_CALL_ENTRY(glDeleteTextures),
    DECLARE_CALL_ENTRY(glDepthFunc),
    DECLARE_CALL_ENTRY(glDepthMask),
    DECLARE_CALL_ENTRY(glDepthRangef),
    DECLARE_CALL_ENTRY(glDetachShader),
    DECLARE_CALL_ENTRY(glDisable),
    DECLARE_CALL_ENTRY(glDisableVertexAttribArray),
    DECLARE_CALL_ENTRY(glDrawArrays),
    DECLARE_CALL_ENTRY(glDrawElements),

    DECLARE_CALL_ENTRY(glEnable),
    DECLARE_CALL_ENTRY(glEnableVertexAttribArray),
    DECLARE_CALL_ENTRY(glFinish),
    DECLARE_CALL_ENTRY(glFlush),
    DECLARE_CALL_ENTRY(glFramebufferRenderbuffer),
    DECLARE_CALL_ENTRY(glFramebufferTexture2D),
    DECLARE_CALL_ENTRY(glFrontFace),
    DECLARE_CALL_ENTRY(glGenBuffers),
    DECLARE_CALL_ENTRY(glGenerateMipmap),
    DECLARE_CALL_ENTRY(glGenFramebuffers),
    DECLARE_CALL_ENTRY(glGenRenderbuffers),
    DECLARE_CALL_ENTRY(glGenTextures),

    DECLARE_CALL_ENTRY(glGetActiveAttrib),
    DECLARE_CALL_ENTRY(glGetActiveUniform),
    DECLARE_CALL_ENTRY(glGetAttachedShaders),
    DECLARE_CALL_ENTRY(glGetAttribLocation),
    DECLARE_CALL_ENTRY(glGetBooleanv),
    DECLARE_CALL_ENTRY(glGetBufferParameteriv),
    DECLARE_CALL_ENTRY(glGetError),
    DECLARE_CALL_ENTRY(glGetFloatv),
    DECLARE_CALL_ENTRY(glGetFramebufferAttachmentParameteriv),
    DECLARE_CALL_ENTRY(glGetIntegerv),
    DECLARE_CALL_ENTRY(glGetProgramiv),
    DECLARE_CALL_ENTRY(glGetProgramInfoLog),
    DECLARE_CALL_ENTRY(glGetRenderbufferParameteriv),
    DECLARE_CALL_ENTRY(glGetShaderiv),
    DECLARE_CALL_ENTRY(glGetShaderInfoLog),
    DECLARE_CALL_ENTRY(glGetShaderPrecisionFormat),
    DECLARE_CALL_ENTRY(glGetShaderSource),
    DECLARE_CALL_ENTRY(glGetString),
    DECLARE_CALL_ENTRY(glGetTexParameterfv),
    DECLARE_CALL_ENTRY(glGetTexParameteriv),
    DECLARE_CALL_ENTRY(glGetUniformfv),
    DECLARE_CALL_ENTRY(glGetUniformiv),
    DECLARE_CALL_ENTRY(glGetUniformLocation),
    DECLARE_CALL_ENTRY(glGetVertexAttribfv),
    DECLARE_CALL_ENTRY(glGetVertexAttribiv),
    DECLARE_CALL_ENTRY(glGetVertexAttribPointerv),
    DECLARE_CALL_ENTRY(glHint),

    DECLARE_CALL_ENTRY(glIsBuffer),
    DECLARE_CALL_ENTRY(glIsEnabled),
    DECLARE_CALL_ENTRY(glIsFramebuffer),
    DECLARE_CALL_ENTRY(glIsProgram),
    DECLARE_CALL_ENTRY(glIsRenderbuffer),
    DECLARE_CALL_ENTRY(glIsShader),
    DECLARE_CALL_ENTRY(glIsTexture),

    DECLARE_CALL_ENTRY(glLineWidth),
    DECLARE_CALL_ENTRY(glLinkProgram),
    DECLARE_CALL_ENTRY(glPixelStorei),
    DECLARE_CALL_ENTRY(glPolygonOffset),
    DECLARE_CALL_ENTRY(glReadPixels),
    DECLARE_CALL_ENTRY(glReleaseShaderCompiler),
    DECLARE_CALL_ENTRY(glRenderbufferStorage),
    DECLARE_CALL_ENTRY(glSampleCoverage),
    DECLARE_CALL_ENTRY(glScissor),
    DECLARE_CALL_ENTRY(glShaderBinary),
    DECLARE_CALL_ENTRY(glShaderSource),

    DECLARE_CALL_ENTRY(glStencilFunc),
    DECLARE_CALL_ENTRY(glStencilFuncSeparate),
    DECLARE_CALL_ENTRY(glStencilMask),
    DECLARE_CALL_ENTRY(glStencilMaskSeparate),
    DECLARE_CALL_ENTRY(glStencilOp),
    DECLARE_CALL_ENTRY(glStencilOpSeparate),

    DECLARE_CALL_ENTRY(glTexImage2D),
    DECLARE_CALL_ENTRY(glTexParameterf),
    DECLARE_CALL_ENTRY(glTexParameterfv),
    DECLARE_CALL_ENTRY(glTexParameteri),
    DECLARE_CALL_ENTRY(glTexParameteriv),
    DECLARE_CALL_ENTRY(glTexSubImage2D),

    DECLARE_CALL_ENTRY(glUniform1f),
    DECLARE_CALL_ENTRY(glUniform1fv),
    DECLARE_CALL_ENTRY(glUniform1i),
    DECLARE_CALL_ENTRY(glUniform1iv),
    DECLARE_CALL_ENTRY(glUniform2f),
    DECLARE_CALL_ENTRY(glUniform2fv),
    DECLARE_CALL_ENTRY(glUniform2i),
    DECLARE_CALL_ENTRY(glUniform2iv),
    DECLARE_CALL_ENTRY(glUniform3f),
    DECLARE_CALL_ENTRY(glUniform3fv),
    DECLARE_CALL_ENTRY(glUniform3i),
    DECLARE_CALL_ENTRY(glUniform3iv),
    DECLARE_CALL_ENTRY(glUniform4f),
    DECLARE_CALL_ENTRY(glUniform4fv),
    DECLARE_CALL_ENTRY(glUniform4i),
    DECLARE_CALL_ENTRY(glUniform4iv),
    DECLARE_CALL_ENTRY(glUniformMatrix2fv),
    DECLARE_CALL_ENTRY(glUniformMatrix3fv),
    DECLARE_CALL_ENTRY(glUniformMatrix4fv),

    DECLARE_CALL_ENTRY(glUseProgram),
    DECLARE_CALL_ENTRY(glValidateProgram),
    DECLARE_CALL_ENTRY(glVertexAttrib1f),
    DECLARE_CALL_ENTRY(glVertexAttrib1fv),
    DECLARE_CALL_ENTRY(glVertexAttrib2f),
    DECLARE_CALL_ENTRY(glVertexAttrib2fv),
    DECLARE_CALL_ENTRY(glVertexAttrib3f),
    DECLARE_CALL_ENTRY(glVertexAttrib3fv),
    DECLARE_CALL_ENTRY(glVertexAttrib4f),
    DECLARE_CALL_ENTRY(glVertexAttrib4fv),
    DECLARE_CALL_ENTRY(glVertexAttribPointer),
    DECLARE_CALL_ENTRY(glViewport),


    /* GL_ES_VERSION_3_0 */
    DECLARE_CALL_ENTRY(glTexImage3D),
    DECLARE_CALL_ENTRY(glTexSubImage3D),
    //DECLARE_CALL_ENTRY(glCopyTexSubImage3D),
    //DECLARE_CALL_ENTRY(glCompressedTexImage3D),
    //DECLARE_CALL_ENTRY(glCompressedTexSubImage3D),
    DECLARE_CALL_ENTRY(glRenderbufferStorageMultisample),

    DECLARE_CALL_ENTRY(glDrawRangeElements),
    DECLARE_CALL_ENTRY(glDrawBuffers),
    DECLARE_CALL_ENTRY(glDrawArraysInstanced),
    DECLARE_CALL_ENTRY(glDrawElementsInstanced),

    DECLARE_CALL_ENTRY(glFenceSync),
    DECLARE_CALL_ENTRY(glIsSync),
    DECLARE_CALL_ENTRY(glDeleteSync),
    DECLARE_CALL_ENTRY(glClientWaitSync),
    DECLARE_CALL_ENTRY(glWaitSync),
    DECLARE_CALL_ENTRY(glGetSynciv),

    DECLARE_CALL_ENTRY(glProgramBinary),

    DECLARE_CALL_ENTRY(glGetQueryiv),
    DECLARE_CALL_ENTRY(glGetQueryObjectuiv),
    DECLARE_CALL_ENTRY(glGetIntegeri_v),
    DECLARE_CALL_ENTRY(glGetStringi),
    DECLARE_CALL_ENTRY(glGetInteger64v),
    DECLARE_CALL_ENTRY(glGetInteger64i_v),
    DECLARE_CALL_ENTRY(glGetSamplerParameteriv),
    DECLARE_CALL_ENTRY(glGetSamplerParameterfv),
    DECLARE_CALL_ENTRY(glGetInternalformativ),


    /* GL_ES_VERSION_3_1 */
    DECLARE_CALL_ENTRY(glDrawArraysIndirect),
    DECLARE_CALL_ENTRY(glDrawElementsIndirect),

    DECLARE_CALL_ENTRY(glGetFramebufferParameteriv),
    DECLARE_CALL_ENTRY(glGetBooleani_v),
    DECLARE_CALL_ENTRY(glGetMultisamplefv),
    DECLARE_CALL_ENTRY(glGetTexLevelParameteriv),
    DECLARE_CALL_ENTRY(glGetTexLevelParameterfv),


    /* GL_ES_VERSION_3_2 */
    DECLARE_CALL_ENTRY(glDrawElementsBaseVertex),
    DECLARE_CALL_ENTRY(glDrawRangeElementsBaseVertex),
    DECLARE_CALL_ENTRY(glDrawElementsInstancedBaseVertex),

    {0}
};


static void
create_egl_entry_table ()
{
    void *dl_handle = RTLD_NEXT;

    fprintf (stderr, "[GLEStrace] Create EGL entry table...\n");

    /*
     *  if Application links "libEGL.so" directly, RTLD_NEXT works well.
     *      +--------------------------+
     *      |        application       |
     *      +--------------------------+
     *      |      libGLEStrace.so     |  <--- insert by LD_PRELOAD
     *      +--------------------------+
     *      |   /real/path/libEGL.so   |  <--- RTLD_NEXT
     *      +--------------------------+
     */
    if (dlsym (RTLD_NEXT, "eglInitialize"))
    {
        fprintf (stderr, "[GLEStrace] found EGL symbol in default path (RTLD_NEXT).\n");
    }
    else
    {
        /*
         *  if Application doesn't link "libEGL.so",
         *   (probably application use dlopen("libEGL.so"))
         *  fake "libEGL.so" (symbolic linked to libGLEStrace.so) must be placed
         *  on the first place of LD_LIBRARY_PATH
         *
         *      +-----------------------------+
         *      |          application        |
         *      +-----------------------------+
         *      |libEGL.so@ -> libGLEStrace.so|  <--- the first place of LD_LIBRARY_PATH
         *      +---------------+-------------+
         *                      |
         *      +---------------+-------------+
         *      |     /real/path/libEGL.so    |  <--- dlopen(GLES_TRACE_REAL_LIBEGL)
         *      +-----------------------------+
         */
        const char libegl_fname_default[] = "libEGL.so.1";
        const char *libegl_fname = getenv ("GLES_TRACE_REAL_LIBEGL");
        if (libegl_fname == NULL)
            libegl_fname = libegl_fname_default;

        fprintf (stderr, "[GLEStrace] dlopen (\"%s\")\n", libegl_fname);
        dl_handle = dlopen (libegl_fname, RTLD_LAZY);
    }

    for (int i = 1; egl_entry_table[i].name; i ++)
    {
        egl_entry_table[i].func_ptr = dlsym (dl_handle, egl_entry_table[i].name);
        fprintf (stderr, "[GLEStrace]   egl_entry_table[%3d] %-30s: %p\n",
            i, egl_entry_table[i].name, egl_entry_table[i].func_ptr);
    }
}


static void
create_gles_entry_table ()
{
    void *dl_handle = RTLD_NEXT;

    fprintf (stderr, "[GLEStrace] Create GLES entry table...\n");
    if (dlsym (RTLD_NEXT, "glEnable"))
    {
        fprintf (stderr, "[GLEStrace] found GLES symbol in default path (RTLD_NEXT)\n");
    }
    else
    {
        const char libgles_fname_default[] = "libGLESv2.so.2";
        const char *liegles_fname = getenv ("GLES_TRACE_REAL_LIBGLES");
        if (liegles_fname == NULL)
            liegles_fname = libgles_fname_default;

        fprintf (stderr, "[GLEStrace] dlopen (\"%s\")\n", liegles_fname);
        dl_handle = dlopen (liegles_fname, RTLD_LAZY);
    }

    for (int i = 1; gles_entry_table[i].name; i ++)
    {
        gles_entry_table[i].func_ptr = dlsym (dl_handle, gles_entry_table[i].name);
        fprintf (stderr, "[GLEStrace]  gles_entry_table[%3d] %-30s: %p\n",
            i, gles_entry_table[i].name, gles_entry_table[i].func_ptr);
    }
}


static int
getenv_int (char *env_name, int default_var)
{
    char *var = getenv (env_name);
    if (var)
        return atoi (var);
    else
        return default_var;
}

static unsigned char *
getenv_str (char *env_name, unsigned char *default_var)
{
    char *var = getenv (env_name);
    if (var)
    return (unsigned char *)var;
    else
        return default_var;
}

void
prepare_gles_tracer ()
{
    if (s_init_done)
        return;

    fprintf (stderr, "[GLEStrace] -----------------------------------------\n");

    /* create EGL api entry table */
    create_egl_entry_table ();

    /* create GLES api entry table */
    create_gles_entry_table ();

    g_pid = getpid ();

    /* log output file */
    char fname_str[64];
    char *fname = getenv ("GLES_TRACE_LOG_FILE");
    if (fname == NULL)
    {
        snprintf (fname_str, sizeof (fname_str), "%05d_GLEStrace.txt", g_pid);
        fname = fname_str;
    }

    g_log_fp = fopen (fname, "w");
    if (g_log_fp == NULL)
        g_log_fp = stderr;

    /* GL_VERSION, GL_RENDERER, GL_VENDOR */
    g_force_gl_version_ptr   = getenv_str ("GLES_TRACE_FORCE_GL_VERSION",    NULL);
    g_force_gl_vendor_ptr    = getenv_str ("GLES_TRACE_FORCE_GL_VENDOR",     NULL);
    g_force_gl_renderer_ptr  = getenv_str ("GLES_TRACE_FORCE_GL_RENDERER",   NULL);
    g_force_gl_extension_ptr = getenv_str ("GLES_TRACE_FORCE_GL_EXTENSIONS", NULL);

    /* capture on draw */
    g_capture_on_draw  = getenv_int ("GLES_TRACE_CAPTURE_ON_DRAW", 0);
    g_capture_on_swap  = getenv_int ("GLES_TRACE_CAPTURE_ON_SWAP", 0);
    g_geterror_on_draw = getenv_int ("GLES_TRACE_GETERROR_ON_DRAW", 0);
    g_geterror_on_swap = getenv_int ("GLES_TRACE_GETERROR_ON_SWAP", 0);

    /* force render with lines */
    g_force_line_render  = getenv_int ("GLES_TRACE_FORCE_LINE_RENDER", 0);

    fprintf (stderr, "[GLEStrace] -----------------------------------------\n");
    fprintf (stderr, "[GLEStrace] Environment values\n");
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_LOG_FILE           : \"%s\"\n", fname);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_FORCE_GL_VERSION   : %s\n", g_force_gl_version_ptr);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_FORCE_GL_VENDOR    : %s\n", g_force_gl_vendor_ptr);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_FORCE_GL_RENDERER  : %s\n", g_force_gl_renderer_ptr);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_FORCE_GL_EXTENSIONS: %s\n", g_force_gl_extension_ptr);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_FORCE_LINE_RENDER  : %d\n", g_force_line_render);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_CAPTURE_ON_DRAW    : %d\n", g_capture_on_draw);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_CAPTURE_ON_SWAP    : %d\n", g_capture_on_swap);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_GETERROR_ON_DRAW   : %d\n", g_geterror_on_draw);
    fprintf (stderr, "[GLEStrace]  GLES_TRACE_GETERROR_ON_SWAP   : %d\n", g_geterror_on_swap);
    fprintf (stderr, "[GLEStrace] -----------------------------------------\n");
    fprintf (stderr, "[GLEStrace] pid: %d\n", g_pid);

    fprintf (stderr, "[GLEStrace] -----------------------------------------\n");
    s_init_done = 1;
}


pid_t
gles_trace_gettid ()
{
    return syscall(SYS_gettid);
}
