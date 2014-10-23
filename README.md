RA
==

RA - Figures out which backend you can render on. Such as MIR/WAYLAND/X11

Soft Dependencies
-----------------
  libx11-6
  libmirclient
  libwayland

How to Compile
--------------
  mkdir build
  cmake ..
  make -j4

How to Test
-----------
  ./ra_test
