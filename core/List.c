#include "List.h"
#include "Object.h"
#include "Memory.h"

Class* LISTNODE_CLASS = NULL;

Class* ListNode_Class() {
	if (LISTNODE_CLASS == NULL) {
		LISTNODE_CLASS = Class_new(String_new("ListNode"), Object_Class);
	}
	return LISTNODE_CLASS;
}

ListNode* ListNode_new(Object* object) {
	ListNode* listNode = (ListNode*)malloc(sizeof(ListNode));
	listNode->class = ListNode_Class;
	listNode->value = object;
	listNode->parent = NULL;
	listNode->child = NULL;
}

Class* LIST_CLASS = NULL;

Class* List_Class() {
	if (LIST_CLASS == NULL) {
		LIST_CLASS = Class_new(String_new("List"), Object_Class);
	}
}

List* List_new() {
	List* list = (List*)malloc(sizeof(List));
	list->class = List_Class;
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void List_append(List* list, Object* object) {
	ListNode* listNode = ListNode_new(object);
	if (list->head == NULL) {
		list->head = listNode;
		list->tail = listNode;
	}
	else {
		listNode->parent = list->tail;
		list->tail = listNode;
	}
	list->size++;
}
