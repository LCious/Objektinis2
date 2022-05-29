main: functions.o
	g++ -o main main.cpp functions.o
	
funckijos:
	g++ -c functions.cpp
del:
	rm *.o main