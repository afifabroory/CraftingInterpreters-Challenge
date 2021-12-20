#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DoublyLinkedNode {
	struct DoublyLinkedNode *next;
	struct DoublyLinkedNode *prev;
	char *data;
} Node;

typedef struct DoublyLinkedList {
	struct DoublyLinkedNode *firstNode;
	struct DoublyLinkedNode *lastNode;
} List;

void printList(List *list) {
	Node *currentNode = list->firstNode;
	
	while (currentNode != NULL) {
		printf("%s ", currentNode->data);
		currentNode = currentNode->next;
	}

	printf("\n");
}

void InsertEnd(List *list, char data[]) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = (char *) malloc(strlen(data) * sizeof(char));
	strcpy(newNode->data, data);

	if (list->lastNode == NULL) {
		list->lastNode = newNode;

		if (list->firstNode == NULL) list->firstNode = newNode;
	} else {
		newNode->prev = list->lastNode;
		list->lastNode->next = newNode;
		list->lastNode = newNode;
	}
}

void InsertFront(List *list, char data[]) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;

	newNode->data = (char *) malloc(strlen(data) * sizeof(char));
	strcpy(newNode->data, data);

	if (list->firstNode == NULL) {
		list->firstNode == newNode;
		
		if (list->lastNode == NULL) list->lastNode = newNode;
	} else {
		list->firstNode->prev = newNode;
		newNode->next = list->firstNode;
		list->firstNode = newNode;
	}
}

Node *FindNode(List *list, char data[]) {
	Node *currentNode = list->firstNode;

	while (currentNode != NULL) {
		if (strcmp(currentNode->data, data) == 0) return currentNode;
		
		currentNode = currentNode->next;
	}	

	return NULL;
}

void DeleteNode(Node *deleteNode) {
	deleteNode->prev->next = deleteNode->next;
	free(deleteNode->data);
	free(deleteNode);
}

int main() {
	List myLinkedList;
	myLinkedList.firstNode = NULL;
	myLinkedList.lastNode = NULL;

	InsertEnd(&myLinkedList, "World");
	InsertFront(&myLinkedList, "Hello");
	InsertEnd(&myLinkedList, "!");

	InsertEnd(&myLinkedList, "C is the best language!");
	InsertFront(&myLinkedList, ">");
	
	printList(&myLinkedList);
	
	DeleteNode(FindNode(&myLinkedList, "C is the best language!"));
	printList(&myLinkedList);

	return 0;
}
