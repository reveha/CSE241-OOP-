all: clean compile run

compile: main.cpp util.hpp 
	@echo "COMPILING  CODE..."
	@g++ -o test main.cpp 
 
run:
	@echo "-------------------------------------------"
	@echo "Running CODE...\n"
	@./test

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
