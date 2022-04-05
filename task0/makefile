
all: exec

exec: my_echo.o numbers.o
	gcc -g -Wall -o task0 my_echo.o numbers.o 

echo.o: echo.c
	gcc -c -Wall -o my_echo.o my_echo.c

numbers.o: numbers.c
	gcc -c -Wall -o numbers.o numbers.c


.PHONY: clean

clean:
	rm -f *.o task0
 
