cmake_minimum_required(VERSION 3.16)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY") # workaround for compiler sanity check

project(devkitpro_test_gba)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_LIBGBA}/include ${PROJECT_DIR}/include)
add_custom_target(build COMMAND
        ${BASH}
        ${devkitpro_test_gba_SOURCE_DIR}/build.sh
        ${devkitpro_test_gba_SOURCE_DIR}
        ${CMAKE_PROJECT_NAME}
)

add_custom_target(clear COMMAND
        ${BASH}
        ${devkitpro_test_gba_SOURCE_DIR}/clean.sh
        ${devkitpro_test_gba_SOURCE_DIR}
)
add_custom_target(cook-assets COMMAND
        ${BASH}
        ${devkitpro_test_gba_SOURCE_DIR}/cook-assets.sh
        ${devkitpro_test_gba_SOURCE_DIR}
)

add_custom_target(run COMMAND ${MGBA} ${devkitpro_test_gba_SOURCE_DIR}/${CMAKE_PROJECT_NAME}.gba)


add_executable(x_do_not_run src/main.c)
target_include_directories(x_do_not_run PUBLIC ${PROJECT_SOURCE_DIR}/include)
