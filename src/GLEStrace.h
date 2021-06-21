#ifndef GLES_TRACE_H_
#define GLES_TRACE_H_

#include <sys/types.h>
#include <unistd.h>

#define GL_GLEXT_PROTOTYPES

#include <EGL/egl.h>

#if defined (USE_GLES_32)
#include <GLES3/gl32.h>
#include <GLES3/gl3ext.h>
#include <GLES2/gl2ext.h>

#elif defined (USE_GLES_31)
#include <GLES3/gl31.h>
#include <GLES3/gl3ext.h>

#elif defined (USE_GLES_30)
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>

#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif


typedef struct gles_entry_t
{
    char    *name;
    void    (*func_ptr)(void *);
    void    (*wrap_ptr)(void *);
} gles_entry_t;

#define DECLARE_CALL_ENTRY(name)    { #name, NULL, (void *)name }

#define EGL_ENTRY(idx)              (egl_entry_table[idx])
#define EGL_ENTRY_PTR(idx)          (EGL_ENTRY(idx).func_ptr)
#define EGL_ENTRY_NAME(idx)         (EGL_ENTRY(idx).name)
#define EGL_ENTRY_WRAP_PTR(idx)     (EGL_ENTRY(idx).wrap_ptr)

#define GLES_ENTRY(idx)             (gles_entry_table[idx])
#define GLES_ENTRY_PTR(idx)         (GLES_ENTRY(idx).func_ptr)
#define GLES_ENTRY_NAME(idx)        (GLES_ENTRY(idx).name)
#define GLES_ENTRY_WRAP_PTR(idx)    (GLES_ENTRY(idx).wrap_ptr)

enum egl_entry_idx
{
    egl_dummy = 0,

    /* EGL_VERSION_1_0 */
    eglChooseConfig_Idx,
    eglCopyBuffers_Idx,
    eglCreateContext_Idx,
    eglCreatePbufferSurface_Idx,
    eglCreatePixmapSurface_Idx,
    eglCreateWindowSurface_Idx,
    eglDestroyContext_Idx,
    eglDestroySurface_Idx,
    eglGetConfigAttrib_Idx,
    eglGetConfigs_Idx,
    eglGetCurrentDisplay_Idx,
    eglGetCurrentSurface_Idx,
    eglGetDisplay_Idx,
    eglGetError_Idx,
    eglGetProcAddress_Idx,
    eglInitialize_Idx,
    eglMakeCurrent_Idx,
    eglQueryContext_Idx,
    eglQueryString_Idx,
    eglQuerySurface_Idx,
    eglSwapBuffers_Idx,
    eglTerminate_Idx,
    eglWaitGL_Idx,
    eglWaitNative_Idx,

    /* EGL_VERSION_1_1 */
    eglBindTexImage_Idx,
    eglReleaseTexImage_Idx,
    eglSurfaceAttrib_Idx,
    eglSwapInterval_Idx,

    /* EGL_VERSION_1_2 */
    eglBindAPI_Idx,
    eglQueryAPI_Idx,
    eglCreatePbufferFromClientBuffer_Idx,
    eglReleaseThread_Idx,
    eglWaitClient_Idx,

    /* EGL_VERSION_1_4 */
    eglGetCurrentContext_Idx,

    /* EGL_VERSION_1_5 */
    eglCreateSync_Idx,
    eglDestroySync_Idx,
    eglClientWaitSync_Idx,
    eglGetSyncAttrib_Idx,
    eglCreateImage_Idx,
    eglDestroyImage_Idx,
    eglGetPlatformDisplay_Idx,
    eglCreatePlatformWindowSurface_Idx,
    eglCreatePlatformPixmapSurface_Idx,
    eglWaitSync_Idx,

    eglAPIMAX_Idx
};

enum gles_entry_idx
{
    gles_dummy = 0,

    /* GLES */
    glActiveTexture_Idx,
    glAttachShader_Idx,
    glBindAttribLocation_Idx,
    glBindBuffer_Idx,
    glBindFramebuffer_Idx,
    glBindRenderbuffer_Idx,
    glBindTexture_Idx,
    glBlendColor_Idx,
    glBlendEquation_Idx,
    glBlendEquationSeparate_Idx,
    glBlendFunc_Idx,
    glBlendFuncSeparate_Idx,
    glBufferData_Idx,
    glBufferSubData_Idx,
    glCheckFramebufferStatus_Idx,

