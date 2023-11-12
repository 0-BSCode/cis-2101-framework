#include "modules/double-pointer/v2/_header.h"
#include <stdio.h>

int main() {
    BST B;
    initialize(&B);

    insert(&B, 'I');
    insert(&B, 'C');
    insert(&B, 'L');
    insert(&B, 'M');
    insert(&B, 'Q');
    insert(&B, 'B');
    insert(&B, 'U');
    insert(&B, 'C');
    insert(&B, 'J');
    insert(&B, 'F');
    insert(&B, 'D');
    insert(&B, 'G');

    printf("\n----- PRE-ORDER -----\n");
    preOrderWalk(B);

    printf("\n----- IN-ORDER -----\n");
    inOrderWalk(B);

    printf("\n----- POST-ORDER -----\n");
    postOrderWalk(B);

    delete(&B, 'I');
    delete(&B, 'C');
    delete(&B, 'B');
    delete(&B, 'U');

    printf("\n----- PRE-ORDER -----\n");
    preOrderWalk(B);

    printf("\nMin: %c\n", min(B));
    printf("Max: %c\n", max(B));

    return 0;
}