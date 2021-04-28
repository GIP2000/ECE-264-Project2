.PHONY: clean

all: main.out

main.out:
	g++ main.cpp -o main.out

clean:
	rm -rf main.out
	rm -rf main