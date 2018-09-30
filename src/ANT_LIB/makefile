BUILD_OS=none
# OS Specification Code (either auto detected or manually specified with the OS variable on command line
# OSX will default to libusb if FRAMEWORK_TYPE is not specified.
ifeq ($(OS), osx)
    $(info OSX Specified)
    BUILD_OS = osx
else ifeq ($(OS), linux)
    $(info Linux Specified)
    BUILD_OS = linux
else 
    ifeq ($(OS),Windows_NT)
        $(info Please use the Visual Studio Project for Windows)
    else
        UNAME_S := $(shell uname -s)
        ifeq ($(UNAME_S),Darwin)
            $(info OSX Detected)
            BUILD_OS = osx
        else ifeq ($(UNAME_S),Linux)
            $(info Linux Detected)
            BUILD_OS = linux
        else
            $(info Linux Assumed)
            BUILD_OS = linux
        endif
    endif
endif


ifeq ($(BUILD_OS), linux)
    LINUX_DEBUG_OUTPUT_LIST=gccDebug/libraries/dsi_libusb_library_linux.o gccDebug/software/serial/dsi_serial_libusb_linux.o gccDebug/software/USB/device_handles/usb_device_handle_libusb_linux.o gccDebug/software/USB/device_handles/usb_device_handle_linux.o gccDebug/software/USB/devices/usb_device_libusb_linux.o 
    
    LINUX_RELEASE_OUTPUT_LIST=gccRelease/libraries/dsi_libusb_library_linux.o gccRelease/software/serial/dsi_serial_libusb_linux.o gccRelease/software/USB/device_handles/usb_device_handle_libusb_linux.o gccRelease/software/USB/device_handles/usb_device_handle_linux.o gccRelease/software/USB/devices/usb_device_libusb_linux.o 
    
else ifeq ($(BUILD_OS), osx)
    OSX_DEBUG_GENERAL_OUTPUT_LIST=gccDebug/libraries/dsi_libusb_library_mac.o gccDebug/software/serial/dsi_vcp_si.o gccDebug/software/USB/devices/usb_device_vcp.o gccDebug/software/USB/device_handles/usb_device_handle_vcp.o gccDebug/software/USB/device_handles/usb_device_handle_mac.o gccDebug/software/serial/dsi_serial_iokit.o gccDebug/software/USB/iokit_driver/iokit_device.o  gccDebug/software/USB/iokit_driver/iokit_device_handle.o gccDebug/software/USB/iokit_driver/iokit_device_list.o gccDebug/software/USB/iokit_driver/iokit_interface.o gccDebug/software/USB/iokit_driver/iokit_transfer.o gccDebug/software/USB/devices/usb_device_iokit.o gccDebug/software/USB/device_handles/usb_device_handle_si_iokit.o gccDebug/software/USB/device_handles/usb_device_handle_iokit.o 
    
    OSX_RELEASE_GENERAL_OUTPUT_LIST=gccRelease/libraries/dsi_libusb_library_mac.o gccRelease/software/serial/dsi_vcp_si.o gccRelease/software/USB/devices/usb_device_vcp.o gccRelease/software/USB/device_handles/usb_device_handle_vcp.o gccRelease/software/USB/device_handles/usb_device_handle_mac.o gccRelease/software/serial/dsi_serial_iokit.o gccRelease/software/USB/iokit_driver/iokit_device.o  gccRelease/software/USB/iokit_driver/iokit_device_handle.o gccRelease/software/USB/iokit_driver/iokit_device_list.o gccRelease/software/USB/iokit_driver/iokit_interface.o gccRelease/software/USB/iokit_driver/iokit_transfer.o gccRelease/software/USB/devices/usb_device_iokit.o gccRelease/software/USB/device_handles/usb_device_handle_si_iokit.o gccRelease/software/USB/device_handles/usb_device_handle_iokit.o 
    
    ifeq ($(FRAMEWORK_TYPE), iokit)
        $(info using IOkit)
        OSX_DEBUG_OUTPUT_LIST = $(OSX_DEBUG_GENERAL_OUTPUT_LIST)  
        
        OSX_RELEASE_OUTPUT_LIST = $(OSX_RELEASE_GENERAL_OUTPUT_LIST)  
        
    else ifeq ($(FRAMEWORK_TYPE), libusb)
        $(info using libusb)
        OSX_DEBUG_OUTPUT_LIST = $(OSX_DEBUG_GENERAL_OUTPUT_LIST) $(LINUX_DEBUG_OUTPUT_LIST) gccDebug/software/USB/devices/usb_device_libusb_mac.o  gccDebug/software/serial/dsi_serial_libusb_mac.o gccDebug/software/USB/device_handles/usb_device_handle_libusb_mac.o
        
        OSX_RELEASE_OUTPUT_LIST = $(OSX_RELEASE_GENERAL_OUTPUT_LIST) $(LINUX_RELEASE_OUTPUT_LIST) gccRelease/software/USB/devices/usb_device_libusb_mac.o gccRelease/software/serial/dsi_serial_libusb_mac.o gccRelease/software/USB/device_handles/usb_device_handle_libusb_mac.o
        
        LIBUSB_PREPROCESSOR=-D LIBUSB_DRIVER
    else
        $(info using libusb)
        OSX_DEBUG_OUTPUT_LIST = $(OSX_DEBUG_GENERAL_OUTPUT_LIST) $(LINUX_DEBUG_OUTPUT_LIST) gccDebug/software/USB/devices/usb_device_libusb_mac.o  gccDebug/software/serial/dsi_serial_libusb_mac.o gccDebug/software/USB/device_handles/usb_device_handle_libusb_mac.o
        
        OSX_RELEASE_OUTPUT_LIST = $(OSX_RELEASE_GENERAL_OUTPUT_LIST) $(LINUX_RELEASE_OUTPUT_LIST)  gccRelease/software/USB/devices/usb_device_libusb_mac.o gccRelease/software/serial/dsi_serial_libusb_mac.o gccRelease/software/USB/device_handles/usb_device_handle_libusb_mac.o
        FRAMEWORK_TYPE=libusb
        LIBUSB_PREPROCESSOR=-D LIBUSB_DRIVER
    endif
endif

GENERAL_DEBUG_OUTPUT_LIST=gccDebug/software/ANTFS/antfs_client_channel.o gccDebug/software/ANTFS/antfs_directory.o gccDebug/software/ANTFS/antfs_host.o gccDebug/software/ANTFS/antfs_host_channel.o gccDebug/common/checksum.o gccDebug/common/crc.o gccDebug/software/serial/device_management/dsi_ant_device.o gccDebug/software/system/dsi_convert.o gccDebug/software/system/dsi_debug.o gccDebug/software/serial/dsi_framer.o gccDebug/software/serial/dsi_framer_ant.o gccDebug/software/serial/dsi_framer_integrated_antfs_client.o gccDebug/software/serial/dsi_serial.o gccDebug/software/serial/dsi_serial_generic.o gccDebug/software/system/dsi_thread_posix.o gccDebug/software/system/dsi_timer.o gccDebug/software/system/macros.o gccDebug/software/USB/devices/usb_device.o

