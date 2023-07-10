all: clean compile run

compile: 
	@echo "COMPILING TEST DRIVER..."
	@javac driver2.java
	@echo "COMPILING ANIMATION DRIVER..."
	@javac driver1.java
 
run:
	@echo "-------------------------------------------"
	@echo "Running DRIVER TEST CODE..."
	@java driver2
	@echo "\n-----------DRIVER TEST OUTPUT IS ABOVE-----------\n\n"
	@echo "-------------------------------------------"
	@echo "Running ANIMATION GAME CODE...\n"
	@java driver1

clean:
	@echo "Removing compiled files..."
	@rm -f *.class
