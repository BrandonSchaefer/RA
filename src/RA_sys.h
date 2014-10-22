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
