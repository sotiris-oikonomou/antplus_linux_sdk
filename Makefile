CC=g++
ODIR = obj
BINDIR = bin
SRCDIR = src
LIB_INSTALL_DIR = /usr/lib
INCLUDES_INSTALL_DIR = /usr/include/ant
ANT_LIB_DIR = $(SRCDIR)/ANT_LIB
ANT_LIB_RELEASE_DIR = $(ANT_LIB_DIR)/gccRelease
ANT_LIB_DEBUG_DIR = $(ANT_LIB_DIR)/gccDebug
ANT_DYLIB_DIR = $(SRCDIR)/ANT_DLL

SHARED_LIBRARY_NAME = libANT.dylib

CFLAGS_ANT_DYLIB = -Os -fPIC -shared -std=c++11 -Wall
CFLAGS_ANT_DYLIB_DEBUG = -g -O0 -v -da -Q -rdynamic -fPIC -shared -std=c++11

CINCLUDES_ANT_DYLIB = -I $(ANT_LIB_DIR)/inc \
	-I $(ANT_LIB_DIR)/software/ANTFS \
	-I $(ANT_LIB_DIR)/software/serial \
	-I $(ANT_LIB_DIR)/software/serial/device_management \
	-I $(ANT_LIB_DIR)/software/system \
	-I $(ANT_LIB_DIR)/software/USB \
	-I $(ANT_LIB_DIR)/software/USB/device_handles \
	-I $(ANT_LIB_DIR)/software/USB/devices \
	-I $(ANT_LIB_DIR)/software/USB/iokit_driver

CLINKS_ANT_DYLIB = -L $(ANT_LIB_RELEASE_DIR)
CLINKS_ANT_DYLIB_DEBUG = -L $(ANT_LIB_DEBUG_DIR)
LIBS_ANT_DYLIB = -Wl,-Bstatic -l:libANT_LIB.a -Wl,-Bdynamic -lusb-1.0

OBJ_ANT_DYLIB = $(ODIR)/ant.o

.PHONY: all ANT_LIB ANT_LIB_clean clean install uninstall

$(ODIR)/%.o: $(ANT_DYLIB_DIR)/%.cpp $(DEPS)
	@mkdir -p $(ODIR)
	@echo Compiling $< to $@
	@$(CC) -c -o $@ $< $(CFLAGS_ANT_DYLIB) $(CINCLUDES_ANT_DYLIB)

all: $(SHARED_LIBRARY_NAME)

$(SHARED_LIBRARY_NAME): $(OBJ_ANT_DYLIB)
	@echo Creating the $@ library
	@mkdir -p $(BINDIR)
	@$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS_ANT_DYLIB) $(CLINKS_ANT_DYLIB) $(CINCLUDES_ANT_DYLIB) $(LIBS_ANT_DYLIB)
	@echo $@ library is ready in $(BINDIR)
	@echo

debug: $(OBJ_ANT_DYLIB)
	@echo Creating the $@ library
	@mkdir -p $(BINDIR)
	@$(CC) -o $(BINDIR)/$(SHARED_LIBRARY_NAME) $^ $(CFLAGS_ANT_DYLIB_DEBUG) $(CLINKS_ANT_DYLIB_DEBUG) $(CINCLUDES_ANT_DYLIB) $(LIBS_ANT_DYLIB)
	@echo $@ library is ready in $(BINDIR)
	@echo

ANT_LIB:
	@echo Compiling the ANT_LIB
	@make -C $(ANT_LIB_DIR)

ANT_LIB_clean:
	@echo Cleaning ANT_LIB
	@make -C $(ANT_LIB_DIR) clean

clean:
	@echo Deleting the object files
	@-rm -f $(BINDIR)/$(SHARED_LIBRARY_NAME)
	@-rm -f $(ODIR)/*.*
	@echo Cleaning Done
	@echo

install:
	@echo Installing the library to $(LIB_INSTALL_DIR)/$(SHARED_LIBRARY_NAME)
	@cp $(BINDIR)/$(SHARED_LIBRARY_NAME) $(LIB_INSTALL_DIR)/$(SHARED_LIBRARY_NAME)

	@echo Installing the include file to $(INCLUDES_INSTALL_DIR)
	@mkdir -p $(INCLUDES_INSTALL_DIR)
	@cp $(ANT_DYLIB_DIR)/ant.h $(INCLUDES_INSTALL_DIR)/ant.h

	@echo Installing Done
	@echo

uninstall:
	@echo Uninstalling $(SHARED_LIBRARY_NAME)
	@-rm $(LIB_INSTALL_DIR)/$(SHARED_LIBRARY_NAME)
	@-rm $(INCLUDES_INSTALL_DIR)/ant.h
	@echo Uninstalling Done
	@echo

