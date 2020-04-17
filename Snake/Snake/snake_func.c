#include "snake_func.h"

void SetField() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
	for (int i = 0; i <= size; i++) {
		gotoxy(i, 0);
		printf("#");
		gotoxy(size - i, size);
		printf("#");
		gotoxy(0, size - i);
		printf("#");
		gotoxy(size, i);
		printf("#");
		Sleep(40);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void SetWalls(Wall* begin) {
	int I = rand() % (size / 2) + 3;
	int J = rand() % (size / 2) + 4;
	for (int i = J; i < J + 4; i++) {
		if (begin->next == 0 && begin->c != '*') {
			begin->x = I;
			begin->y = i;
			begin->c = '*';
		}
		else {
			begin->next = (Wall*)malloc(sizeof(Wall));
			begin = begin->next;
			begin->x = I;
			begin->y = i;
			begin->c = '*';
			begin->next = 0;
		}
		gotoxy(I, i);
		printf("*");
	}
	I = rand() % (size / 2) + 3;
	J = rand() % (size / 2) + 4;
	for (int i = J; i < J + 4; i++) {
		if (begin->next == 0 && begin->c != '*') {
			begin->x = I;
			begin->y = i;
			begin->c = '*';
		}
		else {
			begin->next = (Wall*)malloc(sizeof(Wall));
			begin = begin->next;
			begin->x = I;
			begin->y = i;
			begin->c = '*';
			begin->next = 0;
		}
		gotoxy(I, i);
		printf("*");
	}
}

void DvizhD(Snake* tail) {
	Snake* ptr = tail;
	while (ptr->next != NULL)
	{
		gotoxy(ptr->x, ptr->y);
		printf(" ");
		ptr->x = ptr->next->x;
		ptr->y = ptr->next->y;
		ptr = ptr->next;
	}
	if (ptr->x + 1 == size) {
		ptr->x = 1;
	}
	else {
		ptr->x++;
	}

}

void DvizhW(Snake* tail) {
	Snake* ptr = tail;
	while (ptr->next != NULL)
	{
		gotoxy(ptr->x, ptr->y);
		printf(" ");
		ptr->x = ptr->next->x;
		ptr->y = ptr->next->y;
		ptr = ptr->next;
	}
	if (ptr->y - 1 == 0) {
		ptr->y = size - 1;
	}
	else {
		ptr->y--;
	}
}

void DvizhA(Snake* tail) {
	Snake* ptr = tail;
	while (ptr->next != NULL)
	{
		gotoxy(ptr->x, ptr->y);
		printf(" ");
		ptr->x = ptr->next->x;
		ptr->y = ptr->next->y;
		ptr = ptr->next;
	}
	if (ptr->x - 1 == 0) {
		ptr->x = size - 1;
	}
	else {
		ptr->x--;
	}
}

void DvizhS(Snake* tail) {
	Snake* ptr = tail;
	while (ptr->next != NULL)
	{
		gotoxy(ptr->x, ptr->y);
		printf(" ");
		ptr->x = ptr->next->x;
		ptr->y = ptr->next->y;
		ptr = ptr->next;
	}
	if (ptr->y + 1 == size) {
		ptr->y = 1;
	}
	else {
		ptr->y++;
	}
}

void Apple(Snake* tail, Wall* wall) {
	int flag = 0;

	while (flag == 0) {
		flag = 1;
		AppleX = rand() % (size - 1) + 1;
		AppleY = rand() % (size - 1) + 1;
		Snake* ptr = tail;
		while (ptr->next != 0) {
			if (AppleX == ptr->x && AppleY == ptr->y) {
				flag = 0;
				break;
			}
			ptr = ptr->next;
		}
		Wall* ptr_ = wall;
		int count = 0;
		while (ptr_->next != 0) {
			count += 1;
			if (AppleX == ptr_->x && AppleY == ptr_->y) {
				flag = 0;
				break;
			}
			ptr_ = ptr_->next;
		}
		if (AppleX == ptr_->x && AppleY == ptr_->y) {
			flag = 0;
		}
		if (flag == 0) {
			continue;
		}
		else {
			gotoxy(AppleX, AppleY);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			printf("o");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			return;
		}
	}
}

void InitialSnake(Snake* ptr) {
	ptr->x = 2;
	ptr->y = 2;
	ptr->c = 'x';
	ptr->next = (Snake*)malloc(sizeof(Snake));
	ptr = ptr->next;
	ptr->x = 3;
	ptr->y = 2;
	ptr->c = '<';
	ptr->next = 0;
}

Snake* addUnit(Snake* head) {
	Snake* tail = (Snake*)malloc(sizeof(Snake));
	tail->next = head;
	tail->x = head->x;
	tail->y = head->y;
	tail->c = 'x';
	return tail;
}

void PrintSnake(Snake* tail) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	while (tail->next != 0) {
		gotoxy(tail->x, tail->y);
		putchar(tail->c);
		tail = tail->next;
	}
	gotoxy(tail->x, tail->y);
	putchar(tail->c);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int Logic(Snake** tail, Snake* head, Wall** Walls) {
	Snake* ptr = *tail;
	Wall* wall = *Walls;
	while (ptr->next != 0) {
		if (head->x == ptr->x && head->y == ptr->y) {
			return 0;
		}
		ptr = ptr->next;
	}
	while (wall->next != 0) {
		if (head->x == wall->x && head->y == wall->y) {
			return 0;
		}
		wall = wall->next;
	}
	if (head->x == wall->x && head->y == wall->y) {
		return 0;
	}
	gotoxy(0, size + 3);
	printf("              \n                ");
	gotoxy(0, size + 3);
	printf("Apple %d %d \nHead %d %d\n", AppleX, AppleY, head->x, head->y);
	if (AppleX == head->x && AppleY == head->y) {
		char sym = head->c;
		if (direction_flag == 3 || direction_flag == 1) {
			head->c = '-';
		}
		else {
			head->c = '|';
		}
		PrintSnake(*tail);
		Sleep(delay);
		head->c = sym;
		Apple(*tail, *Walls);
		*tail = addUnit(*tail);
		score += 10;

	}
	gotoxy(3, size + 2);
	printf("Score: %d", score);
	return 1;
}

Snake* GetHead(Snake* tail) {
	while (tail->next != 0) {
		tail = tail->next;
	}
	return tail;
}

void Start(Snake* tail, Wall* wall) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	hidecursor();
	setconsolesize(100, 30);
	printf("Chose a size of a field <15...30> and Delay <50...1000> (and turn on the English layout)\n");
	scanf_s("%d", &size);
	scanf_s("%d", &delay);
	if (size < 15 || size > 30) {
		size = 20;
	}
	if (delay < 50 || delay > 1000) {
		delay = 100;
	}
	clrscr();
	setconsolesize(size + 5, size + 5);
	SetField();
	InitialSnake(tail);
	SetWalls(wall);
	PrintSnake(tail);
	Apple(tail, wall);
}
char direction = 'd';

