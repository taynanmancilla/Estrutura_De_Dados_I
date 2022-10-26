SRC = ./src
INCLUDE = ./include
BIN = ./bin
APPS = ./apps
OBJ = ./obj

all: libed myapps

libed: $(OBJ)/float_vector.o

myapps:
	gcc $(APPS)/tad.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

run:
	./bin/app

clean:
	rm -rf ./bin/* ./obj/*
	