all:encoder

encoder:encoder.o
	@echo 'Building target: hello'
	@echo 'Invoking: C Linker'
	gcc -g -Wall -o encoder encoder.o
	@echo 'Finished building target: hello'
	@echo ' '
encoder.o: encoder.c
	gcc -g -Wall -c -o encoder.o encoder.c

clean:
	rm encoder.o encoder

