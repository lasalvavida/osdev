#include "Method.h"
#include "Memory.h"

Class* METHOD_CLASS = NULL;

Class* Method_Class() {
  if (METHOD_CLASS == NULL) {
    METHOD_CLASS = Class_new(String_new("Method"), Object_Class);
  }
  return METHOD_CLASS;
}

Method* Method_new(Class* (*target)(), String* name, Array* arguments, Array* instructions) {
  Method* method = (Method*)malloc(sizeof(Method));
  method->target = target;
  method->name = name;
  method->arguments = arguments;
  method->instructions = instructions;
}

Object* Method_call(Method* method, Dictionary* arguments) {
  int i;
  Object* returnValue = NULL;
  for (i=0; i<method->instructions->size; i++) {
    Instruction* instruction = (Instruction*)Array_at(method->instructions, i);
    returnValue = Instruction_execute(instruction, arguments);
    if (returnValue != NULL) {
      return returnValue;
    }
  }
  return returnValue;
}
