echo As of right now I do not know if VS Code for WPILib can be installed silently (Via the command line so for now you have to manually install it
cd ../Downloads
curl https://aka.ms/vs/17/release/vs_BuildTools.exe -o vs_BuildTools.exe -L
vs_BuildTools.exe --add Microsoft.VisualStudio.Product.BuildTools Microsoft.VisualStudio.Product.Community Microsoft.Component.MSBuild Microsoft.VisualStudio.Component.CoreBuildTools Microsoft.VisualStudio.Component.Roslyn.Compiler Microsoft.VisualStudio.Component.Windows10SDK.19041 --includeOptional --includeRecommended --quiet --nocache --wait
del vs_BuildTools.exe
curl https://github.com/git-for-windows/git/releases/download/v2.35.1.windows.2/Git-2.35.1.2-64-bit.exe -o GitInstall.exe -L
GitInstall.exe /VERYSILENT /NORESTART
del GitInstall.exe
curl "https://code.visualstudio.com/sha/download?build=stable&os=win32-x64-user" -o VSCode-Setup.exe -L
VSCode-Setup.exe /VERYSILENT /NORESTART /MERGETASKS=!runcode
del VSCode-Setup.exe
curl https://download.oracle.com/java/17/latest/jdk-17_windows-x64_bin.exe -o JavaLatest.exe -L
JavaLatest.exe INSTALL_SILENT=1
del JavaLatest.msi
code --install-extension ms-vscode.cpptools --install-extension wpilibsuite.vscode-wpilib
code