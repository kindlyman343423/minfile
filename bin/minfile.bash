#!bin/bash

# for script lovers

cd ..                           # navigate to root directory

echo "building files..."
bash build.bash                 # build script

cd bin                          # back to bin for running

echo "Enter valid filename"
read filename                   # get filename from user
./minfile $filename

echo "Min files are auto-generated in mfiles directory"
mv *.min.* ../mfiles            # move min files to mfiles directory for safe keeping