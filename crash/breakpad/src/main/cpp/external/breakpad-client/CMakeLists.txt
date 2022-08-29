CMAKE_MINIMUM_REQUIRED(VERSION 3.4.1)


set(EXT_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../breakpad)

include_directories(
        ${ROOT}/src
        ${ROOT}/src/common/android/include
        ${EXT_INCLUDE}
)


# c source files
file(GLOB SRC_C
        ${ROOT}/src/client/linux/crash_generation/crash_generation_client.cc
        ${ROOT}/src/client/linux/dump_writer_common/thread_info.cc
        ${ROOT}/src/client/linux/dump_writer_common/ucontext_reader.cc
        ${ROOT}/src/client/linux/handler/exception_handler.cc
        ${ROOT}/src/client/linux/handler/minidump_descriptor.cc
        ${ROOT}/src/client/linux/log/log.cc
        ${ROOT}/src/client/linux/microdump_writer/microdump_writer.cc
        ${ROOT}/src/client/linux/minidump_writer/linux_dumper.cc
        ${ROOT}/src/client/linux/minidump_writer/linux_ptrace_dumper.cc
        ${ROOT}/src/client/linux/minidump_writer/minidump_writer.cc
        ${ROOT}/src/client/minidump_file_writer.cc
        ${ROOT}/src/common/convert_UTF.cc
        ${ROOT}/src/common/md5.cc
        ${ROOT}/src/common/string_conversion.cc
        ${ROOT}/src/common/linux/elfutils.cc
        ${ROOT}/src/common/linux/file_id.cc
        ${ROOT}/src/common/linux/guid_creator.cc
        ${ROOT}/src/common/linux/linux_libc_support.cc
        ${ROOT}/src/common/linux/memory_mapped_file.cc
        ${ROOT}/src/common/linux/safe_readlink.cc
        )


# asm source files
file(GLOB SRC_ASM
        ${ROOT}/src/common/linux/breakpad_getcontext.S
        )
set_source_files_properties(${SRC_ASM} PROPERTIES LANGUAGE C)


add_library(
        breakpad-client
        STATIC
        ${SRC_C}
        ${SRC_ASM}
        )

target_link_libraries(
        breakpad-client
        log)
