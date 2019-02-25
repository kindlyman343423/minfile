#!bin/bash

echo "Building..."

cd src                                          # navigate to source directory
gcc Main.c -o minfile                           # produce the main output file minfile
cp minfile ../test                              # copy new binary to test directory

echo "Build completed"

echo "Testing..."

cd ..
cd test
bash tests.bash

echo "Test completed"