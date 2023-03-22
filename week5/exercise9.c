#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int getWordLen(char* word) {
	int wordLen = 0, i = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		if (isalnum(word[i])) wordLen++;
	}
	return wordLen;
}

void alnumCpy(char* destination, char* source, int size) {
	for (int i = 0, j = 0; source[i] != '\0'; i++) {
		if (isalnum(source[i])) destination[j++] = source[i];
	}
	destination[size] = '\0';
}


int main() {
	int wordArrSize = 10, wordLen, i = 0;
	char input[21];
	char** wordArr = malloc(wordArrSize * sizeof(char*));
	while (scanf("%s", input) != EOF) {
		wordLen = getWordLen(input);
		if (wordLen == 0) continue;
		char* word = malloc((wordLen + 1) * sizeof(char));
		if (i >= wordArrSize) {
			int prevSize = wordArrSize;
			wordArrSize *= 2;
			wordArr = realloc(wordArr, wordArrSize * sizeof(char*));
		}
		alnumCpy(word, input, wordLen);
		wordArr[i++] = word;
	}

	for (int j = i - 1; j >= 0; j--) {
		printf("%s\n", wordArr[j]);
		free(wordArr[j]);
	}
	free(wordArr);
	return 0;
}