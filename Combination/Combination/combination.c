#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<memory.h>
#include<string.h>


int checkingInt(int n, int r);
int checkingString(char* input, int length);


int main(void) {

	char input[100];
	int n, r;

	printf("!] Input different N numbers or characters. (max length < 99)\n");
	printf(">> ");
	scanf("%s", &input);

	n = strlen(input);

	if (checkingString(input, n) > 0) {

		printf("!] Input R. \n");
		printf(" >> ");
		scanf("%d", &r);

		if (checkingInt(n, r) > 0) {
			
			runCombination(input, n, r, r);
			printCombination(n, r);

			printf("!] Done. \n");
		}

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