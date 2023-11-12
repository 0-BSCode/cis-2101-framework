#include "_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(BST *B) {
    *B = NULL;
}

void insert(BST *B, char elem) {
    BST *trav;

    for (trav = B; *trav != NULL && elem != (*trav)->data;) {
        trav = elem > (*trav)->data ? &(*trav)->RC : &(*trav)->LC;
    }

    if (*trav == NULL) {
        BST node = (BST)malloc(sizeof(Node));

        if (node != NULL) {
            node->data = elem;
            node->LC = NULL;
            node->RC = NULL;

            *trav = node;
        }
    }
}

bool isMember(BST B, char elem) {
    BST trav;

    for (trav = B; trav != NULL && elem != trav->data;) {
        trav = elem > trav->data ? trav->RC : trav->LC;
    }

    return trav != NULL;
}

void delete(BST *B, char elem) {
    BST *trav;

    for (trav = B; *trav != NULL && elem != (*trav)->data;) {
        trav = elem > (*trav)->data ? &(*trav)->RC : &(*trav)->LC;
    }

    BST temp;

    if (*trav != NULL) {
        if ((*trav)->LC == NULL) {
            temp = *trav;
            *trav = temp->RC;
            free(temp);
        } else if ((*trav)->RC == NULL) {
            temp = *trav;
            *trav = temp->LC;
            free(temp);
        } else {
            BST *predecessor;
            for (predecessor = &(*trav)->LC; (*predecessor)->RC != NULL; predecessor = &(*predecessor)->RC) {}

            temp = *predecessor;
            (*trav)->data = temp->data;
            *predecessor = temp->LC;
            free(temp);
        }
    }
}

char min(BST B) {
    BST trav;

    for (trav = B; trav != NULL && trav->LC != NULL; trav = trav->LC) {}

    return B == NULL ? '0' : trav->data;
}

char max(BST B) {
    BST trav;

    for (trav = B; trav != NULL && trav->RC != NULL; trav = trav->RC) {}

    return B == NULL ? '0' : trav->data;
}

void preOrderWalk(BST B) {
    if (B != NULL) {
        printf("%c", B->data);
        preOrderWalk(B->LC);
        preOrderWalk(B->RC);
    }
}

void inOrderWalk(BST B) {
    if (B != NULL) {
        inOrderWalk(B->LC);
        printf("%c", B->data);
        inOrderWalk(B->RC);
    }
}

void postOrderWalk(BST B) {
    if (B != NULL) {
        postOrderWalk(B->LC);
        postOrderWalk(B->RC);
        printf("%c", B->data);
    }
}
