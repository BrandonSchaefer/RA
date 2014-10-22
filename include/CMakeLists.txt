set(RA_PUBLIC_HDR
    RA_driver_available.h
   )

install(FILES ${RA_PUBLIC_HDR}
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RA)
