CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
LDLIBS = -lncurses
EXEC = main
SRC = src
SOURCES = $(wildcard $(SRC)/*.cc) $(wildcard $(SRC)/*/*.cc)
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${LDLIBS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
