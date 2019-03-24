CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
0;136;0cDEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

skipbo: main.o SkipBoGame.o gamefunc.o Pile.o FaceUpPile.o BuildPile.o Card.o DrawPile.o Player.o PlayPile.o StockPile.o DiscardPile.o Hand.o
	g++ $(CFLAGS) -o skipbo main.o SkipBoGame.o gamefunc.o Pile.o FaceUpPile.o BuildPile.o Card.o DrawPile.o Player.o PlayPile.o StockPile.o DiscardPile.o Hand.o

all: main.o SkipBoGame.o gamefunc.o Pile.o FaceUpPile.o BuildPile.o Card.o \
DrawPile.o Player.o PlayPile.o StockPile.o DiscardPile.o Hand.o

main.o: main.cpp Card.h Pile.h SkipBoGame.h gamefunc.h
	g++ $(CFLAGS) -c main.cpp

SkipBoGame.o: SkipBoGame.cpp SkipBoGame.h Player.h StockPile.h BuildPile.h DrawPile.h Pile.h
	g++ $(CFLAGS) -c SkipBoGame.cpp

gamefunc.o: gamefunc.cpp gamefunc.h
	g++ $(CFLAGS) -c gamefunc.cpp

Pile.o: Pile.cpp Pile.h Card.h
	g++ $(CFLAGS) -c Pile.cpp

FaceUpPile.o: FaceUpPile.cpp FaceUpPile.h Card.h Pile.h
	g++ $(CFLAGS) -c FaceUpPile.cpp

BuildPile.o: BuildPile.cpp BuildPile.h FaceUpPile.h
	g++ $(CFLAGS) -c BuildPile.cpp

Card.o: Card.cpp Card.h
	g++ $(CFLAGS) -c Card.cpp

DrawPile.o: DrawPile.cpp DrawPile.h Card.h Pile.h
	g++ $(CFLAGS) -c DrawPile.cpp

Player.o: Player.h Player.cpp Hand.h StockPile.h DiscardPile.h Pile.h StockPile.h Hand.h DiscardPile.h
	g++ $(CFLAGS) -c Player.cpp

PlayPile.o: PlayPile.h PlayPile.cpp FaceUpPile.h
	g++ $(CFLAGS) -c PlayPile.cpp

StockPile.o: StockPile.h StockPile.cpp PlayPile.h
	g++ $(CFLAGS) -c StockPile.cpp

DiscardPile.o: DiscardPile.h DiscardPile.cpp PlayPile.h
	g++ $(CFLAGS) -c DiscardPile.cpp

Hand.o: Hand.cpp Hand.h FaceUpPile.h
	g++ $(CFLAGS) -c Hand.cpp

clean:
	rm -f *.o skipbo *~
