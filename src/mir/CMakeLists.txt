find_package (PkgConfig)

set (BACKEND_REQUIRED
      sdl-backend
    )

pkg_check_modules(BACKEND REQUIRED ${BACKEND_REQUIRED})

set (SDL_SHOOTER_SRC
      Enemy.cpp
      Bullet.cpp
      Main.cpp
      Player.cpp
      ProjectileFactory.cpp
      ShooterMain.cpp
    )

set (SDL_SHOOTER_HDR
      Enemy.h
      Bullet.h
      Main.h
      Player.h
      ProjectileFactory.h
      ShooterMain.h
    )

add_executable(../sdl-shooter ${SDL_SHOOTER_SRC} ${SDL_SHOOTER_HDR})

include_directories(${BACKEND_INCLUDE_DIRS} ${CMAKE_BINARY_DIR} ${SDL_SHOOTER_GENERATORS_SOURCE_DIR}/src ${SDL_SHOOTER_GENERATORS_SOURCE_DIR})

target_link_libraries (../sdl-shooter ${BACKEND_LIBRARIES} ${BACKEND_LDFLAGS})

install (TARGETS ../sdl-shooter DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
