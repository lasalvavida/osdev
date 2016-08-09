#include "String.h"
#include "Object.h"

Class* STRING_CLASS = NULL;

Class* String_Class() {
	if (STRING_CLASS == NULL) {
		STRING_CLASS = Class_new(String_new("String"), Object_Class);
	}
	return STRING_CLASS;
}

String* String_new(char* chars) {
	String* string = (String*)malloc(sizeof(String));
	string->class = String_Class;
	string->chars = chars;
	string->length = String_length(string);
	return string;
}

int String_length(String* str) {
	int i = 0;
	while(str->chars[i] != 0) {
		i++;
	}
}

unsigned long String_hash(String* str) {
	unsigned long hash = 5381;
  int c;
	char* chars = str->chars;
  while (c = *(chars)++) {
    hash = ((hash << 5) + hash) + c;
	}
  return hash;
}

int String_equals(String* str1, String* str2) {
	if (str1->length != str2->length) {
		return 0;
	}
	int i;
	for(i = 0; i < str1->length; i++) {
		if (str1->chars[i] != str2->chars[i]) {
			return 0;
		}
	}
	return 1;
}
