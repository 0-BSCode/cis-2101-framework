#ifndef BST_DOUBLEPOINTER_V2
#define BST_DOUBLEPOINTER_V2
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *LC;
    struct node *RC; 
} Node, *BST;

void initialize(BST *B);
void insert(BST *B, char elem);
bool isMember(BST B, char elem);
void delete(BST *B, char elem);
char min(BST B);
char max(BST B);
char deleteMin(BST *B);

void preOrderWalk(BST B);
void inOrderWalk(BST B);
void postOrderWalk(BST B);


#endif