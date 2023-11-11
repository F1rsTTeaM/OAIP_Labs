#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задача 1
	printf("\n");

	int a1, b, c, p;
	scanf_s("%d%d%d", &a1, &b, &c);
	printf("Ввели: %d, %d, %d\n", a1, b, c);
	p = a1 * b * c;
	printf("p = %d\n", p);

	printf("\n");

	printf("-----------------------------------------------------\n");
	
	//Задача 2
	printf("\n");

	int a2, b2, c2, p2;
	FILE* fin2 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in2.txt", "rt");
	if (fin2 == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin2, "%d%d%d", &a2, &b2, &c2);
	fclose(fin2);

	printf("Ввели: %d, %d, %d\n", a2, b2, c2);
	p2 = a2 * b2 * c2;
	printf("p = %d\n", p2);

	FILE* fout2 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out2.txt", "wt");
	if (fout2 == NULL) {
		printf("Выходной файл не создался\n");
		return;
	}
	fprintf(fout2, "%d", p2);
	fclose(fout2);

	printf("\n");

	printf("-----------------------------------------------------\n");

	//Задача 3
	printf("\n");

	int a3, b3, c3, d3, e3, s3;
	scanf_s("%d%d%d%d%d", &a3, &b3, &c3, &d3, &e3);
	printf("Ввели: %d, %d, %d, %d, %d\n", a3, b3, c3, d3, e3);
	s3 = a3 + b3 + c3 + d3 + e3;
	printf("s = %d\n", s3);

	printf("\n");

	printf("-----------------------------------------------------\n");

	//Задача 4
	printf("\n");

	int a4, b4, c4, d4, e4, s4;
	FILE* fin4 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in4.txt", "rt");
	if (fin4 == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin4, "%d%d%d%d%d", &a4, &b4, &c4, &d4, &e4);
	fclose(fin4);

	printf("Ввели: %d, %d, %d, %d, %d\n", a4, b4, c4, d4, e4);
	s4 = a4 + b4 + c4 + d4 + e4;
	printf("s4 = %d\n", s4);

	FILE* fout4 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out4.txt", "wt");
	if (fout4 == NULL) {
		printf("Выходной файл не создался\n");
		return;
	}
	fprintf(fout4, "%d", s4);
	fclose(fout4);

	printf("\n");

	printf("-----------------------------------------------------\n");

	//Задача 5
	printf("\n");

	int a[10], n, i;
	FILE* fin5 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in5.txt", "rt");
	if (fin5 == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin5, "%d", &n);
	for (i = 0; i < n;i++) {
		fscanf(fin5, "%d", &a[i]);
	}
	fclose(fin5);



	printf("Ввели массив a[%d] = ", n);
	for (i = 0; i < n;i++) {
		printf("%d ", a[i]);
	}

	int s5 = 0;
	for (i = 0; i < n; i++) {
		s5 += a[i];
	}
	float sa5 = (float)s5 / n;
	printf("\nsa = %f\n", sa5);

	for (i = 0; i < n; i++) {
		if (a[i] > sa5) {
			a[i] *= 10;
		}
	}

	printf("Ввели массив a[%d] = ", n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}


	
	FILE* fout5 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out5.txt", "wt");
	if (fout5 == NULL) {
		printf("Выходной файл не создался\n");
		return;
	}
	fprintf(fout5, "%d\n", n);
	for (i = 0; i < n; i++) {
		fprintf(fout5, "%d ", a[i]);
	}
	fclose(fout5);

	printf("\n");

	printf("\n-----------------------------------------------------\n");
	
	//Задача 6
	printf("\n");

	int a6[10], n6, i6;
	FILE* fin6 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in6.txt", "rt");
	if (fin6 == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin6, "%d", &n6);
	for (i6 = 0;i6 < n6;i6++) {
		fscanf(fin6, "%d", &a6[i6]);
	}
	fclose(fin6);



	printf("Ввели массив a[%d] = ", n6);
	for (i6 = 0;i6 < n6;i6++) {
		printf("%d ", a6[i6]);
	}

	int s6 = 0;
	for (i6 = 0;i6 < n6;i6++) {
		s6 += a6[i6];
	}
	float sa6 = (float)s6 / n6;
	printf("\nsa = %f\n", sa6);

	for (i6 = 0;i6 < n6;i6++) {
		if (a6[i6] < sa6 && a6[i6] % 2 == 0) {
			a6[i6] /= 2;
		}
	}

	printf("Ввели массив a[%d] = ", n6);
	for (i6 = 0; i6 < n6; i6++) {
		printf("%d ", a6[i6]);
	}



	FILE* fout6 = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out6.txt", "wt");
	if (fout6 == NULL) {
		printf("Выходной файл не создался\n");
		return;
	}
	fprintf(fout6, "%d\n", n6);
	for (i6 = 0;i6 < n6;i6++) {
		fprintf(fout6, "%d ", a6[i6]);
	}
	fclose(fout6);

	printf("\n");

	printf("\n-----------------------------------------------------\n");

	







}