all: clean compile run

compile: driver1.cpp driver2.cpp util.cpp driver1.hpp driver2.hpp
	@echo "COMPILING TEST DRIVER..."
	@g++ driver1.cpp util.cpp -o test1
	@echo "COMPILING ANIMATION DRIVER..."
	@g++ driver2.cpp util.cpp -o test2
 
run:
	@echo "-------------------------------------------"
	@echo "Running DRIVER TEST CODE..."
	@./test1
	@echo "\n-----------DRIVER TEST OUTPUT IS ABOVE-----------\n\n"
	@echo "-------------------------------------------"
	@echo "Running ANIMATION GAME CODE...\n"
	@./test2

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test1
	@rm -f test2
