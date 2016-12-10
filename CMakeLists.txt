cmake_minimum_required( VERSION 3.0.0 )
project( CrystalBind )


### Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/arch")

### Compilation configuration ###
if(MSVC)
    ### Enable parallel compilation for Visual Studio
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /bigobj")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /w") # disable all warnings (not ideal but...)
else()
    #### Libigl requires a modern C++ compiler that supports c++11
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w") # disable all warnings (not ideal but...)
endif()

### Set enviroments variables
set( CRYSTALBIND               "${PROJECT_NAME}" )
set( CRYSTALBIND_ROOT          "${PROJECT_SOURCE_DIR}" )
set( CRYSTALBIND_INCLUDE_DIRS  "${PROJECT_SOURCE_DIR}/include" )
set( CRYSTALBIND_DEFINITIONS   "" )
set( CRYSTALBIND_EXTRA_LIBS    "" )

### Third party find manualy
set( NODE_INCLUDE "NODE_INCLUDE NOT FOUND" CACHE PATH "Include dir of node" )

list( APPEND CRYSTALBIND_INCLUDE_DIRS ${NODE_INCLUDE} )

include_directories( ${CRYSTALBIND_INCLUDE_DIRS} )
add_library( ${PROJECT_NAME} "crystal_bind.cc" )