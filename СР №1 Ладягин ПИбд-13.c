#include <stdio.h>

void main() {

	//Задача 1B
	int a, b, d, e;

	scanf_s("%d%d", &a, &b);
	d = 0;
	e = 1;

	if (a % 3 == 0) {
		d++;
		e *= a;
	}

	if (b % 3 == 0) {
		d++;
		e *= b;
	}

	if (d == 0) {
		e = 0;
	}

	printf("%d %d", d, e);


	printf("\n\n==============================\n\n");


	//Задча 2B
	int a2, b2;

	scanf_s("%d", &a2);
	b2 = a2;
	do {
		printf("%d ", b2);
		b2--;
	} while (b2 >= 1);

	do {
		b2++;
		printf("%d ", b2);
	} while (b2 < a2);


	printf("\n\n==============================\n\n");


	//Задча 3B
	int n3, d3;

	scanf_s("%d", &n3);
	printf("%d = 1 ", n3);
	d3 = 2;
	do {
		if (n3 % d3 == 0) {
			printf("* %d ", d3);
			n3 = n3 / d3;
		}
		else{
			d3++;
		}
	} while (n3 > 1);
}