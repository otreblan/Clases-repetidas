cmake_minimum_required(VERSION 3.10.0)

include(GNUInstallDirs)
include(FindPkgConfig)

# El nombre del proyecto
project(clases)

# Unas cuantas definiciones
set(SRC_DIR ./src)
set(SOURCES
	${SRC_DIR}/main.cpp
	)

if(NOT DEFINED ENV{CXXFLAGS})
	set(CMAKE_CXX_FLAGS "-Wall -g")
endif()

add_executable(${PROJECT_NAME} ${SOURCES})

# Install target
install(TARGETS clase
	DESTINATION ${CMAKE_INSTALL_BINDIR}
	)

