#include <RA_config.h>
#include "RA_sys.h"

#include <stdio.h>

static VideoDriver* drivers[] =
{
#if CHECK_LINUX_DRIVERS
  &MIR_driver,
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