#ifndef STRING_h
#define STRING_h

#include "Class.h"
#include "Dictionary.h"
#include "Memory.h"

struct Class;
typedef struct Class Class;

struct String {
	Class* (*class)();
	char* chars;
	int length;
};
typedef struct String String;

extern int DEFAULT_STRING_POOL_SIZE;

Class* String_Class();

String* String_new(char* chars);

String* String_toLowerCase(String* str);

String* String_toUpperCase(String* str);

unsigned long String_hash(String* str);

int String_equals(String* str1, String* str2);

void String_destroy(String* str);

#endif