#!bin/bash

# for testing only
echo "Testing new build..."

echo "Do you want to synchronize new build(Y/N)"
read opt

if [[ $opt == 'Y' ]] || [[ $opt == 'y' ]];then
cd ..                                   # navigate to root directory
bash build.bash                         # build script
cd test                                 # navigate back to test folder for testing
fi

echo "Enter filename for test output"
read filename                           # getting filename from user
./minfile $filename                     # executing the file

echo "Min files are auto-generated in mfiles/test directory"
mv *.min.* ../mfiles/test              # move min files to mfiles/test directory for safe keeping