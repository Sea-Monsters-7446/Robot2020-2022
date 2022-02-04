# As of right now I do not know if VS Code for WPILib can be installed silently (Via the command line so for now you have to manually install it
cd %USERPROFILE%
cd Downloads
wget https://aka.ms/vs/17/release/vs_BuildTools.exe
vs_BuildTools.exe -ArgumentList ' --add Microsoft.VisualStudio.Product.BuildTools --includeOptional --includeRecommended --quiet --nocache --wait'
wget https://github.com/git-for-windows/git/releases/download/v2.35.1.windows.2/Git-2.35.1.2-64-bit.exe
Git-2.35.1.2-64-bit.exe /VERYSILENT /NORESTART
