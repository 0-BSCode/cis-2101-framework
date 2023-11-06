#include "modules/linked-list/v1/_header.h"
#include <stdio.h>

int main() {
    DICT D;

    initialize(&D);
    insertMember(&D, 3);
    insertMember(&D, 5);
    insertMember(&D, 33);
    insertMember(&D, 99);
    // deleteMember(&D, 3);
    displayDict(D);

    int member = 33;
    printf("Is %d member: %d\n", member, isMember(D, member));

    return 0;
}