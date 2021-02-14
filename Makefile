CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = BlackJack.o Deck.o Card.o Table.o

BlackJack: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o BlackJack