PROJ_NAME = Nim
OBJS = main.o board.o player.o
CFLAGS = -std=c++11

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	g++ $(CFLAGS) -o $(PROJ_NAME) $(OBJS)

main.o: main.cpp board.h player.h
	g++ $(CFLAGS) -c main.cpp

board.o: board.cpp board.h
	g++ $(CFLAGS) -c board.cpp

player.o: player.cpp player.h
	g++ $(CFLAGS) -c player.cpp

.PHONY: test clean

test: $(PROJ_NAME)
	./$(PROJ_NAME)

clean:
	rm -f $(PROJ_NAME) $(OBJS)