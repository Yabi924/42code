#!/bin/sh

if [ "$1" = "1" ]; then
    ./push_swap 1
fi

if [ "$1" = "2" ]; then
    ./push_swap 0 1
fi

if [ "$1" = "2.1" ]; then
    ./push_swap 1 0
fi

if [ "$1" = "3" ]; then
    ./push_swap "15 70 10"
fi

if [ "$1" = "4" ]; then
    ./push_swap 15 70 10
fi

#three
if [ "$1" = "3.1" ]; then
    ./push_swap 0 2 1
fi

if [ "$1" = "3.2" ]; then
    ./push_swap 2 0 1
fi

if [ "$1" = "3.3" ]; then
    ./push_swap 2 1 0
fi

if [ "$1" = "3.4" ]; then
    ./push_swap 1 0 2
fi

if [ "$1" = "3.5" ]; then
    ./push_swap 1 2 0
fi
