#include <stdio.h>
#include <Windows.h>

void aboutMe() {
	printf("Ладягин\n");
	printf("Павел\n");
	printf("Дмитриевич\n");
	printf("\n");
	printf("Группа: ПИбд-13\n");
	printf("Дата: 15.10.2023\n");
	printf("Предмет: Основы программирования\n");
	printf("Лабораторная работа №8\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();
}