#ifndef RA_DRIVER_AVAIABLE
#define RA_DRIVER_AVAIABLE

#if CHECK_LINUX_DRIVERS
extern int RA_Mir_Available();
extern int RA_Wayland_Avaiable();
extern int RA_X11_Available();
#endif /* CHECK_LINUX_DRIVERS */

#endif /* RA_DRIVER_AVAIABLE */
