all: main.o

	g++ main.o -o run_tests_run

main.o: main.cpp GeneralList.hpp 

	g++ -c main.cpp


clean: 

	rm *.o

	rm run_tests_run
