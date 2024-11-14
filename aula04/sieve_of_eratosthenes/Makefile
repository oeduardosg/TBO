run-int:
	clear
	gcc -o test bitmap.c int_main.c sieve.c
	./test

run-char:
	clear
	gcc -o test bitmap.c char_main.c sieve.c 
	./test

run-bit:
	clear
	gcc -o test bitmap.c bit_main.c sieve.c
	./test

valgrind-int:
	clear
	gcc -o test bitmap.c int_main.c sieve.c
	valgrind --leak-check=full ./test

valgrind-char:
	clear
	gcc -o test bitmap.c char_main.c sieve.c
	valgrind --leak-check=full ./test

valgrind-bit:
	clear
	gcc -o test bitmap.c bit_main.c sieve.c
	valgrind --leak-check=full ./test