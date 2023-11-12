#!/usr/bin/env bash

function lineBreak {
  HEADER_WIDTH=80
  HEADER_CHAR="="
  printf "%${HEADER_WIDTH}s\n" " " | tr " " "${HEADER_CHAR}"
}

function header {
    echo
    lineBreak
    echo "$1"
    lineBreak
}

# Default Variables
export CXX=/usr/bin/clang
export CXX=/usr/bin/clang++
SRC_DIRS=("./include" "./src" "./tests")
BUILD_DIRS=("./build")
TESTS_ENABLED=false
VALGRIND_ENABLED=false
GCC_ENABLED=false

# Argument Parsing

while [ -n "$1" ]
do
  case "${1}" in
  --test)
    TESTS_ENABLED=true
    ;;
  --valgrind)
    VALGRIND_ENABLED=true
    ;;
  --gcc)
    GCC_COMPILER=true
    export CXX=/usr/bin/gcc
    export CXX=/usr/bin/g++
    ;;
  *)
    echo "Invalid option: -${1}."
    exit 1
    ;;
  esac
  shift
done

echo
echo "Source Directories: ${SRC_DIRS[*]}"
echo "Build Directory: ${BUILD_DIRS[*]}"
echo "C++ compiler ${CXX}"
echo "Tests Enabled: ${TESTS_ENABLED}"
echo "Valgrind Enabled: ${VALGRIND_ENABLED}"
echo "GCC Enabled: ${GCC_ENABLED}"

# Building

header "CMake"

cmake .

header "Make"

make

# Testing

if [ "${TESTS_ENABLED}" = true ]
then
  header "Tests"

  TEST_EXE="./tests/test"

  ${TEST_EXE}

  if [ "${VALGRIND_ENABLED}" = true ]
  then
    header "Valgrind"

    valgrind --leak-check=full "${TEST_EXE}"
  fi
fi
# Clean up CMake files after?