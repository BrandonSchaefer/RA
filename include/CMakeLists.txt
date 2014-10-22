configure_file(${CMAKE_SOURCE_DIR}/include/RA_config.h.cmake ${CMAKE_BINARY_DIR}/include/RA_config.h)

set(RA_PUBLIC_HDR
    RA_driver_finder.h
   )

install(FILES ${RA_PUBLIC_HDR}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RA)
