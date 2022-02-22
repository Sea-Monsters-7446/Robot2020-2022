#As of right now VS Code for WPILib cannot be installed via the command line so for now it has to be manually installed

#Install VSCode BuildTools
Write-Host "Installing VSCode BuildTools"
winget install Microsoft.VisualStudio.2022.BuildTools

#Install Git
Write-Host "Installing Git"
winget install Git.Git

#Install GitHub Desktop
Write-Host "Installing GitHub Desktop"
winget install GitHub.GitHubDesktop

#Install VSCode
Write-Host "Installing VSCode"
winget install Microsoft.VisualStudioCode

#Install OpenJDK
Write-Host "Installing OpenJDK"
winget install EclipseAdoptium.Temurin.17

#Install VSCode Extensions
Write-Host "Installing VSCode Extensions"
code --install-extension ms-vscode.cpptools --install-extension wpilibsuite.vscode-wpilib --install-extension vscjava.vscode-java-pack