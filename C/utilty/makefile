SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
CC = gcc

ALL : clean putil
 
putil : $(OBJ)
	echo $(OBJ)
	$(CC) $^ -o $@
 
%.o : %.c
	$(CC) -c $< -o $@

clean :
	rm *.o -f
	rm project -f