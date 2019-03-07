OBJS = main.cpp
CC = g++
COMPILER_FLAGS = -Wall -Wpedantic
OBJ_NAME = videos.out

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
testing: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -ggdb -o $(OBJ_NAME)
