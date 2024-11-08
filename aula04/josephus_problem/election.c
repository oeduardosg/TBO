#include "election.h"
#include <stdlib.h>

typedef struct cell cell;

struct cell {
    int person_number;
    cell next;
};

typedef struct {
    cell * first;
    cell * last;
} circular_list;

circular_list * create_list() {

    circular_list * list = (circular_list *) calloc(1, sizeof(circular_list));

    list -> first = NULL;
    list -> last = NULL;

return list;
}

int list_election(int n_people, int m_elimination) {

    circular_list * list = create_list();

    //add each cell based on the number of people

}

int array_election(int n_people, int m_elimination) {



}
