cmake_minimum_required(VERSION 3.21)
project(PingPong)

set(CMAKE_CXX_STANDARD 14)

add_executable(PingPong main.cpp ball.cpp ball.h Game.cpp Game.h GameScreen.cpp GameScreen.h Player.cpp Player.h PlayerUI.cpp PlayerUI.h pos.h constante.h)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PingPong ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()