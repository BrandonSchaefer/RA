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

#include "../RA_dlopen.h"
#include "../RA_sys.h"

#include <stddef.h>

#include <stdio.h>

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

  if (handle != NULL)
  {
    open_display  = LoadFunction(handle, X_OPEN_DISPLAY);
    close_display = LoadFunction(handle, X_CLOSE_DISPLAY);

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

VideoDriver X11_driver = { "X11", &X11_Available };
