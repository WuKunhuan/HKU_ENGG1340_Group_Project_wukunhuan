FLAGS = -pedantic-errors -std=c++11

Unomain.o: Unomain.cpp Unomain.h
	g++ $(FLAGS) -c Unomain.cpp

_24Cal_main.o: _24Cal_main.cpp _24Cal_main.h
	g++ $(FLAGS) -c _24Cal_main.cpp


MainMenu.o: MainMenu.cpp Unomain.h _24Cal_main.h
	g++ $(FLAGS) -c MainMenu.cpp
MainMenu: MainMenu.o Unomain.o _24Cal_main.o
	g++ $(FLAGS) MainMenu.o Unomain.o _24Cal_main.o -o MainMenu


clean:
	rm -f MainMenu.o Unomain.o _24Cal_main.o
.PHONY: clean
