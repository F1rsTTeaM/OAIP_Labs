#include<stdio.h>
#include<Windows.h>

void main() {
	//Задача 21B
	int n1, i1, j1;
	scanf_s("%d", &n1);

	i1 = 10;
	do {
		j1 = 1;

		do {
			printf("%d ", i1 + j1);
			j1++;
		} while (j1 <= n1);

		printf("\n");
		i1 += 10;
	} while (i1 <= n1 * 10);


	//Задача 22B
	int n2, i2, j2;
	scanf_s("%d", &n2);
	i2 = 1;
	do {
		j2 = n2;
		do {
			if (j2 <= i2)
				printf("%d ", j2);
			else
				printf(" ");
			j2--;
		} while (j2 >= 1);
		printf("\n");
		i2++;
	} while (i2 <= n2);



	//Задача 23B
	int n3, i3, j3;
	char ch;
	scanf_s("%d", &n3);
	i3 = 2;
	do {
		if (i3 % 2 == 0)
			ch = '>';
		else
			ch = '<';
		j3 = 1;
		while (j3 != i3) {
			printf("%c ", ch);
			j3++;
		}
		printf("\n");
		i3++;
	} while (i3 <= n3);
}