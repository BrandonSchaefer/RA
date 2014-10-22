set(RA_TEST_SRC
   )

if(CHECK_LINUX_DRIVERS)
  set(RA_TEST_SRC
      ${RA_TEST_SRC}
      RA_test.c
     )
endif()

include_directories(${CMAKE_BINARY_DIR}/include ${CMAKE_SOURCE_DIR}/include ${RA_LIB_INCLUDE_DIRS})

add_executable(../../ra_test ${RA_TEST_SRC})

target_link_libraries(../../ra_test ra ${CMAKE_DL_LIBS})
