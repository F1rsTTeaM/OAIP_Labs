#include <stdio.h>
#include <Windows.h>

int a2[5] = { 2,3,4,5,6 };
int b2[6] = { 1,2,3,4,5,6 };
void main() {
	//Задача 31B
	int k1, a1, b1;
	scanf_s("%d%d", &a1, &b1);
	for (k1 = b1;k1 >= a1;k1 -= a1)
		printf("%d ", k1);
	printf("\n");
	for (k1 = b1 * 2;k1 <= b1 * b1 / a1;k1 += b1)
		printf("%d\n", k1);


	//Задача 32B
	int i2, s2;
	for (i2 = 0;i2 < 5;i2++)
		if (a2[i2] % 2 == 0)
			a2[i2] = 2;
	s2 = -2;
	for (i2 = 2;i2 < 5;i2++)
		s2 += a2[i2];
	printf("%d", s2);



	//Задача 33B
	int i3, k3, t3;
	scanf_s("%d", &k3);
	t3 = b2[k3];
	for (i3 = k3;i3 > 0;i3--)
		b2[i3] = b2[i3 - 1];
	b2[0] = t3;
	for (i3 = 0;i3 < 6;i3++)
		printf("%d ", b2[i3]);
}