prefix=@PREFIXDIR@
exec_prefix=@EXEC_PREFIX@
libdir=@LIBDIR@
includedir=@INCLUDEDIR@

Name: RA
Library
Description: A simple library which dynamically detects which video driver is available
Version: @VERSION@
Libs: -L${libdir} -lra
Cflags: -I${includedir}
Requires: dl
