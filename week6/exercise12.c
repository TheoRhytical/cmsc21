// #include <myVector.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct Vector {
    int capacity;
    int size;
    char* array;
};


struct VectorResult {
    int result;
    int isValid;
};


typedef struct Vector Vector;
typedef struct VectorResult VectorResult;


void initializeVector(Vector* list) {
    list->capacity = 10;
    list->size = 0;
    list->array = malloc(sizeof(int*) * list->capacity);
}


void resize(Vector* list) {
    list->capacity = list->size * 2;
    list->array = realloc(list->array, sizeof(int) * list->capacity);
}


VectorResult insertItem(Vector* list, int index, int item) {
    VectorResult response = {0, 1};
    if (index < 0 || index > list->size) {
        response.isValid = 0;
        return response;
    }
    
    if (list->size == list->capacity) {
        resize(list);
    }
    
    for (int i = list->size; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index] = item;
    list->size++;

    return response;
}


VectorResult addItem(Vector* list, int item) {
    return insertItem(list, list->size, item);
}


void destroyVector(Vector* list) {
    list->capacity = 0;
    list->size = 0;
    free(list->array);
    list->array = NULL;
}


void initString(Vector* strVec, char* string) {
	int len = strlen(string);
	strVec->capacity = len;
	strVec->size = len;
	strVec->array = string;
}


void concatenate(Vector* combined, Vector* a, Vector* b) {
	int len = strlen(a->array) + strlen(b->array);
    initializeVector(combined);
	// combined->array = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < strlen(a->array); i++) {
		addItem(combined, a->array[i]);
	}
	for (int i = 0; i < strlen(b->array); i++) {
		addItem(combined, b->array[i]);
	}
    addItem(combined, '\0');
}


void slice(Vector* sliced, Vector* source, int start, int end) {
    initializeVector(sliced);
    for(int i = start; i < end; i++) {
        addItem(sliced, source->array[i]);
    }
    addItem(sliced, '\0');
}


int main() {
    char *str1 = malloc(sizeof(char) * 16);
    Vector strVec1;

    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            char *str2 = malloc(sizeof(char) * 16);
            scanf("%s %s", str1, str2);
            Vector strVec2, strVecCombined;
            initString(&strVec1, str1);
            initString(&strVec2, str2);
            concatenate(&strVecCombined, &strVec1, &strVec2);
            printf("%s\n", strVecCombined.array);
            destroyVector(&strVec1);
            destroyVector(&strVec2);
            destroyVector(&strVecCombined);
            break;

        case 2:
            int start, end;
            scanf("%s %d %d", str1, &start, &end);
            Vector strVecSlice;
            initString(&strVec1, str1);
            slice(&strVecSlice, &strVec1, start, end);
            printf("%s\n", strVecSlice.array);
            destroyVector(&strVec1);
            destroyVector(&strVecSlice);
            break;
    }

	return 0;
}