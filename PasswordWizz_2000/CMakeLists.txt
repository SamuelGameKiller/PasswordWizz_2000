cmake_minimum_required(VERSION 3.13)
project(PasswordWizz_2000 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pedantic -std=c11") #-Werror dat prec to su warningy

add_executable(PasswordWizz_2000 main.c PasswordWizz.c PasswordWizz.h Input.c Menus.c Generator.c Strength_tester.c Password_Search.c)