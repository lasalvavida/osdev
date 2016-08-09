#ifndef LIST_h
#define LIST_h

#include "Class.h"

struct Class;
typedef struct Class Class;

struct List;
typedef struct List List;

struct Object;
typedef struct Object Object;

struct ListNode {
  Class* (*class)();
	List* list;
	Object* value;
	struct ListNode* parent;
	struct ListNode* child;
};
typedef struct ListNode ListNode;

Class* ListNode_Class();

ListNode* ListNode_new();

struct List {
	Class* (*class)();
	ListNode* head;
	ListNode* tail;
	int size;
};
typedef struct List List;

Class* List_Class();

List* List_new();

void List_append(List* list, Object* object);

#endif
