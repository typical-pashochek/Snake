#ifndef snake_func
#define snake_func
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

struct Snake {
	int x;
	int y;
	char c;
	struct Snake* next;
};

typedef struct Snake Snake;

struct Wall {
	int x;
	int y;
	char c;
	struct Wall* next;
};

typedef struct Wall Wall;

int size, delay;
int AppleX, AppleY;
int score;
int direction_flag;
void SetField();
void CleanWalls(Wall* ptr);
void SetWalls(Wall* begin);
void DvizhD(Snake* tail);
void DvizhW(Snake* tail);
void DvizhA(Snake* tail);
void DvizhS(Snake* tail);
void Apple(Snake* tail, Wall* wall);
void InitialSnake(Snake* ptr);
Snake* addUnit(Snake* head);
void PrintSnake(Snake* tail);
int Logic(Snake** tail, Snake* head, Wall** Walls);
Snake* GetHead(Snake* tail);
void Start(Snake* tail, Wall* wall);
void Move(Snake* tail, Snake* head);
//void GameOver();
void AutoMove(Snake* tail, Snake* head);
int IsWall(int x, int y, Wall* Walls);
int IsTail(int x, int y, Snake* tail);
int IsTail_Far(int x, int y, Snake* tail, int dir);
void Step(Snake** tail, Snake* head, Wall** Walls);
void CreateWay(Snake** tail, Snake* head, Wall** Walls);

#endif