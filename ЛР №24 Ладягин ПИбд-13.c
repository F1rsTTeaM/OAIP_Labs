#include <stdio.h>
#include <Windows.h>

long fuct(int n1) {
	if (n1 == 0)
		return 1;
	long res = fuct(n1 - 1) * n1;
	return res;
}
long fuct21(int n2) {
	printf("%d ", n2);
	if (n2 > 1)
		fuct21(n2 - 2);
}
long fuct22(int n3) {
	if (n3 > 1)
		fuct22(n3 - 2);
	printf("%d ", n3);
}
long fuct23(int n4) {
	printf("%d ", n4);
	if (n4 > 1)
		fuct23(n4 - 2);
	printf("%d ", n4);
}
void recEGE1(int n) {
	if (n >= 1) {
		printf("%d ", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}
void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}
void F2(int n) {
	printf("%d\n", n);
	if (n < 5) {
		F2(n + 1);
		F2(n + 3);
	}
}
void G3(int n);
void F3(int n) {
	if (n > 0)
		G3(n - 1);
}
void G3(int n) {
	printf("*");
	if (n > 1)
		F3(n - 3);
}


void main() {

	//Задача 1
	int n1 = 5;
	long f1 = fuct(n1);
	printf("%d! = %ld", n1, f1);


	printf("\n\n==================================\n\n");


	//Задача 2.1
	int n2 = 7;
	long f2 = fuct21(n2);


	printf("\n\n==================================\n\n");


	//Задача 2.2
	int n3 = 7;
	long f3 = fuct22(n3);


	printf("\n\n==================================\n\n");


	//Задача 2.3
	int n4 = 7;
	long f4 = fuct23(n4);


	printf("\n\n==================================\n\n");


	//Задача 4
	recEGE1(3);


	printf("\n\n==================================\n\n");


	//Задача 5
	F1(10);


	printf("\n\n==================================\n\n");


	//Задача 6
	F2(1);


	printf("\n\n==================================\n\n");


	//Задача 7
	F3(11);
}