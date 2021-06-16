#include <stdio.h>
#include <string.h>
#include "GLEStrace.h"

#define eglGetProcAddress_  \
    ((__eglMustCastToProperFunctionPointerType (*)(const char *procname))  \
    EGL_ENTRY_PTR(eglGetProcAddress_Idx))


EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY
eglGetProcAddress (const char *procname)
{
    prepare_gles_tracer ();

    fprintf (g_log_fp, "eglGetProcAddress(\"%-30s\"); // ", procname);

    __eglMustCastToProperFunctionPointerType func = NULL;

#if 1
    for (int i = 0; i < glAPIMAX_Idx; i ++)
    {
        if (GLES_ENTRY_NAME(i) == NULL)
            continue;

        if (strcmp (procname, GLES_ENTRY_NAME(i)) == 0)
        {
            func = (__eglMustCastToProperFunctionPointerType)GLES_ENTRY_WRAP_PTR(i);
            fprintf (g_log_fp, "found in wrapper:%p\n", func);
            return func;
        }
    }
#endif

    if (eglGetProcAddress_)
        func = eglGetProcAddress_ (procname);

    fprintf (g_log_fp, "%p\n", func);
    return func;
}

