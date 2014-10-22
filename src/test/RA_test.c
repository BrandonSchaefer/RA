// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
* Copyright (C) 2014 Brandon Schaefer
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Authored by: Brandon Schaefer <brandontschaefer@gmail.com>
*/

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
