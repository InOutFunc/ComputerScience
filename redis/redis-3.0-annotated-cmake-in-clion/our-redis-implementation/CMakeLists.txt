cmake_minimum_required(VERSION 3.14)
project(helloworld C)

set(CMAKE_C_STANDARD 99)

add_executable(helloworld
#        main.c
        my_sds.c
        my_sds.h
        my_anet.h
        my_anet.c
        ../src/zmalloc.c
        ../src/setproctitle.c)