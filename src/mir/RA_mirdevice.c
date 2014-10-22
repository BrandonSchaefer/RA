#include "../RA_main.h"
#include "../RA_dlopen.h"

#include <stddef.h>

static void* (*connect) (char const* server, char const* app_name);
static void  (*release) (void* connection);
static int   (*valid)   (void* connection);

#define DEFAULT_MIR_LIB "libmirclient.so"

#define MIR_CONNECT_SYNC    "mir_connect_sync"
#define MIR_CONNECT_RELEASE "mir_connection_release"
#define MIR_CONNECT_VALID   "mir_connection_is_valid"

static int MIR_Available(void)
{
  void* handle = NULL;
  handle  = LoadObject(DEFAULT_MIR_LIB);

  connect = LoadFunction(handle, MIR_CONNECT_SYNC);
  valid   = LoadFunction(handle, MIR_CONNECT_VALID);

  void* connection = connect(NULL, __PRETTY_FUNCTION__);

  int ret = valid(connection);

  if (ret)
    release(connection);

  CloseObject(handle);

  return ret;
}

VideoBootstrap MIR_bootstrap = { "Mir", &MIR_Available };
