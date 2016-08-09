#ifndef OBJECT_h
#define OBJECT_h

#include "Class.h"

struct Object {
	Class* (*class)();
};
typedef struct Object Object;

Class* Object_Class();

int Object_instanceOf(Object* object, Class* class);

Object* Object_callMethod(Object* object, String* methodName, Dictionary* arguments);

#endif
