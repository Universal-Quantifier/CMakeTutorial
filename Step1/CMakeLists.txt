cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

if(USE_MYMATH)
  # add the MathFunctions library
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

# add the executable
add_executable(Tutorial tutorial.cc)

#  configure a header file to pass the version number to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add that directory to the list of paths to search for include files.
# so that we will find TutorialConfig.h
# PROJECT_BINARY_DIR: Full path to build directory for project. This is the binary directory of the most recent project() command.
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )