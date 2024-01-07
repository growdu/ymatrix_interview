all:
	gcc -g -O0 src/task1.c -o bin/task1
	gcc -g -O0 src/task2.c -o bin/task2
	gcc -g -O0 src/task3.c -o bin/task3
clean:
	rm -rf bin/*
