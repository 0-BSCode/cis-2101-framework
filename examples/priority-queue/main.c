#include "modules/heap/v1/_header.h"

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

    HEAP list;
    initialize(&list);
    insertList(&list, 7);
    insertList(&list, 5);
    insertList(&list, 4);
    insertList(&list, 3);
    insertList(&list, 6);
    insertList(&list, 2);
    insertList(&list, 1);
    insertList(&list, 8);
    insertList(&list, 1);

    displayHeap(list);

    buildMinHeap(&list);
    displayHeap(list);

    heapSort(&list);
    displayHeap(list);
}