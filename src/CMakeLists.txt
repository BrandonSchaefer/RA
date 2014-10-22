set(RA_SRC
     RA_test.c
     RA_dlopen.c
   )

if(CHECK_LINUX_DRIVERS)
  set(RA_SRC
      ${RA_SRC}
      linux/RA_mir_driver.c
      linux/RA_x11_driver.c
     )
endif()

set(RA_HDR
     RA_dlopen.h
     RA_sys.h
   )

include_directories(${CMAKE_BINARY_DIR}/include)

add_executable(../ra_test ${RA_SRC} ${RA_HDR})

#FIXME Add a check if dlopen is around, if not :(
target_link_libraries(../ra_test -ldl)
