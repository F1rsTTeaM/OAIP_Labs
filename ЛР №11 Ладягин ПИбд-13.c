#include <stdio.h>
#include <Windows.h>

void Task1() {
	printf("Task1() START\n");
	int N, M, k, i;
	printf("Введите кол-во строк таблицы: \n");
	scanf_s("%d", &N);
	printf("Введите кол-во столбцов таблицы: \n");
	scanf_s("%d", &M);
	i = 1;
	do {
		k = 1;
		do {
			printf("%d%d ", i, k);
			k += 1;
		} while (k <= M);
		printf("\n");
		i += 1;
	} while (i <= N);
	printf("\n");
	printf("Task1() FINISH\n");
}

void Task2() {
	printf("Task2() START\n");
	int k, i;
	i = 1;
	do {
		k = i;
		do {
			printf("%d ", k);
			k += i;
		} while (k <= i * 10);
		printf("\n");
		i += 1;
	} while (i <= 10);
	printf("\n");
	printf("Task2() FINISH\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = -1;
	do {
		printf("\n");
		printf("\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Задача 1 (i * 10 + j)\n");
		printf("2: Задача 2 (Таблица Пифагора)\n");
		printf("\n");
		printf("0: Выйти из программы\n");

		scanf_s("%d", &n);

		switch (n) {
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		}
	} while (n != 0);
}