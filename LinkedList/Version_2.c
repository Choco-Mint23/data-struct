#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct {
	Node *head;
	int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

int main() {
	
	List *L = initialize();

	
	insertPos(L,2,0);
	insertPos(L,6,1);
	insertPos(L,5,2);
	insertFirst(L,8);
	
	

	display(L);
	printf("\nvalue at index 2 is: %d",retrieve(L,2));
	
	if(locate(L,5)==-1) {
		printf("\nThat number is not in the list");
	} else {
		printf("\nYour number is found at index %d",locate(L,5));
	}
	
	empty(L);
	display(L);
	
	return 0;
	
}
List* initialize() {
	
	List *ptr = malloc(sizeof(List ));
	
	if(ptr==NULL) {
		 printf("Memory allocation failed.\n");
		return NULL;
	}
	ptr->head = NULL;
	ptr->count = 0;
	
	return ptr;
}
void empty(List *list) {
	
	Node *current = list->head;
	int i;
	
	
	for(i=0;i<list->count;i++) {
		Node *temp = current;
		current = current->next;
		free(temp);
	}
    list->head = NULL;
	list->count = 0;
	
}
void insertFirst(List *list, int data) {

  Node *newNode = malloc(sizeof(struct node));
      newNode->data = data;
      newNode->next = list->head;
	  list->head = newNode;
      list->count++;
}

void insertLast(List *list, int data) {
	
	Node *newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	
	Node *current = list->head;
	if(list->head == NULL) {
		list->head = newNode;
	}
	while(current->next!=NULL) {
		current = current->next;
	}
	current->next = newNode;
	list->count++;
}

void insertPos(List *list, int data, int index) {
	
	if (index > list->count) {
		printf("index invalid");
	}
	else if(index == 0) {
		insertFirst(list,data);
	}
	else if(index == list->count) {
		insertLast(list,data);
	} else {
		Node *newNode = malloc(sizeof(struct node));
		int i;
		newNode->data = data;
		Node *current = list->head;
		
		for(i=0;i<index-1;i++) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		list->count++;
	}
	
	
}

void deleteStart(List *list) {
	
	Node *current = list->head;
	list->head = current->next;
	free(current);
	list->count--;
}

void deleteLast(List *list) {
	
	if(list->count == 1) {
		free(list->head); 
		list->head = NULL;
		list->count--;
	} else {
		Node *current = list->head;
		int i;
		for(i=0;i<list->count-2;i++) {
		   current = current->next;
		}
		free(current->next);
		current->next = NULL;
		list->count--;
	}
	
	
}

void deletePos(List *list, int index) {
	
	if(index==0) {
		deleteStart(list);
	} else {
		Node *current = list->head;
		int i;
		for(i=0;i<index-1;i++) {
			current = current->next; 
		}
		Node *temp = current->next;
		current->next = temp->next;
		free(temp);
		list->count--;
	}
	
}

int retrieve(List *list, int index) {
	
	if(index>list->count) {
		printf("invalid index");
	} else {
		Node *current = list->head;
		int i;
		for(i=0;i<index;i++) {
			current = current->next;
		}
		return current->data;
	}
	
}

int locate(List *list, int data) {
	
	if(list->head == NULL) {
		return -1;
	} else {
		Node *current = list->head;
		int index = 0;
		while(current!=NULL) {
			if(current->data == data) {
				return index;
			} else if (current->data != data) {
				current = current->next;
				index++;
			}
			
			}
			return -1;
		}
	}

void display(List *list) {
	
	Node *trav = list->head;
	int i;
	for(i=0;i<list->count;i++) {
	printf("Node[%d]: %d\n",i,trav->data);
		trav = trav->next;
    }
}
