#include "Array.h"
#include "String.h"
#include "Object.h"
#include "Memory.h"

Class* ARRAY_CLASS = NULL;

Class* Array_Class() {
	if (ARRAY_CLASS == NULL) {
		ARRAY_CLASS = Class_new(String_new("Array"), Object_Class);
	}
	return ARRAY_CLASS;
}

Array* Array_new(int capacity) {
	Array* array = (Array*)malloc(sizeof(Array));
	array->class = Array_Class;
	array->elements = (Object**)malloc(sizeof(Object*) * capacity);
	array->capacity = capacity;
	array->size = 0;
	return array;
}

void Array_append(Array* array, Object* element) {
	Array_set(array, array->size, element);
}

Object* Array_at(Array* array, int index) {
	if (index < array->size) {
		return array->elements[index];
	}
	return NULL;
}

void Array_resizeElements(Array* array, int size) {
	if (size > array->capacity) {

	}
}

Object* Array_set(Array* array, int index, Object* element) {
	if (index < array->size) {
		Object* old = Array_at(array, index);
		array->elements[index] = element;
		return old;
	}
	Array_resizeElements(array, index);
	array->elements[index] = element;
	array->size = index;
	return NULL;
}

void Array_destroy(Array* array) {
	free(array->elements);
	free(array);
}
