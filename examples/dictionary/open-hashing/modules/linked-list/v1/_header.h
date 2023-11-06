#ifndef DICTOPEN_LINKEDLIST_V1
#define DICTOPEN_LINKEDLIST_V1
#include <stdbool.h>

#define MAX 10

typedef struct node {
    int data;
    struct node *next;
} NodeType, *LIST;

typedef LIST DICT[MAX];

void initialize(DICT *D);
int hash(int x);
bool isMember(DICT D, int elem);
void insertMember(DICT *D, int elem);
void deleteMember(DICT *D, int elem);
void displayDict(DICT D);

#endif