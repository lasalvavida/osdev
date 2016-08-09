#ifndef CLASS_h
#define CLASS_h

#include "String.h"
#include "Array.h"
#include "Dictionary.h"
#include "Method.h"

struct String;
typedef struct String String;

struct Dictionary;
typedef struct Dictionary Dictionary;

struct Method;
typedef struct Method Method;

struct Class {
	struct Class* (*class)();
	String* name;
	struct Class* (*super)();
	Dictionary* subClasses;
	Dictionary* methods;
};
typedef struct Class Class;

Class* Class_Class();

Class* Class_new(String* name, Class* (*super)());

void Class_registerSubClass(Class* class, Class* subClass);

void Class_registerMethod(Class* class, Method* method);

void Class_callMethod(Class* class, String* name);

void Class_destroy(Class* class);

#endif
