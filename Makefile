FLAGS = -pedantic-errors -std=c++11

Unomain.o: Unomain.cpp Unomain.h
	g++ $(FLAGS) -c Unomain.cpp
MainMenu.o: MainMenu.cpp Unomain.h
	g++ $(FLAGS) -c MainMenu.cpp
MainMenu: MainMenu.o Unomain.o
	g++ $(FLAGS) MainMenu.o Unomain.o -o MainMenu
clean:
	rm -f MainMenu.o Unomain.o
.PHONY: clean
