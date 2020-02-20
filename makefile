 
main: main.cpp imports.h
	g++ -o main main.cpp imports.h
clean:
	rm *.o main