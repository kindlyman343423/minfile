#!bin/bash

# It will build source files and move to bin and test folder

echo "building..."

cd src                                          # navigate to source directory
gcc Main.c -o minfile                           # produce the main output file minfile

cp minfile ../test                              # move minfile to test
echo "Test new build by running test.bash in test directory"

echo "Do you want to release the code (Y/N)";   
read ans

if [[ $ans == 'Y' ]] || [[ $ans == 'y' ]];then
cp minfile ../bin                               # move minfile to bin
echo "Code released..."
fi

rm minfile