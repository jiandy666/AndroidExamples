cmake_minimum_required(VERSION 3.10.2)


add_library(
        native-lib      # The name of the library
        SHARED          # This is a shared library
        # Provides a relative path to your source file(s).
        native-lib.cpp
        MyService.cpp
        # :Binder.Common
        ${aidl_src_dir}/com/example/binder/IMyService.cpp
)


# Includes
target_include_directories(
        native-lib
        PRIVATE
        ${common_inc_dir}
        includes
)


find_library(
        log-lib
        log
)

# minSdk 29
find_library(
        binder_ndk-lib
        binder_ndk
)


target_link_libraries(
        native-lib
        # Link libraries
        ${log-lib}
        ${binder_ndk-lib}
)
