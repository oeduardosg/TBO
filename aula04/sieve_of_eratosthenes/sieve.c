#include "sieve.h"
#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

void print_int_primes(int * prime, int qtt) {

    for(int i = 2; i < qtt; i++) {
        if(!prime[i]) printf("%d ", i);
    }

}

void print_char_primes(char * prime, int qtt) {

    for(int i = 2; i < qtt; i++) {
        if(!prime[i]) printf("%d ", i);
    }

}

void print_bit_primes(bitmap * prime, int qtt) {

    for(int i = 2; i < qtt; i++) {
        if(!bitmapGetBit(prime, i)) printf("%d ", i);
    }

}
void int_sieve(int qtt, int print) {

    int * prime = (int *) calloc(qtt + 1, sizeof(int));

    for(int i = 2; i <= qtt; i++) {
        if(prime[i] == 0) {
            if(i * i > qtt) break;
            for(int j = i * 2; j < qtt; j += i) {
                prime[j] = 1;
            }
        }
    }

    if(print) print_int_primes(prime, qtt);

    free(prime);

}

void char_sieve(int qtt, int print) {

    char * prime = (char *) calloc(qtt + 1, sizeof(char));

    for(int i = 2; i <= qtt; i++) {
        if(prime[i] == 0) {
            if(i * i > qtt) break;
            for(int j = i; j * i < qtt; j++) {
                prime[j * i] = 1;
            }
        }
    }

    if(print) print_char_primes(prime, qtt);

    free(prime);

}

void bit_sieve(int qtt, int print) {

    bitmap * bm = bitmapInit(qtt + 1);
    bitmapSetLength(bm, qtt + 1);

    for(int i = 2; i <= qtt; i++) {
        if(bitmapGetBit(bm, i) == 0) {
            if(i * i > qtt) break;
            for(int j = i; j * i < qtt; j++) {
                bitmapSetBit(bm, j * i, 1);
            }
        }
    }

    if(print) print_bit_primes(bm, qtt);

    bitmapLibera(bm);


}