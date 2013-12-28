MODE=DEBUG
CC=g++
CFLAGS=-std=c++0x
LDFLAGS=
PATHEXEC=bin/
EXEC=inherit
SRC=insaInherit.cpp Point.cpp Circle.cpp Line.cpp Polyline.cpp Rectangle.cpp AO.cpp
OBJ=$(SRC:.cpp=.o)

ifeq ($(MODE),DEBUG)
	CFLAGS:=$(CFLAGS) -g
endif

all: $(EXEC)

inherit: $(OBJ)
	$(CC) -o ${PATHEXEC}$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Point.o: Point.h

Circle.o: Circle.h GeoElt.h Point.h

Line.o: Line.h GeoElt.h Point.h

Polyline.o: Polyline.h GeoElt.h Point.h

Rectangle.o: Rectangle.h GeoElt.h Polyline.h

AO.o: GeoElt.h

#test: $(EXEC)
#	@make -C Tests

clean:
	@rm -rf *.o
#	@make clean -C Tests

mrproper: clean
	@rm -rf $(EXEC)
