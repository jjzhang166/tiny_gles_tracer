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

    if (eglGetProcAddress_)
        func = eglGetProcAddress_ (procname);

    for (int i = 0; i < glAPIMAX_Idx; i ++)
    {
        if (GLES_ENTRY_NAME(i) == NULL)
            continue;

        if (strcmp (procname, GLES_ENTRY_NAME(i)) == 0)
        {
            /* if dlsym() can't get this function,
               replace it with the func obtained by eglGetProcAddress() */
            if (GLES_ENTRY_PTR (i) == NULL)
            {
                fprintf (g_log_fp, "[replace]");
                GLES_ENTRY_PTR (i) = (void *)func;
            }

            /* if the function is successfully retrieved by dlsym() or eglGetProcAddress(),
               return the wrapper function */
            if (GLES_ENTRY_PTR (i))
            {
                void *wrap_func = GLES_ENTRY_WRAP_PTR(i);
                fprintf (g_log_fp, "found in wrapper:%p\n", wrap_func);
                return wrap_func;
            }
        }
    }

    fprintf (g_log_fp, "%p\n", func);
    return func;
}

