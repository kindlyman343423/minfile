#!bin/bash

# for testing only

echo "building files for testing only"
bash build.bash

cd test

echo "Enter filename for test output"
read filename
./minfile $filename

mv *.min.* ../mfiles