# All Targets

all: encoder

# Tool invocations
# Executable "encoder" depends on the files hello.o and run.o.

encoder: encoder.o
	@echo 'Building target: encoder'
	@echo 'Invoking: C Linker'
	gcc -o encoder encoder.o
	@echo 'Finished building target: encoder'
	@echo ' '

# Depends on the source and header files
bin/encoder.o: src/encoder.c
	gcc -g -Wall -c -o encoder.o encoder.c

#Clean the build directory
clean:
	rm -f *.o encoder
