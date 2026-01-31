cmake_minimum_required (VERSION 3.20)
project (sim CXX)

# -----------------------------
# General settings
# -----------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# -----------------------------
# Compiler options
# -----------------------------
set(COMMON_COMPILE_OPTIONS
    -fdiagnostics-color=always
    -Wall
    -Wextra
    -fstack-protector-strong
    -fcheck-new
    -fstrict-overflow
    -march=native
)

set(DEBUG_COMPILE_OPTIONS
    -Og
    -g3
    -DDEBUG
    -ggdb
    -fsanitize=address,leak,undefined
)

set(RELEASE_COMPILE_OPTIONS
    -O2
    -DNDEBUG
)

# -----------------------------
# Simulator executable
# -----------------------------

# asmjit setting

option(ASMJIT_STATIC "Build asmjit as static library" ON)
option(ASMJIT_EMBED "Embed asmjit into project" ON)

set(ASMJIT_STATIC ON CACHE BOOL "" FORCE)
set(ASMJIT_NO_LOGGING OFF CACHE BOOL "" FORCE)
set(ASMJIT_BUILD_X86 ON CACHE BOOL "" FORCE)
set(ASMJIT_BUILD_ARM OFF CACHE BOOL "" FORCE)

add_subdirectory(external/asmjit)



add_executable(sim
    src/main.cpp
    src/ElfLoader.cpp
    src/RegState.cpp
    src/Memory.cpp
    src/CPU.cpp
    src/Executor.cpp
    src/JIT.cpp
    src/Decoder.cpp
    src/JITExecutor.cpp
)

target_include_directories(sim
    PRIVATE include
)

target_compile_options(sim
    PRIVATE
        ${COMMON_COMPILE_OPTIONS}
        $<$<CONFIG:Debug>:${DEBUG_COMPILE_OPTIONS}>
        $<$<CONFIG:Release>:${RELEASE_COMPILE_OPTIONS}>
)

target_link_options(sim
    PRIVATE
        -march=native
        $<$<CONFIG:Debug>:${DEBUG_COMPILE_OPTIONS}>
        $<$<CONFIG:Release>:${RELEASE_COMPILE_OPTIONS}>
)

target_link_libraries(sim
    PRIVATE
        asmjit
)


# -----------------------------
# Catch2 test executable
# -----------------------------
find_package(Catch2 3 REQUIRED)

add_executable(sim_tests
    src/Tests.cpp
    src/CPU.cpp
    src/Memory.cpp
    src/Executor.cpp
    src/Decoder.cpp
    src/RegState.cpp
    src/ElfLoader.cpp
    src/JIT.cpp
    src/JITExecutor.cpp
)

target_include_directories(sim_tests
    PRIVATE include
)

target_link_libraries(sim_tests
    PRIVATE Catch2::Catch2WithMain
    asmjit
)

target_compile_options(sim_tests
    PRIVATE
        ${COMMON_COMPILE_OPTIONS}
        $<$<CONFIG:Debug>:${DEBUG_COMPILE_OPTIONS}>
        $<$<CONFIG:Release>:${RELEASE_COMPILE_OPTIONS}>
)

target_link_options(sim_tests
    PRIVATE
        -march=native
        $<$<CONFIG:Debug>:${DEBUG_COMPILE_OPTIONS}>
        $<$<CONFIG:Release>:${RELEASE_COMPILE_OPTIONS}>
)

# -----------------------------
# Enable testing
# -----------------------------
enable_testing()
add_test(NAME sim_unit_tests COMMAND sim_tests)

# cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++
# cmake --build build
