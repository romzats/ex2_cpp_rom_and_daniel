CC = g++
CFLAGS = -Wvla -Werror -Wall -Wextra -g -std=c++17 -DNDEBUG
BOARDFILES =  Board.h Board.cpp
MANFILES =  Chessmen.h Chessmen.cpp
PLAYERFILES =  Player.h Player.cpp
CHESSFILES =  chess.h chess.cpp
SETFILES = Chessmen.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o Player.o Board.o chess.o
TARFILES = makefile *.h *.cpp


# All Target
all: chess

# main
chess: $(SETFILES)
	$(CC) $(SETFILES) -o chess

# Executables

Chessmen.o: $(MANFILES)
	$(CC) $(CFLAGS) Chessmen.cpp -c


# individual chessmen classes

King.o: Chessmen.h King.cpp King.h
	$(CC) $(CFLAGS) King.cpp -c

Queen.o: Chessmen.h Queen.cpp Queen.h
	$(CC) $(CFLAGS) Queen.cpp -c

Rook.o: Chessmen.h Rook.cpp Rook.h
	$(CC) $(CFLAGS) Rook.cpp -c

Bishop.o: Chessmen.h Bishop.cpp Bishop.h
	$(CC) $(CFLAGS) Bishop.cpp -c

Knight.o: Chessmen.h Knight.cpp Knight.h
	$(CC) $(CFLAGS) Knight.cpp -c

Pawn.o: Chessmen.h Pawn.cpp Pawn.h
	$(CC) $(CFLAGS) Pawn.cpp -c


Player.o: $(MANFILES) $(PLAYERFILES)
	$(CC) $(CFLAGS) Player.cpp -c

Board.o: $(MANFILES) $(PLAYERFILES) $(BOARDFILES)
	$(CC) $(CFLAGS) Board.cpp -c

chess.o: $(MANFILES) $(PLAYERFILES) $(BOARDFILES) $(CHESSFILES)
	$(CC) $(CFLAGS) chess.cpp -c






# tar
tar:
	tar -cvf ex2.tar $(TARFILES)

# Clean
clean:
	-rm -f chess.o Board.o Chessmen.o Player.o ex2

# valgrind
valdb.out: ex2
	valgrind --leak-check=full --show-possibly-lost=yes --show-reachable=yes \
	--undef-value-errors=yes  --track-origins=yes ./ex2


# PHONY
.PHONY: clean
