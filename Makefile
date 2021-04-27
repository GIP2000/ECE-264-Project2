.PHONY: clean

all: main.out

main.out:
	g++ -std=c++17 main.cpp -o main.out

main2.out:
	g++ main2.cpp -o main2.out

clean:
	rm -rf main.out
	rm -rf output.txt
	rm -rf main
	rm -rf main2
	rm -rf main2.out