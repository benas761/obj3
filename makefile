
main: main.cpp gradeGen.cpp inOut.cpp classfuncs.cpp imports.h
	g++ -o main main.cpp gradeGen.cpp inOut.cpp classfuncs.cpp imports.h
	
clean:
	rm *.o main results.txt *.txt