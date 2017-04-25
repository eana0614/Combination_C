#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<memory.h>
#include<string.h>


int checkingInt(int n, int r);
int checkingString(char* input, int length);
void runCombination(char* element, int n, int r, int length);
void addCombinationElement(int length);
int factorial(int i);
int calculationCombinationNum(int n, int r);
void printCombination(int n, int r, int length);

char* temp;
char** combination;
int count = 0;

int main(void) {

	char input[100];
	int n, r;
	int combinationNum;

	printf("!] Input different N numbers or characters. (max length < 99)\n");
	printf(">> ");
	scanf("%s", &input);

	n = strlen(input);

	if (checkingString(input, n) > 0) {

		printf("\n!] Input R. \n");
		printf(" >> ");
		scanf("%d", &r);

		if (checkingInt(n, r) > 0) {
			
			combinationNum = calculationCombinationNum(n, r);

			temp = (char*)malloc(sizeof(char) * r);
			combination = (char**)malloc(sizeof(char*)*combinationNum);

			for (int i = 0; i < combinationNum; i++) {
				combination[i] = (char*)malloc(sizeof(char)*r);
			}

			runCombination(input, n, r, r);
			printCombination(n, r, combinationNum);

			printf("!] Done. \n");
		}

	}
}

void printCombination(int n, int r, int length) {

	printf("===== Result %dC%d =====\n", n, r);

	for (int i = 0; i < length; i++ ) {
		printf("%dth Combination Element = %s \n", (i+1), combination[i]);
	}

	printf("\n");
}

int calculationCombinationNum(int n, int r) {

	int mumerator = factorial(n);
	int denominator = factorial(r) * factorial(n-r);

	return mumerator / denominator;
}

int factorial(int i) {

	if (i < 1) {
		return 1;
	}

	return i * factorial(i-1);

}

void addCombinationElement(int length) {

	int c = 0;

	for (int i = length - 1; i >= 0; i--) {
		char t = temp[i];
		combination[count][c] = t;
		c++;
	}
	combination[count][c] = '\0';
	count++;

}

void runCombination(char* element, int n, int r, int length) {

	if (r == 0) {
		addCombinationElement(length);
	}
	else if (n >= r) {

		temp[r - 1] = element[n - 1];
		runCombination(element, n - 1, r - 1, length);
		runCombination(element, n-1, r, length);

	}
}

int checkingInt(int n, int r) {
	
	if (n >= r) {
		return 1;
	}

	return 0;
}

int checkingString(char* input, int length) {
	int result = 1;
	char temp;

	for (int i = 1; i < length; i++) {
		temp = input[i];
		for (int j = 0; j < i; j++) {
			if (temp == input[j]) {
				result = 0;
				break;
			}
		}
	}

	return result;
}