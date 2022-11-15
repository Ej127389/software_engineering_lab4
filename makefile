main: main.o create_OJ_input.o OJ_running.o Get_filename.o Equivalence_Judge.o
	g++ -std=c++11 -o main main.o create_OJ_input.o OJ_running.o Get_filename.o Equivalence_Judge.o

main.o: main.cpp
	g++ -std=c++11 -c -o main.o main.cpp
create_OJ_input.o: create_OJ_input.cpp
	g++ -std=c++11 -c -o create_OJ_input.o create_OJ_input.cpp
OJ_running.o: OJ_running.cpp
	g++ -std=c++11 -c -o OJ_running.o OJ_running.cpp
Get_filename.o: Get_filename.cpp
	g++ -std=c++11 -c -o Get_filename.o Get_filename.cpp
Equivalence_Judge.o: Equivalence_Judge.cpp
	g++ -std=c++11 -c -o Equivalence_Judge.o Equivalence_Judge.cpp

clean: 
	rm *.o main *.csv *.txt