#include "string_func.h"
int length(char str[]) {
	int n = 0;
	while (str[n] != '\0') {
		n = n + 1;
	}
	return n;
}

void TextIntoMass(char*** mass, FILE** Text, int* rowsCount) {
	char symbol;
	symbol = fgetc(*Text);
	int rows = 2;
	while (!feof(*Text)) {
		if (symbol == '\n') {
			rows += 1;
		}
		symbol = fgetc(*Text);
	}
	*rowsCount = rows - 1;
	fseek(*Text, 0, SEEK_SET);
	(*mass) = (char**)malloc(rows * sizeof(char*));
	for (int i = 0; i < rows; i++) {
		int count = 0;
		symbol = fgetc(*Text);
		while (symbol != '\n' && !feof(*Text)) {
			count += 1;
			symbol = fgetc(*Text);
		}
		if (symbol == '\n') {
			fseek(*Text, -(count + 2), SEEK_CUR);
		}
		else {
			fseek(*Text, -(count), SEEK_CUR);
		}
		(*mass)[i] = (char*)malloc((count + 2) * sizeof(char));
		fgets((*mass)[i], count + 1, *Text);
		fgetc(*Text);
		(*mass)[i][count + 1] = 0;
	}
}

char* Gets() {
	char* mass = (char*)malloc(51 * sizeof(char));
	char sym;
	int i = 0;
	sym = getchar();
	while (sym != '\n' && i < 50) {

		mass[i] = sym;
		sym = getchar();
		i += 1;
	}
	mass[i] = 0;
	char* mass_ = (char*)malloc((i + 1) * sizeof(char));
	for (int j = 0; j <= i; j++) {
		mass_[j] = mass[j];
	}
	free(mass);
	return mass_;
}

char* GetWord(char** mass, int* i) {
	int len = length(*mass);
	char* word;
	while ((*mass)[*i] == ' ' && *i < len) {
		*i += 1;
	}
	int begin = *i;
	while ((*mass)[*i] != ' ' && *i < len) {
		*i += 1;
	}
	word = (char*)malloc((*i + 1 - begin) * sizeof(char));
	for (int j = begin; j < *i; j++) {
		word[j - begin] = (*mass)[j];
	}
	word[*i - begin] = 0;
	return word;
}
//перевод строки в число
int GetDigit(char** mass) {
	int res = 0;
	int len = length(*mass);
	for (int i = 0; i < len; i++) {
		res = res * 10 + (int)(*mass)[i] - 48;
	}
	return res;
}