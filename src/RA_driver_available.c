#include <RA_available_driver.h>

#if CHECK_LINUX_DRIVERS
int RA_Mir_Available()
{
  return 0;
}

int RA_Wayland_Avaiable()
{
  return 0;
}

int RA_X11_Available()
{
  return 0;
}
#endif /* CHECK_LINUX_DRIVERS */
