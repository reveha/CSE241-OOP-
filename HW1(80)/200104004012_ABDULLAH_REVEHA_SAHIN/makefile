all: clean compile run

compile: main.cpp util.cpp util.hpp
	@echo "Compiling..."
	@g++ -o test main.cpp util.cpp

run:
	@echo "-------------------------------------------"
	@echo "Running..."
	@./test

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