void Move(Snake* tail, Snake* head) {

	Sleep(delay);
	if (_kbhit()) {
		direction = _getch();
	}
	if ((direction == 'd' || direction == 'D' || direction == 'â' || direction == 'Â') && direction_flag != 3) {
		direction_flag = 1;
	}
	if ((direction == 'w' || direction == 'W' || direction == 'ö' || direction == 'Ö') && direction_flag != 4) {
		direction_flag = 2;
	}
	if ((direction == 'a' || direction == 'A' || direction == 'ô' || direction == 'Ô') && direction_flag != 1) {
		direction_flag = 3;
	}
	if ((direction == 's' || direction == 'S' || direction == 'û' || direction == 'Û') && direction_flag != 2) {
		direction_flag = 4;
	}
	switch (direction_flag) {
	case 1:
		DvizhD(tail);
		head->c = '<';
		break;
	case 2:
		DvizhW(tail);
		head->c = 'v';
		break;
	case 3:
		DvizhA(tail);
		head->c = '>';
		break;
	case 4:
		DvizhS(tail);
		head->c = '^';
		break;
	}

}

void GameOver() {
	FILE* top;
	fopen_s(&top, "Top5.txt", "r");
	clrscr();
	setconsolesize(100, 30);
	gotoxy(0, 0);
	printf("Game Over\nYour score: %d", score);
	printf("\n");
	char** mass;
	int rows;
	if (top != NULL) {
		TextIntoMass(&mass, &top, &rows);
	}
	else {
		printf("Can't load Top 5...\n");
		exit(1);
	}
	fclose(top);
	fopen_s(&top, "Top5.txt", "w");
	for (int i = 0; i < rows; i++) {
		int len = 0;
		char* word = GetWord(&(mass[i]), &len);
		word = GetWord(&(mass[i]), &len);
		int sc0re = GetDigit(&word);
		if (score >= sc0re) {
			printf("Congratulations, you are in the Top 5! Input your name(without space): ");
			getchar();
			char* name = Gets();
			fprintf(top, "%s %d", name, score);
			if (rows == 1 && mass[0][0] == 0) {
				break;
			}
			if (rows < 5) {
				for (int j = i; j < rows; j++) {
					fprintf(top, "\n%s", mass[j]);
				}
			}
			else {
				for (int j = i; j < rows - 1; j++) {
					fprintf(top, "\n%s", mass[j]);
				}
			}
			break;
		}
		if (i == rows - 1) {
			fprintf(top, "%s", mass[i]);
		}
		else {
			fprintf(top, "%s\n", mass[i]);
		}
		if (i == rows - 1 && rows < 5) {
			printf("Congratulations, you are in the Top 5! Input your name(without space): ");
			getchar();
			char* name = Gets();
			fprintf(top, "\n%s %d", name, score);
			break;
		}
	}
	fclose(top);
	fopen_s(&top, "Top5.txt", "r");
	TextIntoMass(&mass, &top, &rows);
	printf("Top 5!\n");
	for (int i = 0; i < rows; i++) {
		printf("%d %s\n", i + 1, mass[i]);
	}
}