cmake_minimum_required(VERSION 3.20)
project(VPD_Lab2 LANGUAGES C CXX)

add_compile_options(-Wall -Wextra -Wpedantic -O0 -std=gnu2x)

file(GLOB SRC_EX04 "ex04/*.c")
add_executable(ex04 ${SRC_EX04})

file(GLOB SRC_EX05 "ex05_and_ex06/*.c")
add_executable(ex05_and_ex06 ${SRC_EX05})

file(GLOB SRC_EX07 "ex07/*.c")
add_executable(ex07 ${SRC_EX07})

file(GLOB SRC_EX09 "ex09/*.c")
add_executable(ex09 ${SRC_EX09})

file(GLOB SRC_EX10 "ex10_and_ex12/*.c")
add_executable(ex10_and_ex12 ${SRC_EX10})

file(GLOB SRC_EX11 "ex11/*.cpp")
add_executable(ex11 ${SRC_EX11})

add_executable(ex13 ex13/main.c ex13/device.c)

file(GLOB SRC_EX14 "ex14/*.c")
add_executable(ex14 ${SRC_EX14})

file(GLOB SRC_EX15 "ex15/*.c")
add_executable(ex15 ${SRC_EX15})