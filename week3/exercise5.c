#include <stdio.h>

void merge(int arr[], int lowBound, int midIndex, int highBound) {
	int leftArrSize = midIndex - lowBound + 1;
	int rightArrSize = highBound - midIndex;

	int leftArr[leftArrSize], rightArr[rightArrSize];

	for (int i = 0; i < leftArrSize; i++) leftArr[i] = arr[lowBound + i];
	for (int i = 0; i < rightArrSize; i++) rightArr[i] = arr[midIndex + i + 1];

	int i, j, k = lowBound;
	i = j = 0;

	while (i < leftArrSize && j < rightArrSize) {
		if (leftArr[i] <= rightArr[j]) {
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
int* mergeSort(int* arr, int lowBound, int highBound) {
	if (lowBound >= highBound) return arr;
	int midIndex = (lowBound + highBound) / 2;
	// left half
	mergeSort(arr, lowBound, midIndex);
	// right half
	mergeSort(arr, midIndex + 1, highBound);

	merge(arr, lowBound, midIndex, highBound);
	return arr;
}

int* sort(int* arrayToSort, int n) {
	return mergeSort(arrayToSort, 0, n - 1);
}


int main() {
	int test1[] = {3, 4, 25, 5, 7, 8, 11, 21};
	int test2[] = {1, 3, 9, 3, 45, 12, 32, 75};
	int test3[] = {55, 32, 12, 64, 23, 43, 23};
	int test4[] = {32, 42, 15, 87, 67, 23, 54, 34, 32};

	for (int i = 0; i < 9; i++) {
		printf("%d ", test4[i]);
	}
	printf("\n");
	sort(test4, 9);
	for (int i = 0; i < 9; i++) {
		printf("%d ", test4[i]);
	}
	
	return 0;
}