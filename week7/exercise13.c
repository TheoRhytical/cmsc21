#include <stdlib.h>
#include <stdio.h>


typedef struct LinkedListNode {
    void* item;
    struct LinkedListNode* next;
} LinkedListNode;


typedef struct {
    struct LinkedListNode* head;
    int size;
} LinkedList;


void* insertItem(LinkedList* list, int index, void* item) {
	if (index > list->size || index < 0) return NULL;
	LinkedListNode* currNode = list->head;
	LinkedListNode* prevNode;
	for (int i = 0; i <= list->size; i++) {
		if (i == index) {
			// Insert
			LinkedListNode* newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
			newNode->item = item;
			if (i == 0) {
				newNode->next = currNode;
				list->head = newNode;
			} else {
				newNode->next = currNode;
				prevNode->next = newNode;
			}
			
			list->size++;
			return newNode->item;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	return NULL;
}


void* getItem(LinkedList* list, int index) {
	if (index > list->size || index < 0) return NULL;
	LinkedListNode* currNode = list->head;
	for (int i = 0; i < list->size; i++) {
		if (i == index) return currNode->item;
		currNode = currNode->next;
	}
	return NULL;
}


void* setItem(LinkedList* list, int index, void* item) {
	if (index > list->size || index < 0) return NULL;
	LinkedListNode* currNode = list->head;
	for (int i = 0; i < list->size; i++) {
		if (i == index) {
			currNode->item = item;
			return currNode->item;
		}
		currNode = currNode->next;
	}
	return NULL;
}


void* deleteItem(LinkedList* list, int index) {
	if (index > list->size || index < 0) return NULL;
	LinkedListNode* currNode = list->head;
	LinkedListNode* prevNode = NULL;
	for (int i = 0; i < list->size; i++) {
		if (index == 0) {
			list->head = currNode->next;
			free(currNode);
			list->size--;
			return (list->head == NULL) ? NULL : list->head->item;
		} else if (i == index) {
			if (currNode == NULL) return NULL;
			prevNode->next = currNode->next;
			free(currNode);
			list->size--;
			return prevNode->item;
		}
		prevNode = currNode;
		currNode = currNode->next;
		
	}
	return NULL;
}

