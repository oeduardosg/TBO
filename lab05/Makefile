run:
	clear
	gcc -o test main.c merge_v$(v).c
	./test

valgrind:
	clear
	gcc -o test main.c
	valgrind ./test merge_v$(v).c