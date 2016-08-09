#ifndef METHOD_h
#define METHOD_h

#include "Class.h"
#include "String.h"

struct Method {
	Class* (*class)();
	Class* (*target)();
	Class* returnType
	String* name;
	Array* arguments;
	Array* instructions;
};
typedef struct Method Method;

Class* Method_Class();

Method* Method_new(Class* (*target)(), String* name, Array* arguments, Array* instructions);

#endif
