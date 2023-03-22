#include <stdlib.h>
#include <stdio.h>

void* resize(void* array, int* capacity, int size) {
	printf("Cap: %d\n", *capacity);
	*capacity *= 2;
    return realloc(array, *capacity * sizeof(int));
}

int main() {
	int size = 20;
	int capacity = 20;
	int* array = malloc(sizeof(int) * capacity);
	array = resize(array, &capacity, size);
	// array = realloc(array, (capacity*2) * sizeof(int));

	for (int i = 0; i < capacity; i++) {
		array[i] = i;
	}

	for (int i = 0; i < capacity; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;
}