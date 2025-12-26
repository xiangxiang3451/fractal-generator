cmake_minimum_required(VERSION 3.16)
project(FractalProject C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# 开启 Release 和 Debug 配置
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type: Debug or Release")

# ---- 源文件 ----
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

# ---- 可执行文件 ----
add_executable(fractal ${SRC_FILES})
add_executable(fractal_test ${TEST_SRC_FILES})

# ---- 编译选项 ----
# 根据不同编译器设置警告和优化
if (MSVC)
    # MSVC 编译器
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

# ---- 包含目录 ----
target_include_directories(fractal PRIVATE src)
target_include_directories(fractal_test PRIVATE src YY.utest)

# ---- 测试 ----
enable_testing()
add_test(NAME FractalTest COMMAND fractal_test)
