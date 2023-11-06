#ifndef DICTCLOSED_LINKEDLIST_V2
#define DICTCLOSED_LINKEDLIST_V2
#include <stdbool.h>

#define MAX 10
typedef struct node {
    int data;
    struct node *link;
} *LIST;

typedef LIST DICT[MAX];

void initialize(DICT *D);
int hash(int x);
bool isMember(DICT D, int elem);
void insertMember(DICT *D, int elem);
void deleteMember(DICT *D, int elem);
void displayDict(DICT D);

#endif