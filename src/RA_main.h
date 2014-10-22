typedef struct VideoBootstrap
{
  char const* name;
  int (*available) (void);
} VideoBootstrap;

#if CHECK_LINUX_DRIVERS
extern VideoBootstrap MIR_bootstrap;
extern VideoBootstrap X11_bootstrap;
#endif
