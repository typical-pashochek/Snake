#ifndef string_func
#define string_func
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
int length(char str[]);
void TextIntoMass(char*** mass, FILE** Text, int* rowsCount);
char* Gets();
char* GetWord(char** mass, int* i);
int GetDigit(char** mass);
#endif