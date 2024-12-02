cmake_minimum_required(VERSION 3.11)

project(info2_lecture)
set(CMAKE_C_STANDARD 17)

add_executable(01_bufferoverflow Termin_01/bufferoverflow.c)

add_executable(02_primzahl Termin_02/primzahl/primzahl.c)
add_executable(02_sortierung
        Termin_02/sortierung/sortierung.c
        Termin_02/sortierung/sortierungsvergleich.c
        Termin_02/sortierung/stoppuhr.c
        Termin_02/sortierung/zufallsarray.c)

add_executable(03_anfangsbuchstabe
        Termin_03/anfangsbuchstabe.c
        Termin_03/eingabe.c)
add_executable(03_eingabe
        Termin_03/eingabe.c
        Termin_03/eingabeTest.c)
add_executable(03_laengen Termin_03/laengen.c)
add_executable(03_fehler Termin_03/fehler.c)

add_executable(04_stringaddierer Termin_04/stringaddierer.c Termin_03/eingabe.c)
target_include_directories(04_stringaddierer PRIVATE ./Termin_03)
add_executable(04_stringtausch Termin_04/stringtausch.c)

add_executable(05_stringsortierung Termin_05/stringsortierung.c)
add_executable(05_const Termin_05/const.c)
add_executable(05_callbacks Termin_05/callbacks.c)

add_executable(06_namesarchive
        Termin_06/namesarchive.c
        Termin_06/main.c)

add_executable(07_namesarchive_dynamic
        Termin_07/namesarchive.c
        Termin_07/main.c)

add_executable(08_namesarchive_structs
        Termin_08/namesarchive.c
        Termin_08/main.c)
add_executable(08_callbyreference
        Termin_08/callByReference.c)

add_executable(09_namesarchive_lists
        Termin_09/namesarchive.c
        Termin_09/stringlist.c
        Termin_09/main.c)

add_executable(10_namesarchive_bst Termin_10/main.c
        Termin_10/namesarchive.c
        Termin_10/stringbst.c)

add_executable(11_bmp
        Termin_11/bmp/bmp.c
        Termin_11/bmp/main.c)
file(COPY ${CMAKE_CURRENT_LIST_DIR}/Termin_11/bmp/test.bmp
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(11_namesarchive_files
        Termin_11/namesarchive/main.c
        Termin_11/namesarchive/namesarchive.c
        Termin_10/stringbst.c)
file(COPY ${CMAKE_CURRENT_LIST_DIR}/Termin_11/namesarchive/names.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(12_santa Termin_12/main.c
        Termin_12/bst.c)

add_executable(99_test test.c)