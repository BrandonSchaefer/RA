#include "../RA_dlopen.h"
#include "../RA_sys.h"

#include <stddef.h>

#define DEFAULT_X11_LIB "libX11.so"

#define X_OPEN_DISPLAY  "XOpenDisplay"
#define X_CLOSE_DISPLAY "XCloseDisplay"

static int X11_Available(void)
{
  void* (*open_display)  (char* display_name);
  void  (*close_display) (void* display);

  void* handle = LoadObject(DEFAULT_X11_LIB);
  void* display;
  int ret = 0;

  open_display  = LoadFunction(handle, X_OPEN_DISPLAY);
  close_display = LoadFunction(handle, X_CLOSE_DISPLAY);

  display = open_display(NULL);

  if (display != NULL)
  {
    ret = 1;
    close_display(display);
  }

  CloseObject(handle);

  return ret;
}

VideoDriver X11_driver = { "X11", &X11_Available };
