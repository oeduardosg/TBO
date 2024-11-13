#include <stdio.h>
#include "election.h"

int main() {

    int nPeople, mElimination;

    scanf("%d %d", &nPeople, &mElimination);

    array_election(nPeople, mElimination);

return 0;
}