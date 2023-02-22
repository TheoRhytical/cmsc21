#include <stdio.h>

int recursion_search(int input[], int i, int target) {
	if (i == 20) return 0;
	if (input[i] == target) return 1;
	return recursion_search(input, ++i, target);
}

int main() {
	int input[21];
	for (size_t i = 0; i < 21; i++)
	{
		scanf("%d", &input[i]);
	}

	printf("%d\n", recursion_search(input, 0, input[20]));
	
	return 0;
}