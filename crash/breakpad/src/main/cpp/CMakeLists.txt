CMAKE_MINIMUM_REQUIRED(VERSION 3.4.1)
project(androidz-breakpad)


# breakpad client
set(BREAKPAD_ROOT external/breakpad)
include_directories(${BREAKPAD_ROOT}/src ${BREAKPAD_ROOT}/src/common/include)
add_subdirectory(external/breakpad-client)
list(APPEND LINK_LIBRARIES breakpad-client)


add_library(
        androidz-breakpad
        SHARED
        ndk.cpp
)

target_link_libraries(
        androidz-breakpad
        ${LINK_LIBRARIES}
        log
)