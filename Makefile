.PHONY: clean

all: main.out

main.out:
	g++ -std=c++17 main.cpp -o main.out

clean:
	rm -rf main.out
	rm -rf output.txt
	rm -rf main