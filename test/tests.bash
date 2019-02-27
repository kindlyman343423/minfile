#!bin/bash

# This file contains all the test run by travis and bash

echo "====================> Test CSS 1 <===================="
./minfile test.css
echo -e ""
cat test.min.css
echo -e "\n------------------------------------------------------\n"

echo "====================> Test SCSS 1 <===================="
./minfile test.scss
echo -e ""
cat test.min.scss
echo -e "\n------------------------------------------------------\n"

echo "====================> Test JSON 1 <===================="
./minfile test.json
echo -e ""
cat test.min.json
echo -e "\n------------------------------------------------------\n"

echo "====================> Test HTML 1 <===================="
./minfile test.html
echo -e ""
cat test.min.html
echo -e "\n------------------------------------------------------\n"


mv *.min.* ../mfiles/tested              # move min files to mfiles/test directory for safe keeping