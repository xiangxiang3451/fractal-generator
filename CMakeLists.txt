cmake_minimum_required(VERSION 3.16)
project(FractalProject C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Enable Release and Debug configurations
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type: Debug or Release")

# ---- Source files ----
set(SRC_FILES
    src/main.c
    src/image.c
    src/fractal.c
)

set(TEST_SRC_FILES
    src/test_main.c
    src/image.c
    src/fractal.c
)

# ---- Executables ----
add_executable(fractal ${SRC_FILES})
add_executable(fractal_test ${TEST_SRC_FILES})

# ---- Compile options ----
if (MSVC)
    # MSVC compiler
    target_compile_options(fractal PRIVATE
        $<$<CONFIG:Release>:/O2 /DNDEBUG /W4>
        $<$<CONFIG:Debug>:/Zi /DDEBUG /W3>
    )

    target_compile_options(fractal_test PRIVATE
        $<$<CONFIG:Release>:/O2 /DNDEBUG /W4>
        $<$<CONFIG:Debug>:/Zi /DDEBUG /W3>
    )
else()
    # GCC / Clang
    target_compile_options(fractal PRIVATE
        $<$<CONFIG:Release>:-O3 -DNDEBUG -Wall -Wextra>
        $<$<CONFIG:Debug>:-g -DDEBUG -Wall -Wextra>
    )

    target_compile_options(fractal_test PRIVATE
        $<$<CONFIG:Release>:-O3 -DNDEBUG -Wall -Wextra>
        $<$<CONFIG:Debug>:-g -DDEBUG -Wall -Wextra>
    )
endif()

# ---- Include directories ----
target_include_directories(fractal PRIVATE src)
target_include_directories(fractal_test PRIVATE src YY.utest)

# ---- Testing ----
enable_testing()
add_test(NAME FractalTest COMMAND fractal_test)
