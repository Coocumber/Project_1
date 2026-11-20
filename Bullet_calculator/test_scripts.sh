#!/bin/bash

set -e

echo compiling all

g++ \
*.cpp \
-o test_compiling.out

echo -e "compiling complete\n"