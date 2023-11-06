#include "_header.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initialize(DICT *D) {
    int ctr;

    for (ctr = 0; ctr < MAX; ctr++) {
        (*D)[ctr] = NULL;
    }
}

int hash(int x) {
    return x % MAX;
}

bool isMember(DICT D, int elem) {
    int hashVal = hash(elem);
    LIST trav;

    for (trav = D[hashVal]; trav != NULL && trav->data != elem; trav = trav->link) {}

    return trav != NULL;
}

void insertMember(DICT *D, int elem) {
    int hashVal = hash(elem);
    LIST *trav;

    for (trav = *D + hashVal; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}

    if (*trav == NULL) {
        LIST temp = (LIST)malloc(sizeof(struct node));

        if (temp != NULL) {
            temp->data = elem;
            temp->link = NULL;
            *trav = temp;
        }
    }
}

void deleteMember(DICT *D, int elem) {
    int hashVal = hash(elem);
    LIST *trav;

    for (trav = *D + hashVal; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}

    if (*trav != NULL) {
        LIST temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void displayDict(DICT D) {
    int ctr;
    LIST trav;

    for (ctr = 0; ctr < MAX; ctr++) {
        printf("[%d] => ", ctr);
        for (trav = D[ctr]; trav != NULL; trav = trav->link) {
            printf("%d ", trav->data);
        }
        printf("\n");
    }
}