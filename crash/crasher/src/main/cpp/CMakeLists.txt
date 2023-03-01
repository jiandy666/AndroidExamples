CMAKE_MINIMUM_REQUIRED(VERSION 3.4.1)


add_library(
        ndk
        SHARED
        ndk.cpp
)


target_link_libraries(
        ndk
        log
)
