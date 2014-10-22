#include "../RA_dlopen.h"
#include "../RA_main.h"

#include <stddef.h>

static void* (*open_display)  (char* display_name);
static void  (*close_display) (void* display);

#define DEFAULT_X11_LIB "libX11.so"

#define X_OPEN_DISPLAY  "XOpenDisplay"
#define X_CLOSE_DISPLAY "XCloseDisplay"

static int X11_Available(void)
{
  void* handle = LoadObject(DEFAULT_X11_LIB);
  int ret = 0;

  open_display  = LoadFunction(handle, X_OPEN_DISPLAY);
  close_display = LoadFunction(handle, X_CLOSE_DISPLAY);

  void* display = open_display(NULL);

  if (display != NULL)
  {
    ret = 1;
    close_display(display);
  }

  CloseObject(handle);

  return ret;
}

VideoBootstrap X11_bootstrap = { "X11", &X11_Available };
