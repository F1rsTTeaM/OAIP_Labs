#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int a[1000], n = 0, *pa;

int findMax() {
	int max = pa[0];
	for (int i = 0;i < n;i++) {
		if (max < pa[i]) {
			max = pa[i];
		}
	}
	return max;
}
void printElements() {
	printf("< ");
	for (int i = 0;i < n;i++) {
		printf("%d ", pa[i]);
	}
	printf(">\n");
}
void Load() {
	FILE* fin = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in19.1.txt", "rt");
	if (fin == NULL) {
		printf("Файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	for (int i = 0;i < n;i++) {
		fscanf(fin, "%d", &a[i]);
	}

	fclose(fin);
}
void SaveResult() {
	float sa = 0, s = 0;
	
	for (int i = 0;i < n;i++) {
		s += a[i];
	}
	sa = s / n;

	int k = 0;
	for (int i = 0;i < n;i++) {
		if (a[i] > sa) {
			k++;
		}
	}


	FILE* fout = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out19.1.txt", "wt");
	if (fout == NULL) {
		printf("Файл не создался\n");
		return;
	}

	fprintf(fout, "%d\n", k);
	for (int i = 0;i < n;i++) {
		if (a[i] > sa) {
			fprintf(fout, "%d ", a[i]);
		}
	}

	fclose(fout);
}
void Load2() {
	FILE* fin = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in19.1.txt", "rt");
	if (fin == NULL) {
		printf("Файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0;i < n;i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	fclose(fin);
}
void SaveResult2() {
	float sa = 0, s = 0;
	for (int i = 0;i < n;i++) {
		s += pa[i];
	}
	sa = s / n;
	printf("Средняя арифметическая = %f\n", sa);

	int k = 0;
	for (int i = 0;i < n;i++) {
		if (pa[i] > sa) {
			k++;
		}
	}



	FILE* fout = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out19.2.txt", "wt");
	if (fout == NULL) {
		printf("Файл не создался\n");
		return;
	}

	fprintf(fout, "%d\n", k);
	for (int i = 0;i < n;i++) {
		if (pa[i] > sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);
}
void Load3() {
	FILE* fin = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in19.3.txt", "rt");
	if (fin == NULL) {
		printf("Файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0;i < n;i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	fclose(fin);
}
void SaveResult3() {
	float sa = 0, s = 0;
	for (int i = 0;i < n;i++) {
		s += pa[i];
	}
	sa = s / n;
	printf("Средняя арифметическая = %f\n", sa);

	int k = 0;
	for (int i = 0;i < n;i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			k++;
		}
	}



	FILE* fout = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out19.3.txt", "wt");
	if (fout == NULL) {
		printf("Файл не создался\n");
		return;
	}

	fprintf(fout, "%d\n", k);
	for (int i = 0;i < n;i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);
}
void Load4() {
	FILE* fin = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in19.4.txt", "rt");
	if (fin == NULL) {
		printf("Файл не найден\n");
		return;
	}

	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);
	for (int i = 0;i < n;i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	fclose(fin);
}
void SaveResult4() {
	int max = findMax();
	float o;
	o = max * 2 / 3;
	printf("Высокий доход считается от = %f\n", o);

	int k = 0;
	for (int i = 0;i < n;i++) {
		if (pa[i] > o) {
			k++;
		}
	}
	
	

	FILE* fout = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out19.4.txt", "wt");
	if (fout == NULL) {
		printf("Файл не создался\n");
		return;
	}

	fprintf(fout, "%d\n", k);
	for (int i = 0;i < n;i++) {
		if (pa[i] > o) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	fclose(fout);
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("\n");
	printf("----------------------------------------------\n");


	//Задача 1
	printf("\n");

	Load();
	SaveResult();
	printf("Результаты перенесены в файл\n");

	printf("\n");
	
	printf("----------------------------------------------\n");

	//Задача 2
	printf("\n");

	Load2();
	printElements();
	SaveResult2();
	printf("Результаты перенесены в файл\n");
	free(pa);

	printf("\n");

	printf("----------------------------------------------\n");

	//Задача 3
	printf("\n");

	Load3();
	printElements();
	SaveResult3();
	printf("Результаты перенесены в файл\n");
	free(pa);

	printf("\n");

	printf("----------------------------------------------\n");

	//Задача 4
	printf("\n");

	Load4();
	printElements();
	SaveResult4();
	printf("Результаты перенесены в файл\n");
	free(pa);

	printf("\n");

	printf("----------------------------------------------\n");
}