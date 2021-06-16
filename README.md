# Simple & Tiny OpenGLES API Trace Tool.
- Doesn't require any external libraries.
- Trace OpenGLES API calls to a log file.
- Inject some functions that are useful to debug the target application.


## 1. How to build
```
$ make
$ cp libGLEStrace.so ~/lib
```

## 2. Usage
There are two methods to trace. choose the appropriate one depending on the target application.

### 2.1. API hook by using `LD_PRELOAD`

If the target application was linked with `libEGL.so` and `libGLESv2.so` on build phase, just set `LD_PRELOAD` and run the app.
most of the apps will work fine this way.
```
$ export LD_PRELOAD="~/lib/libGLEStrace.so"
$ your_target_gles_app
```

### 2.2. API hook by using `LD_LIBRARY_PATH`

If the target application wasn't linked with `libEGL.so` (probably application use `dlopen("libEGL.so")`), 
place a fake-`libEGL.so` and a fake-`libGLESv2.so` in the first place of `LD_LIBRARY_PATH`.
(Here, fake-ilb means a symbolic linke to `libGLEStrace.so`.)
And then, set `GLES_TRACE_REAL_LIBEGL` and `GLES_TRACE_REAL_LIBGLES` so that the fake library can found the real libraries.

```
$ unset LD_PRELOAD
$
$ cd ~/lib
$ ln -s libGLEStrace.so libEGL.so
$ ln -s libGLEStrace.so libGLESv2.so
$ export LD_LIBRARY_PATH=~/lib/:$LD_LIBRARY_PATH
$
$ export GLES_TRACE_REAL_LIBEGL=/usr/lib/[cputype]-linux-gnu/libEGL.so
$ export GLES_TRACE_REAL_LIBGLES=/usr/lib/[cputype]-linux-gnu/libGLESv2.so
$
$ your_target_gles_app
```


## 3. Customize
You can customize the befavior of the wrapper library. This may help you debug the target application.

### 3.1. log file name 
The default log file name is `pid_GLEStrace.txt`. If you want to change the name of the log file, set as below.
```
$ export GLES_TRACE_LOG_FILE="trace_log.txt"
```

### 3.2. force replacement of GL environment information in wrapper library
If you want to force the replacement of the `GL_VERSION/GL_VENDOR/GL_RENDERER/GL_EXTENSIONS` values, set the following environment values.
```
$ export GLES_TRACE_FORCE_GL_VERSION="OpenGL ES 2.0"
$ export GLES_TRACE_FORCE_GL_VENDOR="Dummy vendor"
$ export GLES_TRACE_FORCE_GL_RENDERER="Dummy renderer"
$ export GLES_TRACE_FORCE_GL_EXTENSIONS="Dummy_extension"
```

### 3.3. capture rendered image
If you want to capture the rendered image on each drawing API or swapping API, set the following environment values.
```
$ export GLES_TRACE_CAPTURE_ON_DRAW=1    # capture on each drawing API
$ export GLES_TRACE_CAPTURE_ON_SWAP=1    # capture on each swapping API
```

### 3.4. inject an error check function
```
$ export GLES_TRACE_GETERROR_ON_DRAW=1   # call glGetError() on each drawing API
$ export GLES_TRACE_GETERROR_ON_SWAP=1   # call glGetError() on each swapping API
```


## 4. Status
Yes, it is still under development.


## 5. Alternatives
more powerful tools are:
- https://github.com/baldurk/renderdoc
- https://github.com/apitrace/apitrace