    glClear_Idx,
    glClearColor_Idx,
    glClearDepthf_Idx,
    glClearStencil_Idx,
    glColorMask_Idx,
    glCompileShader_Idx,
    glCompressedTexImage2D_Idx,
    glCompressedTexSubImage2D_Idx,
    glCopyTexImage2D_Idx,
    glCopyTexSubImage2D_Idx,
    glCreateProgram_Idx,
    glCreateShader_Idx,
    glCullFace_Idx,

    glDeleteBuffers_Idx,
    glDeleteFramebuffers_Idx,
    glDeleteProgram_Idx,
    glDeleteRenderbuffers_Idx,
    glDeleteShader_Idx,
    glDeleteTextures_Idx,
    glDepthFunc_Idx,
    glDepthMask_Idx,
    glDepthRangef_Idx,
    glDetachShader_Idx,
    glDisable_Idx,
    glDisableVertexAttribArray_Idx,
    glDrawArrays_Idx,
    glDrawElements_Idx,

    glEnable_Idx,
    glEnableVertexAttribArray_Idx,
    glFinish_Idx,
    glFlush_Idx,
    glFramebufferRenderbuffer_Idx,
    glFramebufferTexture2D_Idx,
    glFrontFace_Idx,
    glGenBuffers_Idx,
    glGenerateMipmap_Idx,
    glGenFramebuffers_Idx,
    glGenRenderbuffers_Idx,
    glGenTextures_Idx,

    glGetActiveAttrib_Idx,
    glGetActiveUniform_Idx,
    glGetAttachedShaders_Idx,
    glGetAttribLocation_Idx,
    glGetBooleanv_Idx,
    glGetBufferParameteriv_Idx,
    glGetError_Idx,
    glGetFloatv_Idx,
    glGetFramebufferAttachmentParameteriv_Idx,
    glGetIntegerv_Idx,
    glGetProgramiv_Idx,
    glGetProgramInfoLog_Idx,
    glGetRenderbufferParameteriv_Idx,
    glGetShaderiv_Idx,
    glGetShaderInfoLog_Idx,
    glGetShaderPrecisionFormat_Idx,
    glGetShaderSource_Idx,
    glGetString_Idx,
    glGetTexParameterfv_Idx,
    glGetTexParameteriv_Idx,
    glGetUniformfv_Idx,
    glGetUniformiv_Idx,
    glGetUniformLocation_Idx,
    glGetVertexAttribfv_Idx,
    glGetVertexAttribiv_Idx,
    glGetVertexAttribPointerv_Idx,
    glHint_Idx,

    glIsBuffer_Idx,
    glIsEnabled_Idx,
    glIsFramebuffer_Idx,
    glIsProgram_Idx,
    glIsRenderbuffer_Idx,
    glIsShader_Idx,
    glIsTexture_Idx,

    glLineWidth_Idx,
    glLinkProgram_Idx,
    glPixelStorei_Idx,
    glPolygonOffset_Idx,
    glReadPixels_Idx,
    glReleaseShaderCompiler_Idx,
    glRenderbufferStorage_Idx,
    glSampleCoverage_Idx,
    glScissor_Idx,
    glShaderBinary_Idx,
    glShaderSource_Idx,

    glStencilFunc_Idx,
    glStencilFuncSeparate_Idx,
    glStencilMask_Idx,
    glStencilMaskSeparate_Idx,
    glStencilOp_Idx,
    glStencilOpSeparate_Idx,

    glTexImage2D_Idx,
    glTexParameterf_Idx,
    glTexParameterfv_Idx,
    glTexParameteri_Idx,
    glTexParameteriv_Idx,
    glTexSubImage2D_Idx,

    glUniform1f_Idx,
    glUniform1fv_Idx,
    glUniform1i_Idx,
    glUniform1iv_Idx,
    glUniform2f_Idx,
    glUniform2fv_Idx,
    glUniform2i_Idx,
    glUniform2iv_Idx,
    glUniform3f_Idx,
    glUniform3fv_Idx,
    glUniform3i_Idx,
    glUniform3iv_Idx,
    glUniform4f_Idx,
    glUniform4fv_Idx,
    glUniform4i_Idx,
    glUniform4iv_Idx,
    glUniformMatrix2fv_Idx,
    glUniformMatrix3fv_Idx,
    glUniformMatrix4fv_Idx,

