all: clean compile run

compile: main.cpp Catalog.cpp Music.cpp Movie.cpp Book.cpp WrongCommandException.cpp DuplicateException.cpp MissingFieldException.cpp
	@echo "COMPILING TEST DRIVER..."
	@g++ -std=c++11 main.cpp Catalog.cpp Music.cpp Movie.cpp Book.cpp WrongCommandException.cpp DuplicateException.cpp MissingFieldException.cpp -o test
	
 
run:
	@echo "-------------------------------------------"
	@./test

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
