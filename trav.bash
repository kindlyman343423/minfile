#!bin/bash

echo "building..."

cd src                                          # navigate to source directory
gcc Main.c -o minfile                           # produce the main output file minfile

echo "Build completed"