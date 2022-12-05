main.out : tamagotchi.o ui.o main.o
	g++ tamagotchi.o ui.o main.o -o main.out

main.o: ui.h ui.cpp tamagotchi.h tamagotchi.cpp
	g++ -c main.cpp

tamagotchi.o: tamagotchi.h tamagotchi.cpp
	g++ -c tamagotchi.cpp

ui.o: ui.h ui.cpp
	g++ -c ui.cpp

clean:
	rm -f *.o