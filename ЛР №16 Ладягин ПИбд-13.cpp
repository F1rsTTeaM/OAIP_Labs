#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10
int arr[NUM_ELEMENTS], n = 0;

void printElements() {
	printf("< ");
	for (int i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
	printf(">\n");
}
void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}
void oddsX10() {
	for (int i = 0; i < n;i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}
int findMin() {
	int min = arr[0];
	for (int i = 1;i < n;i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}
void much10() {
	int count = 0;
	for (int i = 0;i < n;i++) {
		if (arr[i] > 10) {
			count++;
		}
	}
	printf("\n");
	printf("Элементов > 10: %d\n", count);
}
int findLastEven() {
	int k = 0;
	for (int i = 0;i < n;i++) {
		if (arr[i] % 2 == 0) {
			if (i > k) {
				k = i;
			}
		}
	}
	return k;
}
int findIndexMin() {
	int IndexMin = 0;
	int min = arr[0];
	for (int i = 1;i < n;i++) {
		if (arr[i] < min) {
			min = arr[i];
			IndexMin = i;
		}
	}
	return IndexMin;
}
void number7() {
	for (int i = 0;i < n;i++) {
		if (arr[i] % 2 == 0) {
			arr[i] *= -1;
		}
	}
}
void number8() {
	for (int i = 0;i < n;i++) {
		if (arr[i] < 4) {
			arr[i] = 4;
		}
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("-----------------------------------\n");
		printf("Содержимое массива: \n");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: х10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов > 10\n");
		printf("5: х2 для последнего четного\n");
		printf("6: Сколько четных левее минимального\n");
		printf("7: Все четные элементы массива умножить на -1\n");
		printf("8: Все элементы массива имеющие значения меньше 4 заменить на 4\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>>>>> ");

		scanf_s("%d", &item);

		switch (item) {

		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int min = findMin();
			printf("\n");
			printf("min = %d\n", min);
		}
		break;

		case 4:
			much10();
			break;

		case 5: 
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			}
		}
		break;

		case 6: 
		{
			int index = findIndexMin();
			printf("\n");
			printf("Индекс минимального элемента = %d\n", index);

			int cnt = 0;
			
			for (int i=0;i < index;i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("Левее минимального %d четных элементов\n", cnt);
		}
		break;

		case 7:
			number7();
			break;

		case 8:
			number8();
			break;

		}
	} while (item != 0);
}