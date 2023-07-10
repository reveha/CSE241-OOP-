all: clean compile run

compile: main.cpp world.cpp Robot.cpp humanic.cpp robocop.cpp optimusprime.cpp bulldozer.cpp roomba.cpp
	@echo "COMPILING TEST DRIVER..."
	@g++ -std=c++11 main.cpp world.cpp Robot.cpp humanic.cpp robocop.cpp optimusprime.cpp bulldozer.cpp roomba.cpp -o test
 
run:
	@echo "-------------------------------------------"
	@./test

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
