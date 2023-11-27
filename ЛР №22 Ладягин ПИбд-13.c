#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

int toUpperAll(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'а' && c <= 'я')
		new_c = 'А' + (c - 'а');
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}
int MakeNew(int a) {
	if (a >= ' ' && a <= '@')
		return '_';
	else if (a >= '[' && a <= '`')
		return '_';
	else if (a >= '{' && a <= '~')
		return '_';
	else
		return a;
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//Задача 1
	char name[12];
	printf("Введите ваше имя: ");
	fgets(name, 11, stdin);
	printf("Приветствую тебя, %s\n", name);
	

	//Задача 2
	printf("Введите символ = ");
	int ch = getchar();

	for (int c = ch;c <= ch + 19;c++) {
		printf("'%c' (%d)\n", c, c);
	}
	
	printf("\n\n\n");
	

	//Задача 3
	printf("Введите символ = ");
	int ch3 = getchar();

	for (int c3 = ch3;c3 >= ch3 - 29;c3--) {
		printf("'%c' (%d)\n", c3, c3);
	}
	printf("\n\n\n");


	//Задача 4
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);

	int cnt = 0;
	for (int i = 0;i < strlen(s);i++) {
		if (s[i] == ' ') cnt++;
	}

	printf("\nВ ней %d пробелов\n", cnt);
	

	//Задача 5
	char s5[80];
	printf("Введите строчку: ");
	fgets(s5, 79, stdin);

	printf("\nВы ввели строчку %s\n", s5);

	int k = 0;
	for (int i = 0;i < strlen(s5);i++) {
		if (isspace(s5[i])) {
			s5[i] = '#';
		}
	}

	printf("\nСтрока после обработки = %s\n", s5);
	

	//Задча 6
	char s6[80];
	printf("Введите строчку: ");
	fgets(s6, 79, stdin);

	printf("\nВы ввели строчку: %s\n", s6);

	for (int i = 0;i < strlen(s6);i++) {
		if (isdigit(s6[i])) {
			s6[i] = '$';
		}
	}

	printf("\nСтрока после обработки = % s\n", s6);
	

	//Задача 7
	char s7[80];
	printf("Введите строчку: ");
	fgets(s7, 79, stdin);

	printf("\nВы ввели строчку: %s\n", s7);

	for (int i = 0;i < strlen(s7);i++) {
		s7[i] = toupper(toUpperAll(s7[i]));
	}

	printf("\nСтрока после обработки = %s\n", s7);
	

	//Задание Вариант 8
	char s8[80];
	printf("Введите строчку: ");
	fgets(s8, 79, stdin);

	printf("\nВы ввели строчку: %s\n", s8);

	for (int i = 0;i < strlen(s8);i++) {
		s8[i] = MakeNew(s8[i]);
	}

	printf("\nСтрока после обработки = %s\n", s8);
	
	
	
}