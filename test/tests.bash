#!bin/bash

# This file contains all the test run by travis and bash

echo ""
echo "Test CSS 1"
./minfile test.css

echo ""
echo "Test HTML 1"
./minfile test.html

echo "==================== Test CSS 1 OUTPUT ===================="
cat test.min.css

echo "==================== Test HTML 1 OUTPUT ===================="
cat test.min.html

echo ""
mv *.min.* ../mfiles/tested              # move min files to mfiles/test directory for safe keeping