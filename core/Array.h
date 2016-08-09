#ifndef ARRAY_h
#define ARRAY_h

#include "Class.h"

struct Class;
typedef struct Class Class;

struct Object;
typedef struct Object Object;

struct Array {
	Class* (*class)();
	Object** elements;
	int size;
	int capacity;
};
typedef struct Array Array;

Class* Array_Class();

Array* Array_new(int capacity);

void Array_append(Array* array, Object* element);

void Array_prepend(Array* array, Object* element);

Array* Array_concat(Array* arr1, Array* arr2);

void Array_appendAll(Array* arr1, Array* arr2);

void Array_prependAll(Array* arr1, Array* arr2);

Object* Array_at(Array* array, int index);

Object* Array_set(Array* array, int index, Object* element);

void Array_destroy(Array* array);

#endif
