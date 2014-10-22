#include <RA_config.h>
#include "../RA_sys.h"

#include <RA_driver_available.h>

#include <stdio.h>

/* TODO Move me to an actual API file, where we can check what is around and not. */
static VideoDriver* drivers[] =
{
#if CHECK_LINUX_DRIVERS
  &MIR_driver,
  &WAYLAND_driver,
  &X11_driver,
#endif
  NULL
};

int main()
{
  int i = 0;
  while (drivers[i] != NULL)
  {
    if (drivers[i]->available() == 1)
    {
      printf("Driver %s is available!\n", drivers[i]->name);
    }
    else
    {
      printf("Driver %s is not available!\n", drivers[i]->name);
    }

    i++;
  }

  return 0;
}
