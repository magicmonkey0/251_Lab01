#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, week.o, and slotRange.o to executable main
main: main.o week.o slotRange.o
	g++ -g -o main main.o week.o slotRange.o

#compile the main.cpp to main.o
main.o: main.cpp week.hpp slotRange.hpp
	g++ -g -c main.cpp

#compile the week.cpp to week.o
week.o: week.cpp week.hpp
	g++ -g -c week.cpp

#compile the date.cpp to slotRange.o
slotRange.o: slotRange.cpp slotRange.hpp
	g++ -g -c slotRange.cpp

#remove built files
clean:
	rm -rf main main.o week.o slotRange.o *~
