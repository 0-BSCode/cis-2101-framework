#include "modules/linked-list/v3/_header.h"
#include <stdio.h>

int main() {

    QUEUE Q;
    initialize(&Q);

    enqueue('S', &Q);
    enqueue('C', &Q);
    enqueue('O', &Q);
    enqueue('O', &Q);
    enqueue('B', &Q);
    enqueue('Y', &Q);
    displayList(&Q);

    insertFront('A', &Q);

    displayList(&Q);

    insertAtPos(3, 'Z', &Q);

    dequeue(&Q);
    displayList(&Q);

    printf("Top: %c\n", front(Q));
    return 0;
}