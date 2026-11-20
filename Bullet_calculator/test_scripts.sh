#!/bin/bash

set -e

echo compiling all

MODE=${1:-"all"}

FILES=(
    # *.cpp
    
    Bullet.cpp
    Environment.cpp
    Target.cpp
    Task_param.cpp
    
    Calculator.cpp
    Interface.cpp
    
    Runge_kutta.cpp
    Utils.cpp
    
    main_interface.cpp
)


if [ "$MODE" == "all" ]; then
    echo "Compiling all ${FILES[@]}\n"
    g++ ${FILES[@]} -o test_compiling.out
    echo "All compiling complite\n"
    
    elif [ "$MODE" == "test_output" ]; then
    echo "Test output compiling start\n"
    g++ -g -Wall "${FILES[@]}" -o test_output.out
    echo "Test output compiling complite\n"
    ./test_output.out
    
    elif [ "$MODE" == "clean_all" ]; then
    echo "Очистка всех .out файлов"
    rm -f *.out

    elif [ "$MODE" == "surprise" ]; then
    echo "Думайте"
    pkill -TERM code && exit
    
else
    echo "No such script"
fi