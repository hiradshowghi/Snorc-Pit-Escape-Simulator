OPT = -Wall -std=c++11

escape: main.o Escape.o Hero.o PartArray.o Participant.o Pit.o Position.o random.o Snorc.o
	g++ $(OPT) -o escape main.o Escape.o Hero.o PartArray.o Participant.o Pit.o Position.o random.o Snorc.o

main.o: main.cc Escape.h
	g++ $(OPT) -c main.cc

Escape.o: Escape.cc Escape.h PartArray.h Pit.h Hero.h Snorc.h Participant.h defs.h
	g++ $(OPT) -c Escape.cc

Hero.o: Hero.cc Hero.h Participant.h Position.h defs.h
	g++ $(OPT) -c Hero.cc

PartArray.o: PartArray.cc PartArray.h Participant.h
	g++ $(OPT) -c PartArray.cc

Participant.o: Participant.cc Participant.h Position.h defs.h
	g++ $(OPT) -c Participant.cc

Pit.o: Pit.cc Pit.h Position.h defs.h
	g++ $(OPT) -c Pit.cc

Position.o: Position.cc Position.h defs.h
	g++ $(OPT) -c Position.cc

random.o: random.cc defs.h
	g++ $(OPT) -c random.cc

Snorc.o: Snorc.cc Snorc.h Participant.h Position.h defs.h
	g++ $(OPT) -c Snorc.cc

clean:
	rm -f *.o escape
