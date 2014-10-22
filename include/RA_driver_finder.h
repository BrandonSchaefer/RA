#ifndef RA_DRIVER_FINDER
#define RA_DRIVER_FINDER

#define MIR_DRIVER     "Mir"
#define WAYLAND_DRIVER "Wayland"
#define X11_DRIVER     "X11"

extern int RA_CheckVideoDriverAvailable(char const* driver_name);

#endif /* RA_DRIVER_FINDER */
