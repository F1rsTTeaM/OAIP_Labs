#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	printf("Задача 1. Ряд натуральных чисел.\n");

	int i, n;

	printf("n = ");
	scanf_s("%d", &n);

	i = 1;
	do {
		printf("%d ", i);
		i += 1;
	} while (i <= n);

	printf("\n");
	printf("---------------------------------------------------------------\n");

	printf("Задача 2. Степень двойки.\n");

	int res, stepen;

	stepen = 0;
	res = 1;

	do {
		printf("2^%d = %d\n", stepen, res);
		stepen += 1;
		res = pow(2,stepen);
	} while (stepen <= 5);

	printf("---------------------------------------------------------------\n");

	printf("Задача 4. Первые N четных чисел.\n");

	int n4, k, i4;

	printf("n4 = ");
	scanf_s("%d", &n4);

	k = 1;
	i4 = 2;

	do {
		printf("%d ", i4);
		k += 1;
		i4 += 2;
	} while (k <= n4);

	printf("\n");
	printf("---------------------------------------------------------------\n");

	printf("Задача 5. Первые N чисел кратных А.\n");

	int n5, a, i5, m, k5;

	printf("N = ");
	scanf_s("%d", &n5);

	printf("A = ");
	scanf_s("%d", &a);

	i5 = 1;
	k5 = 1;

	do {
		m = a * i5;
		printf("%d ", m);
		k5 += 1;
		i5 += 1;
	} while (k5 <= n5);

	printf("\n");
	printf("---------------------------------------------------------------\n");
	
	printf("Задача 6. Числа Фибоначчи.\n");

	int n6, a6, b6, k6, c6;

	printf("n = ");
	scanf_s("%d", &n6);

	a6 = 0;
	b6 = 1;
	k6 = 3;

	if (n6 >= 1) {
		printf("%d ", a6);
	}
	if (n6 >= 2) {
		printf("%d ", b6);
	}
	do {
		c6 = a6 + b6;
		printf("%d ", c6);
		a6 = b6;
		b6 = c6;
		k6 += 1;
	} while (k6 <= n6);
}