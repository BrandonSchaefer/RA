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

#include "../RA_sys.h"
#include "../RA_dlopen.h"

#include <stddef.h>

#define DEFAULT_MIR_LIB "libmirclient.so"

#define MIR_CONNECT_SYNC    "mir_connect_sync"
#define MIR_CONNECT_RELEASE "mir_connection_release"
#define MIR_CONNECT_VALID   "mir_connection_is_valid"

static int MIR_Available(void)
{
  void* (*connect) (char const* server, char const* app_name);
  //void  (*release) (void* connection);
  int   (*valid)   (void* connection);

  void* handle = NULL;
  void* connection;
  int ret;

  handle  = LoadObject(DEFAULT_MIR_LIB);

  if (handle != NULL)
  {
    connect = LoadFunction(handle, MIR_CONNECT_SYNC);
    //release = LoadFunction(handle, MIR_CONNECT_RELEASE);
    valid   = LoadFunction(handle, MIR_CONNECT_VALID);

    if (connect != NULL &&
        //release != NULL &&
        valid   != NULL)
    {

      connection = connect(NULL, __PRETTY_FUNCTION__);

      ret = valid(connection);

      // FIXME Something is strange causing a SIGHUP after a release?
      //if (ret)
        //release(connection);
    }

    CloseObject(handle);
  }

  return ret;
}

VideoDriver MIR_driver = { "Mir", &MIR_Available };
