OBJS = main.cpp
OBJ_NAME = caesar

all: $(OBJS)
	g++ $(OBJS) -O2 -o $(OBJ_NAME)
