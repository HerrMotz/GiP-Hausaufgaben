cmake_minimum_required(VERSION 3.13)
project(HA_GIP C)

set(CMAKE_C_STANDARD 99)

add_executable(03_temperatur 3/temperatur.c)
add_executable(03_fragebogen 3/fragebogen.c)
add_executable(03_quader 3/quader.c)
add_executable(04_strassenbahn 4/strassenbahn.c)
add_executable(04_bool 4/bool.c)
add_executable(05_froehliche_zahlen 5/froehliche_zahlen.c)
add_executable(05_berechnung_pi 5/berechnung_pi.c)
add_executable(05_primfaktor 5/primfaktor.c)
add_executable(06_trainingsdaten 6/trainingsdaten.c)

add_executable(06_zinseszinstabelle 6/zinseszinstabelle.c)
target_link_libraries(06_zinseszinstabelle PRIVATE m)

add_executable(06_flaecheninhalt_dreieck 6/flaecheninhalt_dreieck.c)
target_link_libraries(06_flaecheninhalt_dreieck PRIVATE m)

add_executable(07_binary_decimal 7/binary_decimal.c)
target_link_libraries(07_binary_decimal PRIVATE m)

add_executable(07_quadratic_equation 7/quadratic_equation.c)
target_link_libraries(07_quadratic_equation PRIVATE m)

add_executable(07_delta_aristotle 7/delta_aristotle.c)
target_link_libraries(07_delta_aristotle PRIVATE m)

add_executable(81_search_algorithms 8/81_search_algorithms.c)
target_link_libraries(81_search_algorithms PRIVATE m)

add_executable(82_magic_square 8/82_magic_square.c)
target_link_libraries(82_magic_square PRIVATE m)

add_executable(91 9/91.c)

add_executable(92 9/92.c)

add_executable(10_1 10/10_1.c)

add_executable(10_2 10/10_2.c)

add_executable(ilias_02_1 ilias/HA_ilias_02_1.c)
target_link_libraries(ilias_02_1 PRIVATE m)

add_executable(shutdown shutdown.c)
add_executable(test test.c)