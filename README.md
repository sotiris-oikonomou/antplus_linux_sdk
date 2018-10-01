# antplus_linux_sdk
The Official ANT Linux SDK (From https://www.thisisant.com) with some modifications so it compiles succesfully in linux.

I have removed the libusb and libudev included libraries and the compilation only depends on those existing in the linux system being compiled on to. I have also removed all references to MacOS as this is the linux SDK and a separate SDK for MacOS exists.

The following libraries are needed: `libusb-1.0`
Debian: `libusb-1.0-0-dev`

The compilation needs to be made in 3 steps.
1. `make ANT_LIB` First the ANT_LIB low level ANT static library needs to be compiled
2. `make` Then the higher level shared library (ANT_DLL)
3. `make install` Installation
