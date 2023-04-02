#include <stdlib.h>

typedef struct LinkedListNode {
    void* value;
    struct LinkedListNode* next;
} LinkedListNode;


typedef struct {
    LinkedListNode* head;
    int size;
} LinkedList;


LinkedListNode* createNode(void* item) {
    LinkedListNode* node = malloc(sizeof(LinkedListNode));
    node->value = item;
    node->next = NULL;
    return node;
}


LinkedListNode* getNode(LinkedList* list, int index) {
    int currentIndex = 0;
    LinkedListNode* currentNode = list->head;

    while(currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    return currentNode;
}


void* insertItem(LinkedList* list, int index, void* item) {
    if (index < 0 || index > list->size) return NULL;

    LinkedListNode* newNode = createNode(item);
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        LinkedListNode* previousNode = getNode(list, index - 1);

        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }
    list->size++;

    return newNode->value;
}


void* getItem(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) return NULL;

    LinkedListNode* node = getNode(list, index);
    return node->value;
}


void* setItem(LinkedList* list, int index, void* item) {
    if (index < 0 || index >= list->size) return NULL;

    LinkedListNode* node = getNode(list, index);
    void* oldItem = node->value;
    node->value = item;
    return oldItem;
}


void* deleteItem(LinkedList* list, int index) {
    if (index < 0 || index > list->size) return NULL;

    LinkedListNode* toRemove;
    if (index == 0) {
        toRemove = list->head;
        list->head = list->head->next;
    } else {
        LinkedListNode* previous = getNode(list, index - 1);
        toRemove = previous->next;
        previous->next = toRemove->next;
    }

    void* oldItem = toRemove->value;
    free(toRemove);
    list->size--;

    return oldItem;
}