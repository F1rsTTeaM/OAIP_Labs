#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_N 10
#define MAX_M 10

int arr[MAX_N][MAX_M] = {
	{0,23,14,45},
	{54,89,38,57},
	{3,65,8,34}
};
int n = 3, m = 4;


void print() {
	printf("!!!! print() !!!!\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void FILLx10() {
	printf("!!!! FILLx10 !!!!\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}
void fillZero() {
	printf("!!!! fillZero !!!!\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			arr[i][j] = 0;
		}
	}
}
void fillRand() {
	printf("!!!! fillRand !!!!\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			arr[i][j] = rand() % 10;
		}
	}
}
void oddsx10() {
	printf("!!!! oddsx10 !!!!\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] % 2 != 0) {
				arr[i][j] *= 10;
			}
		}
	}
}
void Number5() {
	printf("!!!! Number5 !!!!\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] /= 10;
			}
		}
	}
}
void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);
	printf("m = ");
	scanf_s("%d", &m);

	printf("Введите двухмерный массив размером %d строк на %d столбцов:\n", n, m);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	printf("\n");
}
void deleteRow(int delRow) {
	printf("!!!! deleteRow(%d) !!!!\n", delRow);
	for (int i = delRow;i < n - 1;i++) {
		for (int j = 0;j < m;j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}
void addColumn(int ColumnNum) {
	printf("!!!! addColumn(%d) !!!!\n", ColumnNum);

	if (m < MAX_M) {
		for (int i = 0;i < n;i++) {
			arr[i][m] = arr[i][ColumnNum];
		}
		m++;
	}

}
void Number9() {
	printf("!!!! Number9 !!!!\n");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			for (int k = i + 1;k < n;k++) {
				if (arr[i][j] == arr[k][j]) {
					for (int l = 0;l < n;l++) {
						arr[l][j] = 0;
					}
					break;
				}
			}
		}
	}

}
void load() {
	FILE* fin = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\in20.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
	}
	fclose(fin);
}
void save() {
	FILE* fout = fopen("C:\\Users\\F1rsTTeaM\\Desktop\\out20.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден");
		return;
	}

	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);
	printf("Массив успешно сохранен\n");
	printf("\n");
}




void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	print();
	do {
		printf("==================================\n");
		printf("Выберите нужную вам операцию: \n");
		printf("1: Заполнить значениями i * 10 + j\n");
		printf("2: Заполнить нулями\n");
		printf("3: Заполнить случайными значениями\n");
		printf("4: Все нечетные увеличить в 10 раз\n");
		printf("5: Все кратные 10 уменьшить в 10 раз\n");
		printf("6: Ввод массива с клавиаутры\n");
		printf("7: Удалить заданную строку из массива\n");
		printf("8: Продублировать заданный столбец массива\n");
		printf("9: Обнулить элементы в столбцах, где встречается хотя бы два одинаковых элемента\n");
		printf("10: Загрузить массив из файла\n");
		printf("11: Сохранить массив в файл\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			printf("==================================\n");
			printf("\n");
			FILLx10();
			print();
			break;
		case 2:
			printf("==================================\n");
			printf("\n");
			fillZero();
			print();
			break;
		case 3:
			printf("==================================\n");
			printf("\n");
			fillRand();
			print();
			break;
		case 4:
			printf("==================================\n");
			printf("\n");
			oddsx10();
			print();
			break;
		case 5:
			printf("==================================\n");
			printf("\n");
			Number5();
			print();
			break;
		case 6:
			printf("==================================\n");
			printf("\n");
			keyboardInput();
			print();
			break;
		case 7:
			printf("==================================\n");
			printf("\n");
			int delRow;
			printf("Номер строки, которую нужно удалить: ");
			scanf_s("%d", &delRow);
			deleteRow(delRow);
			print();
			break;
		case 8:
			printf("==================================\n");
			printf("\n");
			int ColumnNum;
			printf("Номер столбца, который нужно продублировать: ");
			scanf_s("%d", &ColumnNum);
			addColumn(ColumnNum);
			print();
			break;
		case 9:
			printf("==================================\n");
			printf("\n");
			Number9();
			print();
			break;
		case 10:
			printf("==================================\n");
			printf("\n");
			load();
			print();
			break;
		case 11:
			printf("==================================\n");
			printf("\n");
			save();
			print();
			break;
		}
		
	} while (item != 0);
}
