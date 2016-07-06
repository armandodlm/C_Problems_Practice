#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
	struct ListNode *first;
	struct ListNode *last;
	uint32_t size;
}LinkedList;

typedef struct ListNode{
	struct ListNode *next;
	struct ListNode *previous;
	int value;
}ListNode;

LinkedList *initList();
void deleteList(LinkedList *list);

ListNode *initNode(int value);
void deleteNode(LinkedList *node);

void appendToList(LinkedList *list, int value);
void deleteNodeLinear(ListNode *list, int value);


LinkedList *initList(){
	LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}

void deleteList(LinkedList *list){
	if(list){
		ListNode *current = list->first;
		ListNode *next;
		while(current){
			next = current->next;
			//printf("Deleting %02d\n",current->value);
			free(current);
			current = next;
		}
	}
}


ListNode *initNode(int value){
	
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	
	newNode->next = NULL;
	newNode->previous = NULL;
	newNode->value = value;

	return newNode;
}

void appendToList(LinkedList *list, int value){
	
	ListNode *node = initNode(value);
	if(list->last){

		list->last->next = node;
		node->previous = list->last;
		list->last = node;

	}else{

		list->last = node;
		list->first = node;
	}

}

void deleteNodeLinear(ListNode *current, int value){

	if(current){
		
		if(current->value == value){
			// delete here
			ListNode *prev = current->previous;
			ListNode *next = current->next;
			if(prev) prev->next = next;
			if(next) next->previous = current->previous;
			free(current);

		}else{
			current = current->next;
			deleteNodeLinear(current,value);
		}
		
	}
}

void printList(LinkedList *list){
	if(list){
		printf("Base ->");
		ListNode *n = list->first;
		while(n != NULL){
			printf("%02d->",n->value);
			n = n->next;
		}
		printf("NULL\n");
	}
}



int main(){

	LinkedList *list = initList();
	appendToList(list,0);
	appendToList(list,2);
	appendToList(list,3);
	appendToList(list,5);
	appendToList(list,8);
	appendToList(list,4);

	printList(list);

	printf("Deleting 3\n");
	deleteNodeLinear(list->first,3);

	printList(list);

	deleteList(list);

	return 0;
}