MODE=DEBUG
CC=g++
CFLAGS=-std=c++11
LDFLAGS=
EXEC=inherit
SRC=
OBJ=$(SRC:.cpp=.o)

ifeq ($(MODE),DEBUG)
	CFLAGS:=$(CFLAGS) -g
endif

all: $(EXEC)

inherit: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

#test: $(EXEC)
#	@make -C Tests

clean:
	@rm -rf *.o
#	@make clean -C Tests

mrproper: clean
	@rm -rf $(EXEC)
