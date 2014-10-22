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

#ifndef RA_SYS_H
#define RA_SYS_H

typedef struct VideoDriver
{
  char const* name;
  int (*available) (void);
} VideoDriver;

#if CHECK_LINUX_DRIVERS
extern VideoDriver MIR_driver;
extern VideoDriver WAYLAND_driver;
extern VideoDriver X11_driver;
#endif

#endif /* RA_SYS_H */
