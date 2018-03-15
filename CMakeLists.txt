# Author: Dominik Harmim <harmim6@gmail.com>

CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_C_FLAGS "-std=c11 -Wall -Wextra -Werror -pedantic -g")
SET(CMAKE_EXE_LINKER_FLAGS "-lallegro -lallegro_main -lallegro_primitives") # for lab 8 only

PROJECT(lab)

SET(WORKING_DIR 8/src)
SET(SOURCES "${WORKING_DIR}/spiral.c")

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCES})
