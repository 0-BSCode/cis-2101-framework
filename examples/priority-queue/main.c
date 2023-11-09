#include "modules/heap/v2/_header.h"

int main() {
    HEAP H;
    initialize(&H);

    insert(&H, 1);
    insert(&H, 6);
    insert(&H, 3);
    insert(&H, 5);
    insert(&H, 8);
    insert(&H, 4);
    insert(&H, 7);
    insert(&H, 2);

    displayHeap(H);

    deleteMin(&H);
    displayHeap(H);

    makeNull(&H);
    displayHeap(H);
}