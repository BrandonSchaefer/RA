set(RA_SRC
     mir/RA_mirdevice.c
     x11/RA_x11device.c
     RA_main.c
     RA_dlopen.c
   )

set(RA_HDR
     RA_dlopen.h
     RA_main.h
   )

include_directories(${CMAKE_BINARY_DIR}/include)

add_executable(../ra_test ${RA_SRC} ${RA_HDR})

#FIXME Add a check if dlopen is around, if not :(
target_link_libraries(../ra_test -ldl)

#add_subdirectory(mir)
#add_subdirectory(x11)
