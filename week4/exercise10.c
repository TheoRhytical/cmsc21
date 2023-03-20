#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int arrCap = 20;
int arrSize = 0;
#define WORDSIZE 46


typedef struct wordObj{
	char* word;
	int count;
} wordObj;

// return -1 if not found
int searchWord(char* word, wordObj** wordArr) {
	for (int i = 0; i < arrSize; i++) {
		if (strcmp(word, wordArr[i]->word) == 0) {
			return i;
		}
	}
	return -1;
}

void storeWord(int index, char* word, wordObj** wordArr) {
	wordObj* newWord = (wordObj*) malloc(sizeof(wordObj));
	newWord->count = 1;
	newWord->word = word;
	wordArr[index] = newWord;
	arrSize++;
}

char* getWord(char word[]) {
	// int size = strlen(word) + 1;
	char* buffer = (char*) malloc(sizeof(char) * (strlen(word) + 1));
	int j = 0;
	for (int i = 0; i < strlen(word); i++) {
		if (isalnum(word[i])) buffer[j++] = tolower(word[i]);
	}
	if (j == 0) {
		buffer[0] = '\0';
		return buffer;
	}

	if (j <= strlen(word)) buffer = realloc(buffer, sizeof(char) * j);
	buffer[j] = '\0';
	return buffer;
}

void bubbleSort(wordObj** wordArr) {
	int i, j;
    for (i = 0; i < arrSize - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < arrSize - i - 1; j++) {
            if (wordArr[j]->count < wordArr[j + 1]->count) {
				wordObj* temp = wordArr[j];
				wordArr[j] = wordArr[j + 1];
				wordArr[j + 1] = temp;
			}
		}
	}
}


int main() {
	wordObj** wordArr = malloc(sizeof(wordObj*) * arrCap);
	char buffer[WORDSIZE];
	char* cleanedWord;
	int wordIndex, newWordIndex = 0, wordCount = 0;
	while(scanf("%s", buffer) != EOF) {
		cleanedWord = getWord(buffer);
		if (strlen(cleanedWord) == 0) continue;
		wordCount++;
		wordIndex = searchWord(cleanedWord, wordArr);
		if (wordIndex == -1) {
			if (newWordIndex >= arrCap) {
				arrCap *= 2;
				wordArr = (wordObj**) realloc(wordArr, sizeof(wordObj*) * arrCap);
			}
			storeWord(newWordIndex++, cleanedWord, wordArr);
		} else {
			wordArr[wordIndex]->count++;
		}
	}

	// for (int i = 0; i < newWordIndex; i++) {
	// 	printf("index: %d\tword: %s\tcount:%d\n", i, wordArr[i]->word, wordArr[i]->count);
	// }
	// printf("~~~~~\n");
	bubbleSort(wordArr);
	printf("%d\n", wordCount);
	for (int i = 0; i < 10 && i < newWordIndex; i++) {
		printf("%d %s\n", wordArr[i]->count, wordArr[i]->word);
	}

	for (int i = 0; i < newWordIndex; i++) {
		free(wordArr[i]);
	}
	free(wordArr);
}