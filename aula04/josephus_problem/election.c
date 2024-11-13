#include "election.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct cell cell;

struct cell {
    int person_number;
    cell * next;
};

typedef struct {
    cell * first;
    cell * last;
    int size;
} circular_list;

cell * create_cell(int person_number) {

    cell * c = (cell *) calloc(1, sizeof(cell));
    c -> person_number = person_number;
    c -> next = NULL;

return c;
}

void set_next(cell * c, cell * n) {
    c -> next = n;
}


circular_list * create_list() {

    circular_list * list = (circular_list *) calloc(1, sizeof(circular_list));

    list -> first = NULL;
    list -> last = NULL;

return list;
}

void insert_cell(circular_list * list, int person_num) {

    cell * nc = create_cell(person_num);

    if(!list -> first && !list -> last) {
        list -> first = nc;
        list -> last = nc;
    }
    else {
        set_next(list -> last, nc);
        list -> last = nc;
        set_next(list -> last, list -> first);
    }

    list -> size++;

}

void remove_cell(circular_list * list, int num) {

    cell * lc = NULL;
    cell * c = list -> first;

    for(int i = 1; i < num; i++) {
        lc = c;
        c = c -> next;
    }

    lc -> next = c -> next;
    list -> last = lc;
    list -> first = c -> next;

    free(c);
    list -> size--;

}

int list_election(int n_people, int m_elimination) {

    circular_list * list = create_list();

    for(int i = 0; i < n_people; i++) {
        insert_cell(list, i+1);
    }

    while(list -> size > 1) {
        remove_cell(list, m_elimination);
    }

    printf("%d", list -> first -> person_number);

    free(list -> first);
    free(list);

}

int array_election(int n_people, int m_elimination) {

    int * election = (int *) calloc(n_people, sizeof(int));
    int runner = 0, candidates = n_people, counter = m_elimination;

    while(candidates > 1) {
        while(1) {
            if(!election[runner]) counter--; 
            if(!counter) break;
            runner++;
            if(runner == n_people) runner = 0;
        }
        counter = m_elimination;
        election[runner] = 1;
        candidates--;
    }

    for(int i = 0; i < n_people; i++) {
        if(!election[i]) printf("%d", i+1);
    }

}
