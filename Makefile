# =====
# INSA Lyon, Département Informatique
# TP C++ 3IF :  Héritage et polymorphisme
# Auteur : B3229
# =====

include Config.mk

SRC=insaInherit.cpp Model.cpp Point.cpp Circle.cpp Line.cpp Polyline.cpp Rectangle.cpp Agregated.cpp Command.cpp AddCommand.cpp DeleteCommand.cpp MoveCommand.cpp FileCommand.cpp Controller.cpp Interpreter.cpp Executor.cpp
OBJ=$(SRC:.cpp=.o)

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

Rectangle.o: Rectangle.h GeoElt.h

Agregated.o: Agregated.h GeoElt.h

Command.o: Command.h GeoElt.h Model.h

AddCommand.o: AddCommand.h Command.h

DeleteCommand.o: DeleteCommand.h Command.h

MoveCommand.o: MoveCommand.h Command.h

FileCommand.o: FileCommand.h Command.h

Controller.o: Controller.h Config.h Model.h Command.h

Interpreter.o: Interpreter.h

Executor.o: Executor.h Config.h Interpreter.h Controller.h Circle.h Line.h Polyline.h Rectangle.h Agregated.h

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	@make -C tests

clean:
	@rm -rf *.o
	@make clean -C tests

mrproper: clean
	@rm -rf $(TARGET)
