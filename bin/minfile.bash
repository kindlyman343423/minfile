#!bin/bash

# for scripters

cd ..                   # navigate to root directory

echo "building files..."
bash build.bash         # build script

cd bin                  # back to bin

echo "Enter valid filename"
read filename

echo "running files"
./minfile $filename

mv *.min.* ../mfiles    # move min files to mfiles directory