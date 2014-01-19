# =====
# INSA Lyon, Département Informatique
# TP C++ 3IF :  Héritage et polymorphisme
# Auteur : B3229
# =====

MODE=DEBUG
CC=g++
CFLAGS=-std=c++0x
LDFLAGS=
PATHEXEC=bin/
EXEC=inherit
TARGET=$(addprefix $(PATHEXEC), $(EXEC))
SRC=insaInherit.cpp Model.cpp Point.cpp Circle.cpp Line.cpp Polyline.cpp Rectangle.cpp AO.cpp Command.cpp AddCommand.cpp DeleteCommand.cpp MoveCommand.cpp FileCommand.cpp Controller.cpp Interpreter.cpp Executor.cpp
OBJ=$(SRC:.cpp=.o)

ifeq ($(MODE),DEBUG)
	CFLAGS:=$(CFLAGS) -g
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(PATHEXEC)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Model.o: Model.h GeoElt.h

Point.o: Point.h

Circle.o: Circle.h GeoElt.h Point.h

Line.o: Line.h GeoElt.h Point.h

Polyline.o: Polyline.h GeoElt.h Point.h

Rectangle.o: Rectangle.h GeoElt.h Polyline.h

AO.o: AO.h GeoElt.h

Command.o: Command.h GeoElt.h Model.h

AddCommand.o: AddCommand.h Command.h

DeleteCommand.o: DeleteCommand.h Command.h

MoveCommand.o: MoveCommand.h Command.h

FileCommand.o: FileCommand.h Command.h

Controller.o: Controller.h Config.h Command.h

Interpreter.o: Interpreter.h

Executor.o: Executor.h Config.h Controller.h

#test: $(EXEC)
#	@make -C Tests

clean:
	@rm -rf *.o
#	@make clean -C Tests

mrproper: clean
	@rm -rf $(PATHEXEC)
