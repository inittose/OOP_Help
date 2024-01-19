cmake_minimum_required(VERSION 3.5)

project(lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rstore main.cpp
    taxpayer.h taxpayer.cpp
    menu.h menu.cpp)

include(GNUInstallDirs)
install(TARGETS rstore
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
