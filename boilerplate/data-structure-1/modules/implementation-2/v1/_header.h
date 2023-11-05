#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME_V1
#define DATASTRUCTURE_IMPLEMENTATIONNAME_V1

// * MACROS HERE
#define MAX 10

// * TYPE DEFINITIONS HERE
typedef struct {
    int someIntegerData[MAX];
    char someCharData[MAX];
} DataStructureName;

// * OPERATIONS HERE
void initializeStruct();
void addToStruct();
void deleteFromStruct();
void updateStruct();
void displayStruct();

#endif