GENERAL_RELEASE_OUTPUT_LIST=gccRelease/software/ANTFS/antfs_client_channel.o gccRelease/software/ANTFS/antfs_directory.o gccRelease/software/ANTFS/antfs_host.o gccRelease/software/ANTFS/antfs_host_channel.o gccRelease/common/checksum.o gccRelease/common/crc.o gccRelease/software/serial/device_management/dsi_ant_device.o gccRelease/software/system/dsi_convert.o gccRelease/software/system/dsi_debug.o gccRelease/software/serial/dsi_framer.o gccRelease/software/serial/dsi_framer_ant.o gccRelease/software/serial/dsi_framer_integrated_antfs_client.o gccRelease/software/serial/dsi_serial.o gccRelease/software/serial/dsi_serial_generic.o gccRelease/software/system/dsi_thread_posix.o gccRelease/software/system/dsi_timer.o gccRelease/software/system/macros.o gccRelease/software/USB/devices/usb_device.o

# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

# Include paths...
Debug_Include_Path=-I"inc" -I"common" -I"libraries" -I"software/ANTFS" -I"software/system" -I"software/serial/device_management" -I"software/serial" -I"software/USB" -I"software/USB/devices" -I"software/USB/device_handles"  -I"software/USB/iokit_driver" 
Release_Include_Path=-I"inc" -I"common" -I"libraries" -I"software/ANTFS" -I"software/system" -I"software/serial/device_management" -I"software/serial" -I"software/USB" -I"software/USB/devices" -I"software/USB/device_handles"  -I"software/USB/iokit_driver" 

# Library paths...
Debug_Library_Path=
Release_Library_Path=

# Additional libraries...
Debug_Libraries=
Release_Libraries=

# Preprocessor definitions...
Debug_Preprocessor_Definitions=-D GCC_BUILD -D _DEBUG -D _LIB -D DEBUG_FILE $(LIBUSB_PREPROCESSOR)
Release_Preprocessor_Definitions=-D GCC_BUILD -D NDEBUG -D _LIB -D DEBUG_FILE $(LIBUSB_PREPROCESSOR)

