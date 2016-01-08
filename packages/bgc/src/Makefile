all : ../test2.epbc ../libbgc.a

../test2.epbc : main.cpp
	clang++ -std=c++11 -emit-llvm -fno-use-cxa-atexit -I../../../build/header -c main.cpp -o ../bgc.epbc

../libbgc.a : bgc.o
	ar rcs $@ $^

bgc.o : runtime.cpp
	clang++ -std=c++11 -I../../../extlib/include -c runtime.cpp -o bgc.o
