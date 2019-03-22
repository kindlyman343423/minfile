#!bin/bash

# This file contains all the test run by travis and can be run by bash for local testing

echo "====================> Test CSS 1 <===================="
./minfile CSS/test.css
echo -e ""
mv CSS/test.min.css .
cat test.min.css
echo -e "\n------------------------------------------------------\n"

echo "====================> Test SCSS 1 <===================="
./minfile SCSS/test.scss
echo -e ""
mv SCSS/test.min.scss .
cat test.min.scss
echo -e "\n------------------------------------------------------\n"

echo "====================> Test JSON 1 <===================="
./minfile JSON/test.json
echo -e ""
mv JSON/test.min.json .
cat test.min.json
echo -e "\n------------------------------------------------------\n"

echo "====================> Test HTML 1 <===================="
./minfile HTML/test.html
echo -e ""
mv HTML/test.min.html .
cat test.min.html
echo -e "\n------------------------------------------------------\n"

echo "====================> Test JavaScript 1 <===================="
./minfile JS/test.js
echo -e ""
mv JS/test.min.js .
cat test.min.js
echo -e "\n------------------------------------------------------\n"

echo "====================> Test C 1 <===================="
./minfile C/test.c
echo -e ""
mv C/test.min.c .
cat test.min.c
echo -e "\n------------------------------------------------------\n"

echo "====================> Test C++ 1 <===================="
./minfile CPP/test.cpp
echo -e ""
mv CPP/test.min.cpp .
cat test.min.cpp
echo -e "\n------------------------------------------------------\n"

echo "====================> Test JAVA 1 <===================="
./minfile JAVA/test.java
echo -e ""
mv JAVA/test.min.java .
cat test.min.java
echo -e "\n------------------------------------------------------\n"

echo "====================> Test C# 1 <===================="
./minfile CS/test.cs
echo -e ""
mv CS/test.min.cs .
cat test.min.cs
echo -e "\n------------------------------------------------------\n"

mv *.min.* ../mfiles/tested              # move min files to mfiles/test directory for safe keeping