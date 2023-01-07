all: clear clean compile run

clear:
	@clear

clean:
	@rm -rf *.o a.out

compile: Gate.o Input.o Output.o And.o Not.o Or.o FlipFlop.o Decoder.o Circuit.o main.o
	@g++ Gate.o Input.o Output.o And.o Not.o Or.o FlipFlop.o Decoder.o Circuit.o main.o -std=c++11

run:
	@./a.out

Gate.o: Gate.cpp
	@g++ -c Gate.cpp -std=c++11

Input.o: Input.cpp
	@g++ -c Input.cpp -std=c++11

Not.o: Not.cpp
	@g++ -c Not.cpp -std=c++11

Output.o: Output.cpp
	@g++ -c Output.cpp -std=c++11

And.o: And.cpp
	@g++ -c And.cpp -std=c++11

Or.o: Or.cpp
	@g++ -c Or.cpp -std=c++11

FlipFlop.o: FlipFlop.cpp
	@g++ -c FlipFlop.cpp -std=c++11

Decoder.o: Decoder.cpp
	@g++ -c Decoder.cpp -std=c++11

Circuit.o: Circuit.cpp
	@g++ -c Circuit.cpp -std=c++11

main.o: main.cpp
	@g++ -c main.cpp -std=c++11