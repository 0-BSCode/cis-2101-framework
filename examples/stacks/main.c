#include "modules/array/v3/_header.h"
#include <stdio.h>

int main() {
    STACK S;

    initialize(&S);
    push('S', &S);
    push('C', &S);
    push('O', &S);
    push('O', &S);
    push('B', &S);
    insertBottom('Y', &S);

    displayStack(&S);

    printf("%c\n", top(S));
    pop(&S);
    printf("%c\n", top(S));

    return 0;
}