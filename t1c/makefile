all: encoder

encoder: encoder.o 
	@echo 'Building target: encoder'
	@echo 'Invoking: C Linker'
	gcc -g -Wall -o encoder  encoder.o
	@echo 'Finished building target: encoder'
	@echo ' '

encoder.o: encoder.c
	gcc -g -Wall -c -o encoder.o encoder.c

.PHONY: clean
clean:
	rm -f *.o encoder
