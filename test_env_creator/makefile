# OBJS specifies which files to compile as part of the project
OBJS = src/create_test_env.cpp src/dir_obj.cpp src/file_obj.cpp

# CC specifies which compiler we're using
CC = g++

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#COMPILER_FLAGS = -w
# we're not suppressing warnings with this one.

# LINKER_FLAGS specifies the libraries we're linking against
#LINKER_FLAGS = -sdl2
# no linkers needed for this project.

# OBJ_NAME specifies the name of our executable
OBJ_NAME = create_test_env

# This is the target that compiles our executable
all : $(OBJS)
		$(CC) $(OBJS) -o $(OBJ_NAME)
