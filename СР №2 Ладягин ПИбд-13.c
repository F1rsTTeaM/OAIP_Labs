#include <stdio.h>

void main() {
	
	//Задача 11B
	int a, b, s;

	scanf_s("%d%d", &a, &b);

	s = 0;
	while (a <= b) {
		s += a;
		a += 4;
		printf("%d ", s);
	}


	printf("\n\n=============================\n\n");


	//Задача 12B
	int a2, b2;

	scanf_s("%d", &a2);

	b2 = 1;
	while (b2 <= a2) {
		printf("\n%d", b2);

		if (b2 % 3 == 0) {
			printf("*");
		}
		if (b2 % 4 == 0) {
			printf(":");
		}

		b2++;
	}

	
	printf("\n\n=============================\n\n");

	//Задача 13B
	int a3, b3, k, s3;

	scanf_s("%d%d", &a3, &b3);
	k = 1;
	s3 = a3;
	while (k <= b3) {
		s3 += k;
		k += 1;
		printf("%d ", s3);
		if (s3 % 7 == 0)
			break;
	}
}