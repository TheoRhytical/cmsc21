// #include "myVector.h"
#include <stdlib.h>

struct Vector {
    int capacity;
    int size;
    int* array;
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


void addItem(Vector* list, int item) {
    insertItem(list, list->size, item);
}


VectorResult getItem(Vector* list, int index) {
    VectorResult response = {0, 1};
    if (index < 0 || index > list->size) {
        response.isValid = 0;
        return response;
    }
    response.result = list->array[index];
    return response;
}


VectorResult setItem(Vector* list, int index, int item) {
    VectorResult response = {0, 1};
    if (index < 0 || index > list->size) {
        response.isValid = 0;
        return response;
    }
    list->array[index] = item;
    return response;
}


VectorResult removeItem(Vector* list, int index) {
    VectorResult response = {0, 1};
    if (index < 0 || index > list->size) {
        response.isValid = 0;
        return response;
    }
    response.result = list->array[index];
    for (int i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    if (list->size <= list->capacity / 3) {
        resize(list);
    }
    return response;
}


void destroyVector(Vector* list) {
    list->capacity = 0;
    list->size = 0;
    free(list->array);
    list->array = NULL;
}
