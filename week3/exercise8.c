#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Enemy {
	int hitpoints;
    int manapoints;
    int attackspeed;
} Enemy;

int takeDamage(Enemy* entity, int damage) {
	entity->hitpoints -= damage;
	return (entity->hitpoints > 0);
}

void merge(Enemy* arr, int lowBound, int midIndex, int highBound) {
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
Enemy* mergeSortEnemies(Enemy* arr, int lowBound, int highBound) {
	if (lowBound >= highBound) return arr;
	int midIndex = (lowBound + highBound) / 2;
	// left half
	mergeSortEnemies(arr, lowBound, midIndex);
	// right half
	mergeSortEnemies(arr, midIndex + 1, highBound);

	merge(arr, lowBound, midIndex, highBound);
	return arr;
}


int main() {
	srand(time(NULL));
	int n, damage;

	scanf("%d", &n);
	Enemy* enemies = (Enemy*) malloc(n * sizeof(Enemy));

	for (int i = 0; i < n; i++) {
		scanf("%d", &enemies[i].hitpoints);
		enemies[i].manapoints = rand() % 10;
		enemies[i].attackspeed = rand() % 10;
	}

	scanf("%d", &damage);

	for (int i = 0; i < n; i++) {
		takeDamage(&enemies[i], damage);
	}

	enemies = mergeSortEnemies(enemies, 0, n - 1);
	
	for (int i = 0; i < n; i++)
	{
		if (enemies[i].hitpoints > 0) printf("%d ", enemies[i].hitpoints);
	}
	
	free(enemies);
	return 0;
}