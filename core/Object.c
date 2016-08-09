#include "Object.h"
#include "Memory.h"
#include "String.h"

Class* OBJECT_CLASS = NULL;

Class* Object_Class() {
  if (OBJECT_CLASS == NULL) {
    OBJECT_CLASS = Class_new(String_new("Object"), NULL);
  }
  return OBJECT_CLASS;
}

int Object_instanceOf(Object* object, Class* class) {
  Class* objectClass = object->class();
  while (objectClass != NULL) {
    if (objectClass == class) {
      return 1;
    }
    if (objectClass->super != NULL) {
      objectClass = objectClass->super();
    }
    else {
      break;
    }
  }
  return 0;
}

Object* Object_callMethod(Object* object, Class* returnType, String* methodName, Dictionary* arguments) {
  Class* class = object->class();
  Dictionary* methods = class->methods;
  Object* object = Dictionary_at(methods, methodName);
  while (object == NULL) {
    class = class->super();
    if (class == NULL) {
      return NULL;
    }
    methods = class->methods;
    object = Dictionary_at(methods, methodName);
  }
  if (Object_instanceOf(object, Method_Class())) {
    Method* method = (Method*)object;
    return Method_call(method, arguments);
  }
  return NULL;
}
