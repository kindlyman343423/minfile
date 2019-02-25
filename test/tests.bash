#!bin/bash

# This file contains all the test run by travis and bash

echo ""
echo "Test CSS 1"
./minfile test.css
echo ""
echo "OUTPUT:"
cat test.min.css

echo ""
mv *.min.* ../mfiles/tested              # move min files to mfiles/test directory for safe keeping

echo ""
echo "============ test css 1 completed ============"
echo ""