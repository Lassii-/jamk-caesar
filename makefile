OBJS = main.cpp
OBJ_NAME = caesar
OPT_LEVEL = -O2

all: $(OBJS)
	g++ $(OBJS) $(OPT_LEVEL) -o $(OBJ_NAME)
