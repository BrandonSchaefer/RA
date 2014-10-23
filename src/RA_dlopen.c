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

#include "RA_dlopen.h"

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int DebugModeOn()
{
  char const* debug = getenv("RA_DEBUGMODE");

  return debug && *debug == '1';
}

void* LoadObject(char const* sofile)
{
  void* handle = dlopen(sofile, RTLD_LAZY);
  char const* load_error = (char*)dlerror();

  if (DebugModeOn() && handle == NULL)
    fprintf(stderr, "Failed to load %s - Error: %s\n", sofile, load_error);

  return handle;
}

void* LoadFunction(void* handle, char const* name)
{
  /* Clear the last dlerror, so we can be sure theres no error in dlsym */
  dlerror();

  void* symbol;

  symbol = (void*)dlsym(handle, name);

  if (DebugModeOn() && (symbol == NULL || dlerror() != NULL))
    fprintf(stderr, "Failed loading %s : %s\n", name, (char const*)dlerror());

  return symbol;
}

void CloseObject(void* handle)
{
  if (handle != NULL)
  {
    int ret = dlclose(handle);

    if (DebugModeOn() && ret < 0)
      fprintf(stderr, "Failed to dlclose() handle: %p\n", (void*)handle);
  }
}
