#ifndef DICTIONARY_h
#define DICTIONARY_h

#include "Class.h"
#include "String.h"
#include "Array.h"
#include "List.h"

struct Class;
typedef struct Class Class;

struct String;
typedef struct String String;

struct Array;
typedef struct Array Array;

struct List;
typedef struct List List;

struct KeyValuePair {
	Class* (*class)();
	String* key;
	Object* value;
};
typedef struct KeyValuePair KeyValuePair;

Class* KeyValuePair_Class();

KeyValuePair* KeyValuePair_new(String* key, Object* value);


struct Dictionary {
	Class* (*class)();
	Array* keys;
	Array* bins;
	int size;
};
typedef struct Dictionary Dictionary;

extern int DICTIONARY_DEFAULT_SIZE;

Class* Dictionary_Class();

Dictionary* Dictionary_new(int size);

Object* Dictionary_at(Dictionary* dictionary, String* key);

Object* Dictionary_set(Dictionary* dictionary, String* key, Object* value);

void Dictionary_destroy(Dictionary* dictionary);

#endif