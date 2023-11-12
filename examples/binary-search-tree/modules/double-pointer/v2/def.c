#include "_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(BST *B) {
    *B = NULL;
}
void insert(BST *B, char elem) {
    BST *trav = B;
    if (*trav == NULL) {
        BST temp = (BST)malloc(sizeof(Node));

        if (temp != NULL) {
            temp->data = elem;
            temp->LC = *trav;
            temp->RC = *trav;
            *trav = temp;
        }
    } else if (elem > (*trav)->data) {
        insert(&(*trav)->RC, elem);
    } else if (elem < (*trav)->data) {
        insert(&(*trav)->LC, elem);
    }
}
bool isMember(BST B, char elem) {
    if (B == NULL) {
        return false;
    } else if (elem == B->data) {
        return true;
    } else if (elem > B->data) {
        return isMember(B->RC, elem);
    } else {
        return isMember(B->LC, elem);
    }
}
// TODO: Make recursive
void delete(BST *B, char elem) {
    BST *trav = B, temp;

    if ((*trav) == NULL) {
        return;
    } else if (elem == (*trav)->data) {
        if ((*trav)->LC == NULL) {
            temp = *trav;
            *trav = temp->RC;
            free(temp);
        } else if ((*trav)->RC == NULL) {
            temp = *trav;
            *trav = temp->LC;
            free(temp);
        } else {
            (*trav)->data = deleteMin(&(*trav)->RC);
        }
    } else if (elem > (*trav)->data) {
        delete(&(*trav)->RC, elem);
    } else {
        delete(&(*trav)->LC, elem);
    }
}
char deleteMin(BST *B) {
    BST *trav = B, temp;
    int ret;

    if ((*trav)->LC == NULL) {
        temp = *trav;
        *trav = temp->RC;
        ret = temp->data;
        free(temp);
        return ret;
    } else {
        return deleteMin(&(*trav)->LC);
    }
}

char min(BST B) {
    if (B == NULL) {
        return '0';
    } else if (B->LC == NULL) {
        return B->data;
    } else {
        return min(B->LC);
    }
}
char max(BST B) {
    if (B == NULL) {
        return '0';
    } else if (B->RC == NULL) {
        return B->data;
    } else {
        return max(B->RC);
    }
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