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

#include <RA_driver_finder.h>

#include <stdio.h>

int main()
{
  printf("Mir video driver is     : %i\n", RA_CheckVideoDriverAvailable(MIR_DRIVER));
  printf("Wayland video driver is : %i\n", RA_CheckVideoDriverAvailable(WAYLAND_DRIVER));
  printf("X11 video driver is     : %i\n", RA_CheckVideoDriverAvailable(X11_DRIVER));

  return 0;
}
