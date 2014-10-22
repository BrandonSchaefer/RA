#include "../RA_dlopen.h"
#include "../RA_sys.h"

#include <stddef.h>

#define DEFAULT_WAYLAND_LIB "libwayland-client.so"

#define WL_CONNECT    "wl_display_connect"
#define WL_DISCONNECT "wl_display_disconnect"

static int WAYLAND_Available(void)
{
  void* (*open_display)  (char* display_name);
  void  (*close_display) (void* display);

  void* handle = LoadObject(DEFAULT_WAYLAND_LIB);
  void* display;
  int ret = 0;

  if (handle != NULL)
  {
    open_display  = LoadFunction(handle, WL_CONNECT);
    close_display = LoadFunction(handle, WL_DISCONNECT);

    if (open_display != NULL && close_display != NULL)
    {
      display = open_display(NULL);

      if (display != NULL)
      {
        ret = 1;
        close_display(display);
      }
    }

    CloseObject(handle);
  }

  return ret;
}

VideoDriver WAYLAND_driver = { "Wayland", &WAYLAND_Available };
