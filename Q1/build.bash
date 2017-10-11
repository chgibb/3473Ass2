#!/bin/bash
(set -o igncr) 2>/dev/null && set -o igncr; # For Cygwin on Windows compatibility

for f in *.cpp
do
    g++ -c $f -Werror -Wfatal-errors
done
g++ -o q1 $(find . -type f -iname *.o -print)