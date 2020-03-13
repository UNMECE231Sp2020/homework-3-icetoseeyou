all: main.o GeneralList.o

	g++ main.o GeneralList.o -o run_tests_run

main.o: main.cpp GeneralList.hpp 

	g++ -c main.cpp

GeneralLists.o: GeneralList.hpp

	g++ -c GeneralList.hpp 	

clean: 

	rm *.o

	rm run_tests_run
