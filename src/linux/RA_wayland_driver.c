#include "../RA_dlopen.h"
#include "../RA_sys.h"

#include <stddef.h>

static void* (*open_display)  (char* display_name);
static void  (*close_display) (void* display);

#define DEFAULT_WAYLAND_LIB "libwayland-client.so"

#define WL_CONNECT    "wl_display_connect"
#define WL_DISCONNECT "wl_display_disconnect"

static int WAYLAND_Available(void)
{
  void* handle = LoadObject(DEFAULT_WAYLAND_LIB);
  int ret = 0;

  open_display  = LoadFunction(handle, WL_CONNECT);
  close_display = LoadFunction(handle, WL_DISCONNECT);

  void* display = open_display(NULL);

  if (display != NULL)
  {
    ret = 1;
    close_display(display);
  }

  CloseObject(handle);

  return ret;
}

VideoDriver WAYLAND_driver = { "WAYLAND", &WAYLAND_Available };
