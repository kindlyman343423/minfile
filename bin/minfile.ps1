# for script lovers

Set-Location ..                           # navigate to root directory

"building files..."
pwsh build.ps1                 # build script

Set-Location bin                          # back to bin for running


$filename = Read-Host "Enter valid filename"                   # get filename from user
./minfile $filename

"Min files are auto-generated in mfiles directory"
Move-Item *.min.* ../mfiles            # move min files to mfiles directory for safe keeping