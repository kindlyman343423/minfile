#!bin/bash

echo "***** Building *****"

cd src                                          # navigate to source directory
gcc Main.c -o minfile                           # produce the main output file minfile
mv minfile ../test                              # move new binary to test directory

echo -e "***** Build completed *****\n"

echo -e "***** Testing *****\n"

cd ..
cd test
bash tests.bash

echo "****** Test completed *****"