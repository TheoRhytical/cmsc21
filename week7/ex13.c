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

void printList(LinkedList* list) {
	LinkedListNode* current = list->head;
	for (int i = 0; current != NULL; i++) {
		printf("%d ", *((int*) current->item));
		current = current->next;
	}
	printf("\n");
}


int main() {
	LinkedList* list = malloc(sizeof(LinkedList));
	list->head = NULL;
	int a = 3, b = 5, c = 11, d = 34;
	insertItem(list, 0, &a);
	insertItem(list, 1, &b);
	insertItem(list, 2, &c);
	printList(list);
	setItem(list, 0, &d);
	printList(list);
	// printf("GetItem: %d\n", *((int*)getItem(list, 1)));
	// int new = 49;
	// setItem(list, 1, &new);
	// deleteItem(list, 1);
	// printList(list);
	// deleteItem(list, 1);
	// printList(list);
	// deleteItem(list, 0);
	// printList(list);
	free(list);
}