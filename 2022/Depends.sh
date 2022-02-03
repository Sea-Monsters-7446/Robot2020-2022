# This is to setup the tools for programming

sudo apt-get update
sudo apt-get install git build-essential openjdk-11-jdk libc6-armel-cross binutils gcc-arm-linux-gnueabi g++-arm-linux-gnueabi

# This installs:
# git - For interacting with the repo
# build-essential - To build wpilibs
# openjdk-11-jdk - Same as above

# libc6-armel-cross - C library for cross compilation
# binutils - For linking libraries
# gcc-arm-linux-gnueabi - For compiling to the target CPU
# g++-arm-linux-gnueabi - Same as above

# The compiler might also be found here:
# frc/2022/roborio/bin/arm-frc2022-linux-gnueabi-gcc
