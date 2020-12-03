cmake_minimum_required(VERSION 3.17)
project(HA_GIP C)

set(CMAKE_C_STANDARD 99)

add_executable(HA_GIP_03_temperatur temperatur.c)
add_executable(HA_GIP_03_fragebogen fragebogen.c)
add_executable(HA_GIP_03_quader quader.c)