#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* first = NULL;

void printList() {
	struct Node* point = first;
	while (point != NULL) {
		printf("(%d) -> ", point->data);
		point = point -> next;
	}
	printf("NULL\n");
}
void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> next = first;
	newNode -> data = value;
	first = newNode;
}
void delFromHead() {
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
}
void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}
int contains(int value) {
	struct Node* point = first;
	while (point != NULL) {
		if (point->data == value)
			return 1;
		point = point->next;
	}
	return 0;
}
int sum() {
	struct Node* point = first;
	int s = 0;
	while (point != NULL) {
		s += point->data;
		point = point->next;
	}
	return s;
}
int evenCount() {
	int k = 0;

	struct Node* newNode = first;
	while (newNode != NULL) {
		if (newNode->data % 2 == 0)
			k += 1;
		newNode = newNode->next;
	}
	return k;
}
void oddsX10() {
	struct Node* point = first;
	while (point != NULL) {
		if (point->data % 2 != 0)
			point->data *= 10;
		point = point->next;
	}
}
void elementIx100(int i) {
	struct Node* point = first;
	int index = 0;
	while (point != NULL) {
		if (index == i) {
			point->data *= 100;
			return;
		}
		point = point->next;
		index++;
	}

}
void elementLeftIx10(int i) {
	struct Node* point = first;
	int index = 0;
	while (point != NULL) {
		if (index < i) {
			point->data *= 10;
		}
		point = point->next;
		index++;
	}
}


void main() {
	printf("\n\n------------------------------------\n\n");

	printList();

	printf("\n------------------------------------\n\n");

	addToHead(100);
	addToHead(200);
	addToHead(300);
	printList();

	printf("\n------------------------------------\n\n");

	delFromHead();
	printList();

	printf("\n------------------------------------\n\n");

	clearList();
	printList();

	printf("\n------------------------------------\n\n");

	addToHead(100);
	addToHead(230);
	addToHead(350);
	addToHead(400);
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(200) = %d\n", contains(200));
	printf("contains(350) = %d\n", contains(350));

	printf("\n------------------------------------\n\n");

	printList();
	printf("sum = %d\n", sum());

	printf("\n------------------------------------\n\n");

	clearList();
	addToHead(2);
	addToHead(5);
	addToHead(8);
	addToHead(11);
	addToHead(13);
	printList();

	printf("even numb = %d\n", evenCount());

	printf("\n------------------------------------\n\n");

	printList();
	oddsX10();
	printList();

	printf("\n------------------------------------\n\n");

	printList();
	elementIx100(0);
	elementIx100(4);
	printList();

	printf("\n------------------------------------\n\n");

	clearList();
	addToHead(2);
	addToHead(5);
	addToHead(8);
	addToHead(11);
	addToHead(13);
	printList();

	elementLeftIx10(3);
	printList();
	elementLeftIx10(5);
	printList();


}