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
