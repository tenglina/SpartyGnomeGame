cmake_minimum_required(VERSION 3.21)
project(Project1)
set(APPLICATION_LIBRARY Project1Lib)

set(CMAKE_CXX_STANDARD 17)


set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_subdirectory(${APPLICATION_LIBRARY}) # ADD THE LIBRARY WHEN WE HAVE ONE (name on folder)
include_directories(${APPLICATION_LIBRARY})

# Define a variable containing a list of source files for the project
# Add files in as we go !!!!!
set(SOURCE_FILES main.cpp pch.h GameApp.cpp GameApp.h Project1Lib/Platform.cpp Project1Lib/Platform.h Project1Lib/Game.cpp Project1Lib/Game.h)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCE_FILES})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${APPLICATION_LIBRARY})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)
add_subdirectory(Tests)
