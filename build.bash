#!bin/bash

cd src
gcc Main.c -o minfile

cp minfile ../bin
cp minfile ../test

rm minfile