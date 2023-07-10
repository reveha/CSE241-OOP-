all: clean compile run

compile: driver.cpp util.cpp
	@echo "COMPILING TEST DRIVER..."
	@g++ -o test driver.cpp util.cpp -std=c++11
 
run:
	@echo "-------------------------------------------"
	@echo "Running DRIVER TEST CODE..."
	@./test

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
