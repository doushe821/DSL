
cmake_minimum_required (VERSION 3.20)
project (sim CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(EXECUTABLE sim)
add_executable (${EXECUTABLE}
    src/main.cpp
    src/ElfLoader.cpp
    src/RegState.cpp
    src/Memory.cpp
    stc/CPU.cpp
)

target_include_directories (${EXECUTABLE}
    PRIVATE
    include
)

target_link_libraries (${EXECUTABLE}
    PRIVATE
)

target_compile_features (${EXECUTABLE}
    PRIVATE
        cxx_std_20
)

target_compile_options (${EXECUTABLE}
    PRIVATE
        -fdiagnostics-color=always

        -Wall
        -Wextra
        -fstack-protector-strong
        -fcheck-new
        -fstrict-overflow

        -march=native
        $<$<CONFIG:Debug>:
            -Og
            -g3
            -DDEBUG
            -ggdb
            -fsanitize=address,leak,undefined
        >

        $<$<CONFIG:Release>:
            -O2
            -DNDEBUG
        >
)

target_link_options (${EXECUTABLE}
    PRIVATE
        -march=native
        -Wl,-q
        $<$<CONFIG:Debug>:
            -Og
            -g3
            -DDEBUG
            -ggdb
            -fsanitize=address,leak,undefined
        >

        $<$<CONFIG:Release>:
            -O2
        >
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

# cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++
# cmake --build build
