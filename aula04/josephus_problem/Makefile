run-list:
	clear
	gcc -o test list_main.c election.c
	./test

run-array:
	clear
	gcc -o test array_main.c election.c
	./test

valgrind-list:
	clear
	gcc -o test list_main.c election.c
	valgrind --leak-check=full ./test

valgrind-array:
	clear
	gcc -o test array_main.c election.c
	valgrind --leak-check=full ./test
