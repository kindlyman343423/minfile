# It will build source files and move to bin and test folder

"building..."

Set-Location src                                          # navigate to source directory
gcc Main.c -o minfile                           # produce the main output file minfile

Copy-Item minfile ../test                              # move minfile to test
"Test new build by running test.bash in test directory"
  
$ans = Read-Host "Do you want to release the code (Y/N)" 

if(($ans -eq 'Y') -OR ($ans -eq 'y'))
{
    Copy-Item minfile ../bin                               # move minfile to bin
    "Code released..."
}
Remove-Item minfile