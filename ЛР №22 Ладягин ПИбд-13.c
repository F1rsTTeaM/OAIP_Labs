#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

int toUpperAll(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c == '�')
		new_c = '�';
	return new_c;
}
int MakeNew(int a) {
	if (a >= ' ' && a <= '@')
		return '_';
	else if (a >= '[' && a <= '`')
		return '_';
	else if (a >= '{' && a <= '~')
		return '_';
	else
		return a;
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//������ 1
	char name[12];
	printf("������� ���� ���: ");
	fgets(name, 11, stdin);
	printf("����������� ����, %s\n", name);
	

	//������ 2
	printf("������� ������ = ");
	int ch = getchar();

	for (int c = ch;c <= ch + 19;c++) {
		printf("'%c' (%d)\n", c, c);
	}
	
	printf("\n\n\n");
	

	//������ 3
	printf("������� ������ = ");
	int ch3 = getchar();

	for (int c3 = ch3;c3 >= ch3 - 29;c3--) {
		printf("'%c' (%d)\n", c3, c3);
	}
	printf("\n\n\n");


	//������ 4
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������ s = \"%s\"", s);

	int cnt = 0;
	for (int i = 0;i < strlen(s);i++) {
		if (s[i] == ' ') cnt++;
	}

	printf("\n� ��� %d ��������\n", cnt);
	

	//������ 5
	char s5[80];
	printf("������� �������: ");
	fgets(s5, 79, stdin);

	printf("\n�� ����� ������� %s\n", s5);

	int k = 0;
	for (int i = 0;i < strlen(s5);i++) {
		if (isspace(s5[i])) {
			s5[i] = '#';
		}
	}

	printf("\n������ ����� ��������� = %s\n", s5);
	

	//����� 6
	char s6[80];
	printf("������� �������: ");
	fgets(s6, 79, stdin);

	printf("\n�� ����� �������: %s\n", s6);

	for (int i = 0;i < strlen(s6);i++) {
		if (isdigit(s6[i])) {
			s6[i] = '$';
		}
	}

	printf("\n������ ����� ��������� = % s\n", s6);
	

	//������ 7
	char s7[80];
	printf("������� �������: ");
	fgets(s7, 79, stdin);

	printf("\n�� ����� �������: %s\n", s7);

	for (int i = 0;i < strlen(s7);i++) {
		s7[i] = toupper(toUpperAll(s7[i]));
	}

	printf("\n������ ����� ��������� = %s\n", s7);
	

	//������� ������� 8
	char s8[80];
	printf("������� �������: ");
	fgets(s8, 79, stdin);

	printf("\n�� ����� �������: %s\n", s8);

	for (int i = 0;i < strlen(s8);i++) {
		s8[i] = MakeNew(s8[i]);
	}

	printf("\n������ ����� ��������� = %s\n", s8);
	
	
	
}