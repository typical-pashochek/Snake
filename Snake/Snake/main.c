#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>
#include "graphics.h"
#include "string_func.h"
#include "snake_func.h"


int score = 0;
int direction_flag = 1;
int main() {	
	srand((unsigned int)time(NULL));	
	Snake* tail = (Snake*)malloc(sizeof(Snake));	
	Wall* wall = (Wall*)malloc(sizeof(Wall));
	wall->next = 0;
	wall->c = ' ';
	Start(tail, wall);
	Snake* head = (Snake*)malloc(sizeof(Snake));
	head = GetHead(tail);	
	
	
	while (Logic(&tail, head, &wall)) {
		PrintSnake(tail);
		Move(tail, head);		
	}

	GameOver();
	
	
	system("pause");
	return 0;
}