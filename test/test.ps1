# for testing only
"Testing new build..."

$opt = Read-Host "Do you want to synchronize new build(Y/N)"

if(($opt -eq 'Y') -OR ($opt -eq 'y'))
{
    Set-Location ..                                         # navigate to root directory
    pwsh build.ps1                                          # build script
    Set-Location test                                       # navigate back to test folder for testing
}

$filename = Read-Host "Enter filename for test output"      # getting filename from user
./minfile $filename                                         # executing the file

Move-Item */*.min.* .

"Min files are auto-generated in mfiles/test directory"
Copy-Item *.min.* ../mfiles/tested                          # move min files to mfiles/test directory for safe keeping

Remove-Item *.min.*