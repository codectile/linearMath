# Project Configurations
PROJECT_NAME="LinearMath"
PROJECT_AUTHOR="codectile"
PROJECT_DESCRIPTION="Linear mathematics plugin for sa-mp."
PROJECT_EXECUTABLE="linear.so"
			   
# Linux Compiler Configurations
LINUX_COMPILER=g++ -m32
LINUX_GCC=gcc -m32

# (Linux) Compiler Configurations
L_FLAGS=
L_COMPILER_FLAGS=-c $(FRAMEWORK_BUILD_FLAGS) -I../include -I../src/SDK $(shell pkg-config --cflags bullet)
L_LINKER_FLAGS= $(shell pkg-config --libs bullet)
# (Source Files)
SRC_FOLDER=../src
SOURCES=	linear.cpp \
			SDK/amxplugin.cpp

# (Object Files)
OBJECTS=$(foreach source, $(SOURCES), ./objects/$(source).o)
OBJECT_DIRS=SDK 

# (Lets Begin)
all: CREATE_OBJECT_DIRECTORIES linux

# Preparing for compiling.
CREATE_OBJECT_DIRECTORIES:
	@mkdir -p ./objects
	@$(foreach dir, $(OBJECT_DIRS), $(shell mkdir -p ./objects/$(dir)))
	
	
# (Linux Compilers)

linux: LINUX_COMPILE LINUX_LINK

LINUX_COMPILE:
	@echo "Compiling..."
	@$(foreach source, $(SOURCES), $(shell $(LINUX_COMPILER) $(L_FLAGS) $(L_COMPILER_FLAGS) $(FRAMEWORK_VER_FLAGS) $(SRC_FOLDER)/$(source) -o ./objects/$(source).o &> results.txt ))
	@echo "Compiled."
	
LINUX_LINK:
	@echo "Linking..."
	@$(LINUX_COMPILER) $(OBJECTS) $(L_FLAGS) $(L_LINKER_FLAGS) -shared -o $(PROJECT_EXECUTABLE)
	@echo "Linked."
	
clean:
	@rm -f -r ./objects
	@rm -f $(PROJECT_EXECUTABLE)

