#!/bin/sh

if [ "$1" = "1" ]; then
    ./push_swap
fi

if [ "$1" = "2" ]; then
    ./push_swap 42
fi

if [ "$1" = "3" ]; then
    ./push_swap 1 2
fi

if [ "$1" = "4" ]; then
    ./push_swap 1 2 3 4
fi

if [ "$1" = "5" ]; then
    ./push_swap 1 2 3 4 5 a
fi

if [ "$1" = "6" ]; then
    ./push_swap 1 2 3 4 5 111111111111111111
fi

if [ "$1" = "7" ]; then
    ./push_swap 1 2 3 4 5 -1111111111111111111111
fi

if [ "$1" = "8" ]; then
    ./push_swap 5 4 3 2 1
fi

if [ "$1" = "9" ]; then
    ./push_swap "-2147483648 -2147483647 -2147483646"
fi

ARG=""
./push_swap ""
leaks -atExit -- ./push_swap $ARG > /dev/null && echo $?

# ARG=$(ruby -e "puts (-50000..-49510).to_a.shuffle.join(' ')");
# ./push_swap $ARG | ./checker_linux $ARG
# ./push_swap $ARG
# echo $ARG


# val=101

# cont=1
# while [ $cont -lt $val ]
# do
# ARG=$(ruby -e "puts (00..499).to_a.shuffle.join(' ')");
# printf "$cont: ";
# ./push_swap $ARG | ./checker_linux $ARG
# ((cont++))
# done
