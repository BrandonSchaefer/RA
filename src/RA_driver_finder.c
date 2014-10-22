#include <string.h>
#include <stddef.h>

#include <RA_config.h>
#include "RA_sys.h"

static VideoDriver* drivers[] =
{
#if CHECK_LINUX_DRIVERS
  &MIR_driver,
  &WAYLAND_driver,
  &X11_driver,
#endif
  NULL
};

int RA_CheckVideoDriverAvailable(char const* driver_name)
{
  int i = 0;
  while (drivers[i] != NULL)
  {
    if (strcmp(drivers[i]->name, driver_name) == 0)
    {
      return drivers[i]->available();
    }

    i++;
  }

  return 0;
}
