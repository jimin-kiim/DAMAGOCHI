main.out : tamagotchi.o ui.o main.o studyingGame.o
	g++ tamagotchi.o ui.o main.o studyingGame.o -o main.out

main.o: ui.h ui.cpp tamagotchi.h tamagotchi.cpp studyingGame.h studyingGame.cpp
	g++ -c main.cpp

tamagotchi.o: tamagotchi.h tamagotchi.cpp
	g++ -c tamagotchi.cpp

ui.o: ui.h ui.cpp
	g++ -c ui.cpp

studyingGame.o: studyingGame.h studyingGame.cpp
	g++ -c studyingGame.cpp

clean:
	rm -f *.o