CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
SRC = src/engine
GAME1 = src/arlg
GAME2 = src/snake
CONFIG = src/config

SOURCES = $(shell find $(SRC) -name '*.cc')
CONFIG_SOURCES = $(shell find $(CONFIG) -name '*.cc')
GAME1_SOURCES = $(shell find $(GAME1) -name '*.cc')
GAME2_SOURCES = $(shell find $(GAME2) -name '*.cc')
OBJECTS = ${SOURCES:.cc=.o}
CONFIG_OBJECTS = ${CONFIG_SOURCES:.cc=.o}
GAME1_OBJECTS = ${GAME1_SOURCES:.cc=.o}
GAME2_OBJECTS = ${GAME2_SOURCES:.cc=.o}
DEPENDS = ${OBJECTS:.o=.d}
CONFIG_DEPENDS = ${CONFIG_OBJECTS:.o=.d}
GAME1_DEPENDS = ${GAME1_OBJECTS:.o=.d}
GAME2_DEPENDS = ${GAME2_OBJECTS:.o=.d}

all: game1 game2

game1: $(OBJECTS) $(CONFIG_OBJECTS) $(GAME1_OBJECTS)
	$(CXX) $(OBJECTS) $(CONFIG_OBJECTS) $(GAME1_OBJECTS) -o game1 -lncurses

-include ${DEPENDS} $(CONFIG_DEPENDS) $(GAME1_DEPENDS)

game2: $(OBJECTS) $(CONFIG_OBJECTS) $(GAME2_OBJECTS)
	$(CXX) $(OBJECTS) $(CONFIG_OBJECTS) $(GAME2_OBJECTS) -o game2 -lncurses

-include ${DEPENDS} $(CONFIG_DEPENDS) $(GAME2_DEPENDS)

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${CONFIG_OBJECTS} ${CONFIG_DEPENDS} ${GAME1_OBJECTS} ${GAME1_DEPENDS} ${GAME2_OBJECTS} ${GAME2_DEPENDS} game1 game2