    glUseProgram_Idx,
    glValidateProgram_Idx,
    glVertexAttrib1f_Idx,
    glVertexAttrib1fv_Idx,
    glVertexAttrib2f_Idx,
    glVertexAttrib2fv_Idx,
    glVertexAttrib3f_Idx,
    glVertexAttrib3fv_Idx,
    glVertexAttrib4f_Idx,
    glVertexAttrib4fv_Idx,
    glVertexAttribPointer_Idx,
    glViewport_Idx,


    /* GL_ES_2_0_EXT */
    glTexBufferOES_Idx,
    glTexBufferRangeOES_Idx,
    glDrawArraysInstancedBaseInstanceEXT_Idx,
    glDrawElementsInstancedBaseInstanceEXT_Idx,
    glDrawElementsInstancedBaseVertexBaseInstanceEXT_Idx,


    /* GL_ES_VERSION_3_0 */
    glReadBuffer_Idx,
    glBlitFramebuffer_Idx,
    glTexImage3D_Idx,
    glTexSubImage3D_Idx,
    //glCopyTexSubImage3D_Idx,
    //glCompressedTexImage3D_Idx,
    //glCompressedTexSubImage3D_Idx,
    glUnmapBuffer_Idx,
    glRenderbufferStorageMultisample_Idx,
    glMapBufferRange_Idx,
    glFlushMappedBufferRange_Idx,

    glDrawRangeElements_Idx,
    glDrawBuffers_Idx,
    glDrawArraysInstanced_Idx,
    glDrawElementsInstanced_Idx,

    glBindVertexArray_Idx,
    glDeleteVertexArrays_Idx,
    glGenVertexArrays_Idx,
    glVertexAttribIPointer_Idx,

    glFenceSync_Idx,
    glIsSync_Idx,
    glDeleteSync_Idx,
    glClientWaitSync_Idx,
    glWaitSync_Idx,
    glGetSynciv_Idx,

    glGetProgramBinary_Idx,
    glProgramBinary_Idx,
    glProgramParameteri_Idx,

    glGetQueryiv_Idx,
    glGetQueryObjectuiv_Idx,
    glGetIntegeri_v_Idx,
    glGetStringi_Idx,
    glGetInteger64v_Idx,
    glGetInteger64i_v_Idx,
    glGetSamplerParameteriv_Idx,
    glGetSamplerParameterfv_Idx,
    glGetInternalformativ_Idx,

    glGenSamplers_Idx,
    glDeleteSamplers_Idx,
    glBindSampler_Idx,
    glSamplerParameteri_Idx,
    glSamplerParameteriv_Idx,
    glSamplerParameterf_Idx,
    glSamplerParameterfv_Idx,

    glVertexAttribDivisor_Idx,

    glInvalidateFramebuffer_Idx,
    glInvalidateSubFramebuffer_Idx,
    glTexStorage2D_Idx,


    /* GL_ES_VERSION_3_1 */
    glDrawArraysIndirect_Idx,
    glDrawElementsIndirect_Idx,

    glGetFramebufferParameteriv_Idx,
    glGetBooleani_v_Idx,
    glMemoryBarrier_Idx,
    glGetMultisamplefv_Idx,
    glGetTexLevelParameteriv_Idx,
    glGetTexLevelParameterfv_Idx,

    /* GL_ES_VERSION_3_2 */
    glDrawElementsBaseVertex_Idx,
    glDrawRangeElementsBaseVertex_Idx,
    glDrawElementsInstancedBaseVertex_Idx,
    glPatchParameteri_Idx,
    glTexBuffer_Idx,
    glTexBufferRange_Idx,

    glAPIMAX_Idx
};

extern gles_entry_t     egl_entry_table[];
extern gles_entry_t     gles_entry_table[];
extern FILE             *g_log_fp;
extern pid_t            g_pid;
extern int              g_frame_counter;
extern int              g_draw_counter;
extern int              g_capture_on_swap;
extern int              g_capture_on_draw;
extern int              g_geterror_on_swap;
extern int              g_geterror_on_draw;
extern int              g_force_line_render;
extern unsigned char    *g_force_gl_version_ptr;
extern unsigned char    *g_force_gl_vendor_ptr;
extern unsigned char    *g_force_gl_renderer_ptr;
extern unsigned char    *g_force_gl_extension_ptr;

void  prepare_gles_tracer ();
pid_t gles_trace_gettid ();

#endif /* GLES_TRACE_H_ */