# Implictly linked object files...
Debug_Implicitly_Linked_Objects=gccDebug/libraries/*.o
Release_Implicitly_Linked_Objects=gccRelease/libraries/*.o

# Compiler flags...
Debug_Compiler_Flags=-Wall -O0 -g
Release_Compiler_Flags=-Wall -O2 

# ----------------------------------------------    
# Builds all configurations for this project...
# ----------------------------------------------    
.PHONY: build_all_configurations
build_all_configurations: create_folders Debug Release 

# ----------------------------------------------    
# Builds the Debug configuration...
# ----------------------------------------------    
.PHONY: Debug
Debug: $(GENERAL_DEBUG_OUTPUT_LIST) $(LINUX_DEBUG_OUTPUT_LIST) $(OSX_DEBUG_OUTPUT_LIST)
	ar rcs gccDebug/libANT_LIB.a $(GENERAL_DEBUG_OUTPUT_LIST) $(LINUX_DEBUG_OUTPUT_LIST) $(OSX_DEBUG_OUTPUT_LIST) $(Debug_Implicitly_Linked_Objects)

# Compiles file software/ANTFS/antfs_client_channel.cpp for the Debug configuration...
-include gccDebug/software/ANTFS/antfs_client_channel.d
gccDebug/software/ANTFS/antfs_client_channel.o: software/ANTFS/antfs_client_channel.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/ANTFS/antfs_client_channel.cpp $(Debug_Include_Path) -o gccDebug/software/ANTFS/antfs_client_channel.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/ANTFS/antfs_client_channel.cpp $(Debug_Include_Path) > gccDebug/software/ANTFS/antfs_client_channel.d


# Compiles file software/ANTFS/antfs_directory.c for the Debug configuration...
-include gccDebug/software/ANTFS/antfs_directory.d
gccDebug/software/ANTFS/antfs_directory.o: software/ANTFS/antfs_directory.c
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/ANTFS/antfs_directory.c $(Debug_Include_Path) -o gccDebug/software/ANTFS/antfs_directory.o
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/ANTFS/antfs_directory.c $(Debug_Include_Path) > gccDebug/software/ANTFS/antfs_directory.d

# Compiles file software/ANTFS/antfs_host.cpp for the Debug configuration...
-include gccDebug/software/ANTFS/antfs_host.d
gccDebug/software/ANTFS/antfs_host.o: software/ANTFS/antfs_host.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/ANTFS/antfs_host.cpp $(Debug_Include_Path) -o gccDebug/software/ANTFS/antfs_host.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/ANTFS/antfs_host.cpp $(Debug_Include_Path) > gccDebug/software/ANTFS/antfs_host.d

# Compiles file software/ANTFS/antfs_host_channel.cpp for the Debug configuration...
-include gccDebug/software/ANTFS/antfs_host_channel.d
gccDebug/software/ANTFS/antfs_host_channel.o: software/ANTFS/antfs_host_channel.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/ANTFS/antfs_host_channel.cpp $(Debug_Include_Path) -o gccDebug/software/ANTFS/antfs_host_channel.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/ANTFS/antfs_host_channel.cpp $(Debug_Include_Path) > gccDebug/software/ANTFS/antfs_host_channel.d

# Compiles file common/checksum.c for the Debug configuration...
-include gccDebug/common/checksum.d
gccDebug/common/checksum.o: common/checksum.c
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c common/checksum.c $(Debug_Include_Path) -o gccDebug/common/checksum.o
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM common/checksum.c $(Debug_Include_Path) > gccDebug/common/checksum.d

# Compiles file common/crc.c for the Debug configuration...
-include gccDebug/common/crc.d
gccDebug/common/crc.o: common/crc.c
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c common/crc.c $(Debug_Include_Path) -o gccDebug/common/crc.o
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM common/crc.c $(Debug_Include_Path) > gccDebug/common/crc.d

# Compiles file software/serial/device_management/dsi_ant_device.cpp for the Debug configuration...
-include gccDebug/software/serial/device_management/dsi_ant_device.d
gccDebug/software/serial/device_management/dsi_ant_device.o: software/serial/device_management/dsi_ant_device.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/device_management/dsi_ant_device.cpp $(Debug_Include_Path) -o gccDebug/software/serial/device_management/dsi_ant_device.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/device_management/dsi_ant_device.cpp $(Debug_Include_Path) > gccDebug/software/serial/device_management/dsi_ant_device.d

# Compiles file libraries/dsi_cm_library.cpp for the Debug configuration...
#-include gccDebug/libraries/dsi_cm_library.d
#gccDebug/libraries/dsi_cm_library.o: libraries/dsi_cm_library.cpp
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c libraries/dsi_cm_library.cpp $(Debug_Include_Path) -o gccDebug/libraries/dsi_cm_library.o
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM libraries/dsi_cm_library.cpp $(Debug_Include_Path) > gccDebug/libraries/dsi_cm_library.d

# Compiles file software/system/dsi_convert.c for the Debug configuration...
-include gccDebug/software/system/dsi_convert.d
gccDebug/software/system/dsi_convert.o: software/system/dsi_convert.c
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/system/dsi_convert.c $(Debug_Include_Path) -o gccDebug/software/system/dsi_convert.o
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/system/dsi_convert.c $(Debug_Include_Path) > gccDebug/software/system/dsi_convert.d

# Compiles file software/system/dsi_debug.cpp for the Debug configuration...
-include gccDebug/software/system/dsi_debug.d
gccDebug/software/system/dsi_debug.o: software/system/dsi_debug.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/system/dsi_debug.cpp $(Debug_Include_Path) -o gccDebug/software/system/dsi_debug.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/system/dsi_debug.cpp $(Debug_Include_Path) > gccDebug/software/system/dsi_debug.d

# Compiles file software/serial/dsi_framer.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_framer.d
gccDebug/software/serial/dsi_framer.o: software/serial/dsi_framer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_framer.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_framer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_framer.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_framer.d

# Compiles file software/serial/dsi_framer_ant.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_framer_ant.d
gccDebug/software/serial/dsi_framer_ant.o: software/serial/dsi_framer_ant.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_framer_ant.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_framer_ant.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_framer_ant.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_framer_ant.d

# Compiles file software/serial/dsi_framer_integrated_antfs_client.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_framer_integrated_antfs_client.d
gccDebug/software/serial/dsi_framer_integrated_antfs_client.o: software/serial/dsi_framer_integrated_antfs_client.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_framer_integrated_antfs_client.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_framer_integrated_antfs_client.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_framer_integrated_antfs_client.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_framer_integrated_antfs_client.d

# Compiles file libraries/dsi_libusb_library_linux.cpp for the Debug configuration...
-include gccDebug/libraries/dsi_libusb_library_linux.d
gccDebug/libraries/dsi_libusb_library_linux.o: libraries/dsi_libusb_library_linux.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c libraries/dsi_libusb_library_linux.cpp $(Debug_Include_Path) -o gccDebug/libraries/dsi_libusb_library_linux.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM libraries/dsi_libusb_library_linux.cpp $(Debug_Include_Path) > gccDebug/libraries/dsi_libusb_library_linux.d

# Compiles file software/serial/dsi_serial.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_serial.d
gccDebug/software/serial/dsi_serial.o: software/serial/dsi_serial.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_serial.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_serial.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_serial.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_serial.d

# Compiles file software/serial/dsi_serial_generic.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_serial_generic.d
gccDebug/software/serial/dsi_serial_generic.o: software/serial/dsi_serial_generic.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_serial_generic.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_serial_generic.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_serial_generic.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_serial_generic.d

# Compiles file software/serial/dsi_serial_libusb_linux.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_serial_libusb_linux.d
gccDebug/software/serial/dsi_serial_libusb_linux.o: software/serial/dsi_serial_libusb_linux.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_serial_libusb_linux.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_serial_libusb_linux.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_serial_libusb_linux.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_serial_libusb_linux.d

# Compiles file software/serial/dsi_serial_si.cpp for the Debug configuration...
#-include gccDebug/software/serial/dsi_serial_si.d
#gccDebug/software/serial/dsi_serial_si.o: software/serial/dsi_serial_si.cpp
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_serial_si.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_serial_si.o
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_serial_si.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_serial_si.d

# Compiles file software/serial/dsi_serial_vcp.cpp for the Debug configuration...
#-include gccDebug/software/serial/dsi_serial_vcp.d
#gccDebug/software/serial/dsi_serial_vcp.o: software/serial/dsi_serial_vcp.cpp
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_serial_vcp.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_serial_vcp.o
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_serial_vcp.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_serial_vcp.d

# Compiles file libraries/dsi_silabs_library.cpp for the Debug configuration...
#-include gccDebug/libraries/dsi_silabs_library.d
#gccDebug/libraries/dsi_silabs_library.o: libraries/dsi_silabs_library.cpp
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c libraries/dsi_silabs_library.cpp $(Debug_Include_Path) -o gccDebug/libraries/dsi_silabs_library.o
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM libraries/dsi_silabs_library.cpp $(Debug_Include_Path) > gccDebug/libraries/dsi_silabs_library.d

# Compiles file software/system/dsi_thread_posix.c for the Debug configuration...
-include gccDebug/software/system/dsi_thread_posix.d
gccDebug/software/system/dsi_thread_posix.o: software/system/dsi_thread_posix.c
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/system/dsi_thread_posix.c $(Debug_Include_Path) -o gccDebug/software/system/dsi_thread_posix.o
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/system/dsi_thread_posix.c $(Debug_Include_Path) > gccDebug/software/system/dsi_thread_posix.d

# Compiles file software/system/dsi_timer.cpp for the Debug configuration...
-include gccDebug/software/system/dsi_timer.d
gccDebug/software/system/dsi_timer.o: software/system/dsi_timer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/system/dsi_timer.cpp $(Debug_Include_Path) -o gccDebug/software/system/dsi_timer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/system/dsi_timer.cpp $(Debug_Include_Path) > gccDebug/software/system/dsi_timer.d

# Compiles file software/system/macros.c for the Debug configuration...
-include gccDebug/software/system/macros.d
gccDebug/software/system/macros.o: software/system/macros.c
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/system/macros.c $(Debug_Include_Path) -o gccDebug/software/system/macros.o
	$(C_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/system/macros.c $(Debug_Include_Path) > gccDebug/software/system/macros.d

# Compiles file software/USB/devices/usb_device.cpp for the Debug configuration...
-include gccDebug/software/USB/devices/usb_device.d
gccDebug/software/USB/devices/usb_device.o: software/USB/devices/usb_device.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/devices/usb_device.cpp $(Debug_Include_Path) -o gccDebug/software/USB/devices/usb_device.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/devices/usb_device.cpp $(Debug_Include_Path) > gccDebug/software/USB/devices/usb_device.d

# Compiles file software/USB/device_handles/usb_device_handle_libusb_linux.cpp for the Debug configuration...
-include gccDebug/software/USB/device_handles/usb_device_handle_libusb_linux.d
gccDebug/software/USB/device_handles/usb_device_handle_libusb_linux.o: software/USB/device_handles/usb_device_handle_libusb_linux.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_libusb_linux.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_libusb_linux.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_libusb_linux.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_libusb_linux.d

# Compiles file software/USB/device_handles/usb_device_handle_si.cpp for the Debug configuration...
#-include gccDebug/software/USB/device_handles/usb_device_handle_si.d
#gccDebug/software/USB/device_handles/usb_device_handle_si.o: software/USB/device_handles/usb_device_handle_si.cpp
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_si.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_si.o
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_si.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_si.d

# Compiles file software/USB/device_handles/usb_device_handle_linux.cpp for the Debug configuration...
-include gccDebug/software/USB/device_handles/usb_device_handle_linux.d
gccDebug/software/USB/device_handles/usb_device_handle_linux.o: software/USB/device_handles/usb_device_handle_linux.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_linux.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_linux.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_linux.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_linux.d

# Compiles file software/USB/devices/usb_device_libusb_linux.cpp for the Debug configuration...
-include gccDebug/software/USB/devices/usb_device_libusb_linux.d
gccDebug/software/USB/devices/usb_device_libusb_linux.o: software/USB/devices/usb_device_libusb_linux.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/devices/usb_device_libusb_linux.cpp $(Debug_Include_Path) -o gccDebug/software/USB/devices/usb_device_libusb_linux.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/devices/usb_device_libusb_linux.cpp $(Debug_Include_Path) > gccDebug/software/USB/devices/usb_device_libusb_linux.d

# Compiles file software/USB/devices/usb_device_si.cpp for the Debug configuration...
#-include gccDebug/software/USB/devices/usb_device_si.d
#gccDebug/software/USB/devices/usb_device_si.o: software/USB/devices/usb_device_si.cpp
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/devices/usb_device_si.cpp $(Debug_Include_Path) -o gccDebug/software/USB/devices/usb_device_si.o
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/devices/usb_device_si.cpp $(Debug_Include_Path) > gccDebug/software/USB/devices/usb_device_si.d

# Compiles file software/serial/WinDevice.cpp for the Debug configuration...
#-include gccDebug/software/serial/WinDevice.d
#gccDebug/software/serial/WinDevice.o: software/serial/WinDevice.cpp
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/WinDevice.cpp $(Debug_Include_Path) -o gccDebug/software/serial/WinDevice.o
#	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/WinDevice.cpp $(Debug_Include_Path) > gccDebug/software/serial/WinDevice.d

# OSX Files
# Compiles file libraries/dsi_libusb_library_mac.cpp for the Debug configuration...
-include gccDebug/libraries/dsi_libusb_library_mac.d
gccDebug/libraries/dsi_libusb_library_mac.o: libraries/dsi_libusb_library_mac.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c libraries/dsi_libusb_library_mac.cpp $(Debug_Include_Path) -o gccDebug/libraries/dsi_libusb_library_mac.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM libraries/dsi_libusb_library_mac.cpp $(Debug_Include_Path) > gccDebug/libraries/dsi_libusb_library_mac.d

# Compiles file software/serial/dsi_serial_libusb_mac.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_serial_libusb_mac.d
gccDebug/software/serial/dsi_serial_libusb_mac.o: software/serial/dsi_serial_libusb_mac.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_serial_libusb_mac.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_serial_libusb_mac.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_serial_libusb_mac.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_serial_libusb_mac.d

# Compiles file software/serial/dsi_serial_iokit.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_serial_iokit.d
gccDebug/software/serial/dsi_serial_iokit.o: software/serial/dsi_serial_iokit.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_serial_iokit.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_serial_iokit.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_serial_iokit.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_serial_iokit.d

# Compiles file software/serial/dsi_vcp_si.cpp for the Debug configuration...
-include gccDebug/software/serial/dsi_vcp_si.d
gccDebug/software/serial/dsi_vcp_si.o: software/serial/dsi_vcp_si.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/serial/dsi_vcp_si.cpp $(Debug_Include_Path) -o gccDebug/software/serial/dsi_vcp_si.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/serial/dsi_vcp_si.cpp $(Debug_Include_Path) > gccDebug/software/serial/dsi_vcp_si.d

    # Compiles file software/USB/device_handles/usb_device_handle_libusb_mac.cpp for the Debug configuration...
-include gccDebug/software/USB/device_handles/usb_device_handle_libusb_mac.d
gccDebug/software/USB/device_handles/usb_device_handle_libusb_mac.o: software/USB/device_handles/usb_device_handle_libusb_mac.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_libusb_mac.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_libusb_mac.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_libusb_mac.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_libusb_mac.d

# Compiles file software/USB/device_handles/usb_device_handle_iokit.cpp for the Debug configuration...
-include gccDebug/software/USB/device_handles/usb_device_handle_iokit.d
gccDebug/software/USB/device_handles/usb_device_handle_iokit.o: software/USB/device_handles/usb_device_handle_iokit.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_iokit.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_iokit.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_iokit.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_iokit.d

# Compiles file software/USB/device_handles/usb_device_handle_si_iokit.cpp for the Debug configuration...
-include gccDebug/software/USB/device_handles/usb_device_handle_si_iokit.d
gccDebug/software/USB/device_handles/usb_device_handle_si_iokit.o: software/USB/device_handles/usb_device_handle_si_iokit.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_si_iokit.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_si_iokit.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_si_iokit.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_si_iokit.d

# Compiles file software/USB/device_handles/usb_device_handle_vcp.cpp for the Debug configuration...
-include gccDebug/software/USB/device_handles/usb_device_handle_vcp.d
gccDebug/software/USB/device_handles/usb_device_handle_vcp.o: software/USB/device_handles/usb_device_handle_vcp.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_vcp.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_vcp.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_vcp.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_vcp.d

# Compiles file software/USB/device_handles/usb_device_handle_mac.cpp for the Debug configuration...
-include gccDebug/software/USB/device_handles/usb_device_handle_mac.d
gccDebug/software/USB/device_handles/usb_device_handle_mac.o: software/USB/device_handles/usb_device_handle_mac.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_mac.cpp $(Debug_Include_Path) -o gccDebug/software/USB/device_handles/usb_device_handle_mac.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_mac.cpp $(Debug_Include_Path) > gccDebug/software/USB/device_handles/usb_device_handle_mac.d

# Compiles file software/USB/devices/usb_device_libusb_mac.cpp for the Debug configuration...
-include gccDebug/software/USB/devices/usb_device_libusb_mac.d
gccDebug/software/USB/devices/usb_device_libusb_mac.o: software/USB/devices/usb_device_libusb_mac.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/devices/usb_device_libusb_mac.cpp $(Debug_Include_Path) -o gccDebug/software/USB/devices/usb_device_libusb_mac.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/devices/usb_device_libusb_mac.cpp $(Debug_Include_Path) > gccDebug/software/USB/devices/usb_device_libusb_mac.d

# Compiles file software/USB/devices/usb_device_iokit.cpp for the Debug configuration...
-include gccDebug/software/USB/devices/usb_device_iokit.d
gccDebug/software/USB/devices/usb_device_iokit.o: software/USB/devices/usb_device_iokit.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/devices/usb_device_iokit.cpp $(Debug_Include_Path) -o gccDebug/software/USB/devices/usb_device_iokit.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/devices/usb_device_iokit.cpp $(Debug_Include_Path) > gccDebug/software/USB/devices/usb_device_iokit.d
    
# Compiles file software/USB/devices/usb_device_vcp.cpp for the Debug configuration...
-include gccDebug/software/USB/devices/usb_device_vcp.d
gccDebug/software/USB/devices/usb_device_vcp.o: software/USB/devices/usb_device_vcp.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/devices/usb_device_vcp.cpp $(Debug_Include_Path) -o gccDebug/software/USB/devices/usb_device_vcp.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/devices/usb_device_vcp.cpp $(Debug_Include_Path) > gccDebug/software/USB/devices/usb_device_vcp.d
    
# Compiles file software/USB/iokit_driver/iokit_device.cpp for the Debug configuration...
-include gccDebug/software/USB/iokit_driver/iokit_device.d
gccDebug/software/USB/iokit_driver/iokit_device.o: software/USB/iokit_driver/iokit_device.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/iokit_driver/iokit_device.cpp $(Debug_Include_Path) -o gccDebug/software/USB/iokit_driver/iokit_device.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/iokit_driver/iokit_device.cpp $(Debug_Include_Path) > gccDebug/software/USB/iokit_driver/iokit_device.d

# Compiles file software/USB/iokit_driver/iokit_device_handle.cpp for the Debug configuration...
-include gccDebug/software/USB/iokit_driver/iokit_device_handle.d
gccDebug/software/USB/iokit_driver/iokit_device_handle.o: software/USB/iokit_driver/iokit_device_handle.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/iokit_driver/iokit_device_handle.cpp $(Debug_Include_Path) -o gccDebug/software/USB/iokit_driver/iokit_device_handle.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/iokit_driver/iokit_device_handle.cpp $(Debug_Include_Path) > gccDebug/software/USB/iokit_driver/iokit_device_handle.d

# Compiles file software/USB/iokit_driver/iokit_device_list.cpp for the Debug configuration...
-include gccDebug/software/USB/iokit_driver/iokit_device_list.d
gccDebug/software/USB/iokit_driver/iokit_device_list.o: software/USB/iokit_driver/iokit_device_list.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/iokit_driver/iokit_device_list.cpp $(Debug_Include_Path) -o gccDebug/software/USB/iokit_driver/iokit_device_list.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/iokit_driver/iokit_device_list.cpp $(Debug_Include_Path) > gccDebug/software/USB/iokit_driver/iokit_device_list.d

# Compiles file software/USB/iokit_driver/iokit_interface.cpp for the Debug configuration...
-include gccDebug/software/USB/iokit_driver/iokit_interface.d
gccDebug/software/USB/iokit_driver/iokit_interface.o: software/USB/iokit_driver/iokit_interface.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/iokit_driver/iokit_interface.cpp $(Debug_Include_Path) -o gccDebug/software/USB/iokit_driver/iokit_interface.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/iokit_driver/iokit_interface.cpp $(Debug_Include_Path) > gccDebug/software/USB/iokit_driver/iokit_interface.d

# Compiles file software/USB/iokit_driver/iokit_transfer.cpp for the Debug configuration...
-include gccDebug/software/USB/iokit_driver/iokit_transfer.d
gccDebug/software/USB/iokit_driver/iokit_transfer.o: software/USB/iokit_driver/iokit_transfer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c software/USB/iokit_driver/iokit_transfer.cpp $(Debug_Include_Path) -o gccDebug/software/USB/iokit_driver/iokit_transfer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM software/USB/iokit_driver/iokit_transfer.cpp $(Debug_Include_Path) > gccDebug/software/USB/iokit_driver/iokit_transfer.d

# ----------------------------------------------    
# Builds the Release configuration...
# ----------------------------------------------    
.PHONY: Release
Release: $(GENERAL_RELEASE_OUTPUT_LIST) $(LINUX_RELEASE_OUTPUT_LIST) $(OSX_RELEASE_OUTPUT_LIST)
	ar rcs gccRelease/libANT_LIB.a $(GENERAL_RELEASE_OUTPUT_LIST) $(LINUX_RELEASE_OUTPUT_LIST) $(OSX_RELEASE_OUTPUT_LIST) $(Release_Implicitly_Linked_Objects)
    
# Compiles file software/ANTFS/antfs_client_channel.cpp for the Release configuration...
-include gccRelease/software/ANTFS/antfs_client_channel.d
gccRelease/software/ANTFS/antfs_client_channel.o: software/ANTFS/antfs_client_channel.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/ANTFS/antfs_client_channel.cpp $(Release_Include_Path) -o gccRelease/software/ANTFS/antfs_client_channel.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/ANTFS/antfs_client_channel.cpp $(Release_Include_Path) > gccRelease/software/ANTFS/antfs_client_channel.d

# Compiles file software/ANTFS/antfs_directory.c for the Release configuration...
-include gccRelease/software/ANTFS/antfs_directory.d
gccRelease/software/ANTFS/antfs_directory.o: software/ANTFS/antfs_directory.c
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/ANTFS/antfs_directory.c $(Release_Include_Path) -o gccRelease/software/ANTFS/antfs_directory.o
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/ANTFS/antfs_directory.c $(Release_Include_Path) > gccRelease/software/ANTFS/antfs_directory.d

# Compiles file software/ANTFS/antfs_host.cpp for the Release configuration...
-include gccRelease/software/ANTFS/antfs_host.d
gccRelease/software/ANTFS/antfs_host.o: software/ANTFS/antfs_host.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/ANTFS/antfs_host.cpp $(Release_Include_Path) -o gccRelease/software/ANTFS/antfs_host.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/ANTFS/antfs_host.cpp $(Release_Include_Path) > gccRelease/software/ANTFS/antfs_host.d

# Compiles file software/ANTFS/antfs_host_channel.cpp for the Release configuration...
-include gccRelease/software/ANTFS/antfs_host_channel.d
gccRelease/software/ANTFS/antfs_host_channel.o: software/ANTFS/antfs_host_channel.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/ANTFS/antfs_host_channel.cpp $(Release_Include_Path) -o gccRelease/software/ANTFS/antfs_host_channel.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/ANTFS/antfs_host_channel.cpp $(Release_Include_Path) > gccRelease/software/ANTFS/antfs_host_channel.d

# Compiles file common/checksum.c for the Release configuration...
-include gccRelease/common/checksum.d
gccRelease/common/checksum.o: common/checksum.c
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c common/checksum.c $(Release_Include_Path) -o gccRelease/common/checksum.o
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM common/checksum.c $(Release_Include_Path) > gccRelease/common/checksum.d

# Compiles file common/crc.c for the Release configuration...
-include gccRelease/common/crc.d
gccRelease/common/crc.o: common/crc.c
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c common/crc.c $(Release_Include_Path) -o gccRelease/common/crc.o
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM common/crc.c $(Release_Include_Path) > gccRelease/common/crc.d

# Compiles file software/serial/device_management/dsi_ant_device.cpp for the Release configuration...
-include gccRelease/software/serial/device_management/dsi_ant_device.d
gccRelease/software/serial/device_management/dsi_ant_device.o: software/serial/device_management/dsi_ant_device.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/device_management/dsi_ant_device.cpp $(Release_Include_Path) -o gccRelease/software/serial/device_management/dsi_ant_device.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/device_management/dsi_ant_device.cpp $(Release_Include_Path) > gccRelease/software/serial/device_management/dsi_ant_device.d

# Compiles file libraries/dsi_cm_library.cpp for the Release configuration...
#-include gccRelease/libraries/dsi_cm_library.d
#gccRelease/libraries/dsi_cm_library.o: libraries/dsi_cm_library.cpp
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c libraries/dsi_cm_library.cpp $(Release_Include_Path) -o gccRelease/libraries/dsi_cm_library.o
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM libraries/dsi_cm_library.cpp $(Release_Include_Path) > gccRelease/libraries/dsi_cm_library.d

# Compiles file software/system/dsi_convert.c for the Release configuration...
-include gccRelease/software/system/dsi_convert.d
gccRelease/software/system/dsi_convert.o: software/system/dsi_convert.c
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/system/dsi_convert.c $(Release_Include_Path) -o gccRelease/software/system/dsi_convert.o
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/system/dsi_convert.c $(Release_Include_Path) > gccRelease/software/system/dsi_convert.d

# Compiles file software/system/dsi_debug.cpp for the Release configuration...
-include gccRelease/software/system/dsi_debug.d
gccRelease/software/system/dsi_debug.o: software/system/dsi_debug.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/system/dsi_debug.cpp $(Release_Include_Path) -o gccRelease/software/system/dsi_debug.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/system/dsi_debug.cpp $(Release_Include_Path) > gccRelease/software/system/dsi_debug.d

# Compiles file software/serial/dsi_framer.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_framer.d
gccRelease/software/serial/dsi_framer.o: software/serial/dsi_framer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_framer.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_framer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_framer.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_framer.d

# Compiles file software/serial/dsi_framer_ant.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_framer_ant.d
gccRelease/software/serial/dsi_framer_ant.o: software/serial/dsi_framer_ant.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_framer_ant.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_framer_ant.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_framer_ant.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_framer_ant.d

# Compiles file software/serial/dsi_framer_integrated_antfs_client.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_framer_integrated_antfs_client.d
gccRelease/software/serial/dsi_framer_integrated_antfs_client.o: software/serial/dsi_framer_integrated_antfs_client.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_framer_integrated_antfs_client.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_framer_integrated_antfs_client.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_framer_integrated_antfs_client.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_framer_integrated_antfs_client.d

# Compiles file libraries/dsi_libusb_library_linux.cpp for the Release configuration...
-include gccRelease/libraries/dsi_libusb_library_linux.d
gccRelease/libraries/dsi_libusb_library_linux.o: libraries/dsi_libusb_library_linux.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c libraries/dsi_libusb_library_linux.cpp $(Release_Include_Path) -o gccRelease/libraries/dsi_libusb_library_linux.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM libraries/dsi_libusb_library_linux.cpp $(Release_Include_Path) > gccRelease/libraries/dsi_libusb_library_linux.d

# Compiles file software/serial/dsi_serial.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_serial.d
gccRelease/software/serial/dsi_serial.o: software/serial/dsi_serial.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_serial.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_serial.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_serial.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_serial.d

# Compiles file software/serial/dsi_serial_generic.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_serial_generic.d
gccRelease/software/serial/dsi_serial_generic.o: software/serial/dsi_serial_generic.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_serial_generic.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_serial_generic.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_serial_generic.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_serial_generic.d

# Compiles file software/serial/dsi_serial_libusb_linux.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_serial_libusb_linux.d
gccRelease/software/serial/dsi_serial_libusb_linux.o: software/serial/dsi_serial_libusb_linux.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_serial_libusb_linux.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_serial_libusb_linux.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_serial_libusb_linux.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_serial_libusb_linux.d

# Compiles file software/serial/dsi_serial_si.cpp for the Release configuration...
#-include gccRelease/software/serial/dsi_serial_si.d
#gccRelease/software/serial/dsi_serial_si.o: software/serial/dsi_serial_si.cpp
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_serial_si.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_serial_si.o
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_serial_si.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_serial_si.d

# Compiles file software/serial/dsi_serial_vcp.cpp for the Release configuration...
#-include gccRelease/software/serial/dsi_serial_vcp.d
#gccRelease/software/serial/dsi_serial_vcp.o: software/serial/dsi_serial_vcp.cpp
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_serial_vcp.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_serial_vcp.o
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_serial_vcp.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_serial_vcp.d

# Compiles file libraries/dsi_silabs_library.cpp for the Release configuration...
#-include gccRelease/libraries/dsi_silabs_library.d
#gccRelease/libraries/dsi_silabs_library.o: libraries/dsi_silabs_library.cpp
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c libraries/dsi_silabs_library.cpp $(Release_Include_Path) -o gccRelease/libraries/dsi_silabs_library.o
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM libraries/dsi_silabs_library.cpp $(Release_Include_Path) > gccRelease/libraries/dsi_silabs_library.d

# Compiles file software/system/dsi_thread_posix.c for the Release configuration...
-include gccRelease/software/system/dsi_thread_posix.d
gccRelease/software/system/dsi_thread_posix.o: software/system/dsi_thread_posix.c
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/system/dsi_thread_posix.c $(Release_Include_Path) -o gccRelease/software/system/dsi_thread_posix.o
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/system/dsi_thread_posix.c $(Release_Include_Path) > gccRelease/software/system/dsi_thread_posix.d

# Compiles file software/system/dsi_timer.cpp for the Release configuration...
-include gccRelease/software/system/dsi_timer.d
gccRelease/software/system/dsi_timer.o: software/system/dsi_timer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/system/dsi_timer.cpp $(Release_Include_Path) -o gccRelease/software/system/dsi_timer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/system/dsi_timer.cpp $(Release_Include_Path) > gccRelease/software/system/dsi_timer.d

# Compiles file software/system/macros.c for the Release configuration...
-include gccRelease/software/system/macros.d
gccRelease/software/system/macros.o: software/system/macros.c
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/system/macros.c $(Release_Include_Path) -o gccRelease/software/system/macros.o
	$(C_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/system/macros.c $(Release_Include_Path) > gccRelease/software/system/macros.d

# Compiles file software/USB/devices/usb_device.cpp for the Release configuration...
-include gccRelease/software/USB/devices/usb_device.d
gccRelease/software/USB/devices/usb_device.o: software/USB/devices/usb_device.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/devices/usb_device.cpp $(Release_Include_Path) -o gccRelease/software/USB/devices/usb_device.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/devices/usb_device.cpp $(Release_Include_Path) > gccRelease/software/USB/devices/usb_device.d

# Compiles file software/USB/device_handles/usb_device_handle_libusb_linux.cpp for the Release configuration...
-include gccRelease/software/USB/device_handles/usb_device_handle_libusb_linux.d
gccRelease/software/USB/device_handles/usb_device_handle_libusb_linux.o: software/USB/device_handles/usb_device_handle_libusb_linux.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_libusb_linux.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_libusb_linux.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_libusb_linux.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_libusb_linux.d

# Compiles file software/USB/device_handles/usb_device_handle_si.cpp for the Release configuration...
#-include gccRelease/software/USB/device_handles/usb_device_handle_si.d
#gccRelease/software/USB/device_handles/usb_device_handle_si.o: software/USB/device_handles/usb_device_handle_si.cpp
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_si.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_si.o
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_si.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_si.d

# Compiles file software/USB/device_handles/usb_device_handle_linux.cpp for the Release configuration...
-include gccRelease/software/USB/device_handles/usb_device_handle_linux.d
gccRelease/software/USB/device_handles/usb_device_handle_linux.o: software/USB/device_handles/usb_device_handle_linux.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_linux.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_linux.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_linux.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_linux.d

# Compiles file software/USB/devices/usb_device_libusb_linux.cpp for the Release configuration...
-include gccRelease/software/USB/devices/usb_device_libusb_linux.d
gccRelease/software/USB/devices/usb_device_libusb_linux.o: software/USB/devices/usb_device_libusb_linux.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/devices/usb_device_libusb_linux.cpp $(Release_Include_Path) -o gccRelease/software/USB/devices/usb_device_libusb_linux.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/devices/usb_device_libusb_linux.cpp $(Release_Include_Path) > gccRelease/software/USB/devices/usb_device_libusb_linux.d

# Compiles file software/USB/devices/usb_device_si.cpp for the Release configuration...
#-include gccRelease/software/USB/devices/usb_device_si.d
#gccRelease/software/USB/devices/usb_device_si.o: software/USB/devices/usb_device_si.cpp
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/devices/usb_device_si.cpp $(Release_Include_Path) -o gccRelease/software/USB/devices/usb_device_si.o
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/devices/usb_device_si.cpp $(Release_Include_Path) > gccRelease/software/USB/devices/usb_device_si.d

# Compiles file software/serial/WinDevice.cpp for the Release configuration...
#-include gccRelease/software/serial/WinDevice.d
#gccRelease/software/serial/WinDevice.o: software/serial/WinDevice.cpp
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/WinDevice.cpp $(Release_Include_Path) -o gccRelease/software/serial/WinDevice.o
#	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/WinDevice.cpp $(Release_Include_Path) > gccRelease/software/serial/WinDevice.d

# OSX Files
# Compiles file libraries/dsi_libusb_library_mac.cpp for the Release configuration...
-include gccRelease/libraries/dsi_libusb_library_mac.d
gccRelease/libraries/dsi_libusb_library_mac.o: libraries/dsi_libusb_library_mac.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c libraries/dsi_libusb_library_mac.cpp $(Release_Include_Path) -o gccRelease/libraries/dsi_libusb_library_mac.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM libraries/dsi_libusb_library_mac.cpp $(Release_Include_Path) > gccRelease/libraries/dsi_libusb_library_mac.d

# Compiles file software/serial/dsi_serial_libusb_mac.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_serial_libusb_mac.d
gccRelease/software/serial/dsi_serial_libusb_mac.o: software/serial/dsi_serial_libusb_mac.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_serial_libusb_mac.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_serial_libusb_mac.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_serial_libusb_mac.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_serial_libusb_mac.d

# Compiles file software/serial/dsi_serial_iokit.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_serial_iokit.d
gccRelease/software/serial/dsi_serial_iokit.o: software/serial/dsi_serial_iokit.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_serial_iokit.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_serial_iokit.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_serial_iokit.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_serial_iokit.d

# Compiles file software/serial/dsi_vcp_si.cpp for the Release configuration...
-include gccRelease/software/serial/dsi_vcp_si.d
gccRelease/software/serial/dsi_vcp_si.o: software/serial/dsi_vcp_si.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/serial/dsi_vcp_si.cpp $(Release_Include_Path) -o gccRelease/software/serial/dsi_vcp_si.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/serial/dsi_vcp_si.cpp $(Release_Include_Path) > gccRelease/software/serial/dsi_vcp_si.d

# Compiles file software/USB/device_handles/usb_device_handle_libusb_mac.cpp for the Release configuration...
-include gccRelease/software/USB/device_handles/usb_device_handle_libusb_mac.d
gccRelease/software/USB/device_handles/usb_device_handle_libusb_mac.o: software/USB/device_handles/usb_device_handle_libusb_mac.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_libusb_mac.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_libusb_mac.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_libusb_mac.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_libusb_mac.d

# Compiles file software/USB/device_handles/usb_device_handle_iokit.cpp for the Release configuration...
-include gccRelease/software/USB/device_handles/usb_device_handle_iokit.d
gccRelease/software/USB/device_handles/usb_device_handle_iokit.o: software/USB/device_handles/usb_device_handle_iokit.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_iokit.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_iokit.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_iokit.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_iokit.d

# Compiles file software/USB/device_handles/usb_device_handle_si_iokit.cpp for the Release configuration...
-include gccRelease/software/USB/device_handles/usb_device_handle_si_iokit.d
gccRelease/software/USB/device_handles/usb_device_handle_si_iokit.o: software/USB/device_handles/usb_device_handle_si_iokit.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_si_iokit.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_si_iokit.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_si_iokit.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_si_iokit.d

# Compiles file software/USB/device_handles/usb_device_handle_vcp.cpp for the Release configuration...
-include gccRelease/software/USB/device_handles/usb_device_handle_vcp.d
gccRelease/software/USB/device_handles/usb_device_handle_vcp.o: software/USB/device_handles/usb_device_handle_vcp.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_vcp.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_vcp.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_vcp.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_vcp.d

# Compiles file software/USB/device_handles/usb_device_handle_mac.cpp for the Release configuration...
-include gccRelease/software/USB/device_handles/usb_device_handle_mac.d
gccRelease/software/USB/device_handles/usb_device_handle_mac.o: software/USB/device_handles/usb_device_handle_mac.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/device_handles/usb_device_handle_mac.cpp $(Release_Include_Path) -o gccRelease/software/USB/device_handles/usb_device_handle_mac.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/device_handles/usb_device_handle_mac.cpp $(Release_Include_Path) > gccRelease/software/USB/device_handles/usb_device_handle_mac.d

# Compiles file software/USB/devices/usb_device_libusb_mac.cpp for the Release configuration...
-include gccRelease/software/USB/devices/usb_device_libusb_mac.d
gccRelease/software/USB/devices/usb_device_libusb_mac.o: software/USB/devices/usb_device_libusb_mac.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/devices/usb_device_libusb_mac.cpp $(Release_Include_Path) -o gccRelease/software/USB/devices/usb_device_libusb_mac.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/devices/usb_device_libusb_mac.cpp $(Release_Include_Path) > gccRelease/software/USB/devices/usb_device_libusb_mac.d

# Compiles file software/USB/devices/usb_device_iokit.cpp for the Release configuration...
-include gccRelease/software/USB/devices/usb_device_iokit.d
gccRelease/software/USB/devices/usb_device_iokit.o: software/USB/devices/usb_device_iokit.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/devices/usb_device_iokit.cpp $(Release_Include_Path) -o gccRelease/software/USB/devices/usb_device_iokit.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/devices/usb_device_iokit.cpp $(Release_Include_Path) > gccRelease/software/USB/devices/usb_device_iokit.d
    
# Compiles file software/USB/devices/usb_device_vcp.cpp for the Release configuration...
-include gccRelease/software/USB/devices/usb_device_vcp.d
gccRelease/software/USB/devices/usb_device_vcp.o: software/USB/devices/usb_device_vcp.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/devices/usb_device_vcp.cpp $(Release_Include_Path) -o gccRelease/software/USB/devices/usb_device_vcp.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/devices/usb_device_vcp.cpp $(Release_Include_Path) > gccRelease/software/USB/devices/usb_device_vcp.d
    
# Compiles file software/USB/iokit_driver/iokit_device.cpp for the Release configuration...
-include gccRelease/software/USB/iokit_driver/iokit_device.d
gccRelease/software/USB/iokit_driver/iokit_device.o: software/USB/iokit_driver/iokit_device.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/iokit_driver/iokit_device.cpp $(Release_Include_Path) -o gccRelease/software/USB/iokit_driver/iokit_device.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/iokit_driver/iokit_device.cpp $(Release_Include_Path) > gccRelease/software/USB/iokit_driver/iokit_device.d

# Compiles file software/USB/iokit_driver/iokit_device_handle.cpp for the Release configuration...
-include gccRelease/software/USB/iokit_driver/iokit_device_handle.d
gccRelease/software/USB/iokit_driver/iokit_device_handle.o: software/USB/iokit_driver/iokit_device_handle.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/iokit_driver/iokit_device_handle.cpp $(Release_Include_Path) -o gccRelease/software/USB/iokit_driver/iokit_device_handle.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/iokit_driver/iokit_device_handle.cpp $(Release_Include_Path) > gccRelease/software/USB/iokit_driver/iokit_device_handle.d

# Compiles file software/USB/iokit_driver/iokit_device_list.cpp for the Release configuration...
-include gccRelease/software/USB/iokit_driver/iokit_device_list.d
gccRelease/software/USB/iokit_driver/iokit_device_list.o: software/USB/iokit_driver/iokit_device_list.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/iokit_driver/iokit_device_list.cpp $(Release_Include_Path) -o gccRelease/software/USB/iokit_driver/iokit_device_list.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/iokit_driver/iokit_device_list.cpp $(Release_Include_Path) > gccRelease/software/USB/iokit_driver/iokit_device_list.d

# Compiles file software/USB/iokit_driver/iokit_interface.cpp for the Release configuration...
-include gccRelease/software/USB/iokit_driver/iokit_interface.d
gccRelease/software/USB/iokit_driver/iokit_interface.o: software/USB/iokit_driver/iokit_interface.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/iokit_driver/iokit_interface.cpp $(Release_Include_Path) -o gccRelease/software/USB/iokit_driver/iokit_interface.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/iokit_driver/iokit_interface.cpp $(Release_Include_Path) > gccRelease/software/USB/iokit_driver/iokit_interface.d

# Compiles file software/USB/iokit_driver/iokit_transfer.cpp for the Release configuration...
-include gccRelease/software/USB/iokit_driver/iokit_transfer.d
gccRelease/software/USB/iokit_driver/iokit_transfer.o: software/USB/iokit_driver/iokit_transfer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c software/USB/iokit_driver/iokit_transfer.cpp $(Release_Include_Path) -o gccRelease/software/USB/iokit_driver/iokit_transfer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM software/USB/iokit_driver/iokit_transfer.cpp $(Release_Include_Path) > gccRelease/software/USB/iokit_driver/iokit_transfer.d

    
    
# ----------------------------------------------    
# Creates the intermediate and output folders for each configuration...
# ----------------------------------------------    
.PHONY: create_folders
create_folders:
	rm -rf gccDebug
	rm -rf gccRelease
	mkdir -p gccDebug/software/USB/device_handles
	mkdir -p gccDebug/software/USB/devices
	mkdir -p gccDebug/software/USB/iokit_driver
	mkdir -p gccDebug/software/system
	mkdir -p gccDebug/software/serial/device_management
	mkdir -p gccDebug/software/ANTFS
	mkdir -p gccDebug/libraries
	mkdir -p gccDebug/common
	mkdir -p gccRelease/software/USB/device_handles
	mkdir -p gccRelease/software/USB/devices
	mkdir -p gccRelease/software/USB/iokit_driver
	mkdir -p gccRelease/software/system 
	mkdir -p gccRelease/software/serial/device_management
	mkdir -p gccRelease/software/ANTFS
	mkdir -p gccRelease/libraries
	mkdir -p gccRelease/common
    
    # Linux libusb
    ifeq ($(BUILD_OS), linux)
		echo "Unpacking and building libudev & libusb-1.0..."
		tar xvjf libraries/libudev/udev_*.* && cd udev* && ./configure && make && cp libudev/.libs/libudev*.o ../gccDebug/libraries && cp libudev/.libs/libudev*.o ../gccRelease/libraries && cd .. && rm -R udev*
		tar xvjf libraries/libusb-1.0/libusb-1.0.* && cd libusb-1.0.*  && ./configure && make && cp libusb/libusb*.o ../gccDebug/libraries && cp libusb/os/libusb*.o ../gccDebug/libraries && cp libusb/os/libusb*.o ../gccRelease/libraries && mv libusb/libusb*.o ../gccRelease/libraries && cd ..  && rm -R libusb-1.0.*
        
    # OSX libusb
    else ifeq ($(BUILD_OS), osx)
        ifeq ($(FRAMEWORK_TYPE), libusb)
			echo "Unpacking and building libusb-1.0..."
			tar -zxvf libraries/libusb-1.0/libusb-1.0.* && cd libusb-1.0.*  && ./configure && make && cp libusb/libusb*.o ../gccDebug/libraries && cp libusb/os/libusb*.o ../gccDebug/libraries && cp libusb/os/libusb*.o ../gccRelease/libraries && mv libusb/libusb*.o ../gccRelease/libraries && cd ..  && rm -R libusb-1.0.*
        endif
    endif

    
    
# ----------------------------------------------    
# Cleans intermediate and output files (objects, libraries, executables)...
# ----------------------------------------------    
.PHONY: clean
clean:
	rm -f gccDebug/*.o
	rm -f gccDebug/*.d
	rm -f gccRelease/*.o
	rm -f gccRelease/*.d

