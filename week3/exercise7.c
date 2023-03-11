#include <time.h>
#include <stdlib.h>
#include <stdio.h>
// #include "Enemy.h";

struct Enemy {
    int hitpoints;
    int manapoints;
    int attackspeed;
};

void merge(struct Enemy* arr, int lowBound, int midIndex, int highBound) {
	int leftArrSize = midIndex - lowBound + 1;
	int rightArrSize = highBound - midIndex;

	struct Enemy leftArr[leftArrSize], rightArr[rightArrSize];

	for (int i = 0; i < leftArrSize; i++) leftArr[i] = arr[lowBound + i];
	for (int i = 0; i < rightArrSize; i++) rightArr[i] = arr[midIndex + i + 1];

	int i, j, k = lowBound;
	i = j = 0;

	while (i < leftArrSize && j < rightArrSize) {
		if (leftArr[i].hitpoints <= rightArr[j].hitpoints) {
			arr[k++] = leftArr[i++];
		} else {
			arr[k++] = rightArr[j++];
		}
	}

	while (i < leftArrSize) {
		arr[k++] = leftArr[i++];
	}

	while (j < rightArrSize) {
		arr[k++] = rightArr[j++];
	}
}

// merge sort
// A recursive function that sorts enemies
// I think this is quite advanced in the meantime, but if you're interested, here's a CS50 explainer
// https://www.youtube.com/watch?v=Ns7tGNbtvV4
// or this
// https://www.youtube.com/watch?v=r9iYBM4-BMA
struct Enemy* mergeSort(struct Enemy* arr, int lowBound, int highBound) {
	if (lowBound >= highBound) return arr;
	int midIndex = (lowBound + highBound) / 2;
	// left half
	mergeSort(arr, lowBound, midIndex);
	// right half
	mergeSort(arr, midIndex + 1, highBound);

	merge(arr, lowBound, midIndex, highBound);
	return arr;
}


// I had to use sir's function prototype, but essentially, my sortin algorithm is within mergeSort()
struct Enemy* sortEnemies(struct Enemy* enemies, int n) {
	return mergeSort(enemies, 0, n - 1);
}


int main() {
	// Setup for rand() to generate random numbers
	srand(time(NULL));
	struct Enemy enemies[5];

	// Generate random stats for enemies with a range of 0 to 99
	// I included manapoints and attackspeed for badazzle
	for (int i = 0; i < 5; i++) {
		enemies[i].hitpoints = rand() % 100;
		enemies[i].manapoints = rand() % 100;
		enemies[i].attackspeed = rand() % 100;
	}

	// Prints out enemy hitpoints before they're sorted
	for (int i = 0; i < 5; i++) {
		printf("enemy #%d hitpoints: %d\n", i, enemies[i].hitpoints);
	}

	printf("\n\n");

	// Sort enemies
	struct Enemy* sortedEnemies = sortEnemies(enemies, 5);

	// Print hitpoints of sorted enemies
	for (int i = 0; i < 5; i++) {
		printf("enemy #%d hitpoints: %d\n", i, sortedEnemies[i].hitpoints);
	}
	
	
	return 0;
}