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
    fprintf(stderr, "Failed to load %s - Error: %s", sofile, load_error);

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
