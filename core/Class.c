#include "Class.h"
#include "Object.h"
#include "Memory.h"

Class* CLASS_CLASS = NULL;

Class* Class_Class() {
	if (CLASS_CLASS == NULL) {
	  CLASS_CLASS = Class_new(String_new("Class"), Object_Class);
	}
	return CLASS_CLASS;
}

Class* Class_new(String* name, Class* (*super)()) {
	Class* class = (Class*)malloc(sizeof(Class));
	class->name = name;
	class->super = super;
	class->class = Class_Class;
	if (class->super != NULL) {
		Class_registerSubClass(class->super(), class);
	}
	class->subClasses = Dictionary_new(DICTIONARY_DEFAULT_SIZE);
	class->methods = Dictionary_new(DICTIONARY_DEFAULT_SIZE);
	return class;
}

void Class_registerSubClass(Class* class, Class* subClass) {
	Dictionary_set(class->subClasses, subClass->name, (Object*)subClass);
}

void Class_registerMethod(Class* class, Method* method) {
	List* methods = (List*)Dictionary_at(class->methods, method->name);
	if (methods == NULL) {
		methods = List_new();
		Dictionary_set(class->methods, method->name, methods);
	}
	List_append(methods, (Object*)method)
}

void Class_destroy(Class* class) {
	int i;
	class->class = NULL;
	class->name = NULL;
	class->super = NULL;
	Array* keys = class->subClasses->keys;
	for (i = 0; i < keys->size; i++) {
		String* className = (String*)Array_at(keys, i);
		Class* subClass = (Class*)Dictionary_at(class->subClasses, className);
		Class_destroy(subClass);
	}
	Dictionary_destroy(class->subClasses);
	Dictionary_destroy(class->methods);
}
