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

# ARG=$(ruby -e "puts (-2147483648..-2147483149).to_a.shuffle.join(' ')");
# echo $ARG
# ./push_swap $ARG

ARG=$(ruby -e "puts (-250..249).to_a.shuffle.join(' ')");
./push_swap $ARG | ./checker_Mac $ARG
echo $ARG
# if [ $S == "OK" ]; then
# 	printf "${GREEN}$cont .[OK]${DEF_COLOR}";
# 	control=2
# else
# 	printf "${RED}$cont .[KO]${DEF_COLOR}";
# 	control=3
# fi