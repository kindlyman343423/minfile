#!bin/bash

# for testing only

cd ..                                   # navigate to root directory

echo "building files for testing only"
bash build.bash                         # build script

cd test                                 # navigate to test folder for testing

echo "Enter filename for test output"
read filename                           # getting filename from user
./minfile $filename                     # executing the file

echo "Min files are auto-generated in mfiles directory"
mv *.min.* ../mfiles                    # move min files to mfiles directory for safe keeping