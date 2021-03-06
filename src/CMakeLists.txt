set(RA_SRC
    RA_driver_finder.c
   )

set(RA_HDR
     RA_sys.h
   )

if(CHECK_LINUX_DRIVERS)
  set(RA_SRC
      ${RA_SRC}
      RA_dlopen.c
      linux/RA_mir_driver.c
      linux/RA_wayland_driver.c
      linux/RA_x11_driver.c
     )

  set(RA_HDR
      ${RA_HDR}
      RA_dlopen.h
     )

  set (PREFIXDIR   "${CMAKE_INSTALL_PREFIX}")
  set (EXEC_PREFIX "${CMAKE_INSTALL_PREFIX}")
  set (LIBDIR      "${CMAKE_INSTALL_PREFIX}/lib")
  set (INCLUDEDIR  "${CMAKE_INSTALL_PREFIX}/include")

  configure_file (ra.pc.cmake ${CMAKE_CURRENT_BINARY_DIR}/ra.pc @ONLY)
  install (FILES ${CMAKE_CURRENT_BINARY_DIR}/ra.pc
           DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)
endif()


include_directories(${CMAKE_BINARY_DIR}/include ${CMAKE_SOURCE_DIR}/include)

add_library (ra SHARED ${RA_SRC} ${RA_HDR})

install (TARGETS ra
         RUNTIME DESTINATION bin
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib
        )

add_subdirectory(test)
