CXX=clang++

CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

BINARIES=lab07Test

all: ${BINARIES}

lab07Test: lab07Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

lab07Test.o: lab07Test.cpp WordCount.h tddFuncs.h
	${CXX} ${CXXFLAGS} -c lab07Test.cpp

WordCount.o: WordCount.cpp WordCount.h
	${CXX} ${CXXFLAGS} -c WordCount.cpp

tddFuncs.o: tddFuncs.cpp tddFuncs.h
	${CXX} ${CXXFLAGS} -c tddFuncs.cpp

tests: ${BINARIES}
	./lab07Test

clean:
	/bin/rm -f ${BINARIES} *.o