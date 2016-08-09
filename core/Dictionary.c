#include "Memory.h"
#include "Dictionary.h"
#include "Object.h"

Class* KEYVALUEPAIR_CLASS = NULL;

Class* KeyValuePair_Class() {
	if (KEYVALUEPAIR_CLASS == NULL) {
		KEYVALUEPAIR_CLASS = Class_new(String_new("KeyValuePair"), Object_Class);
	}
}

KeyValuePair* KeyValuePair_new(String* key, Object* value) {
	KeyValuePair* keyValuePair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
	keyValuePair->class = KeyValuePair_Class;
	keyValuePair->key = key;
	keyValuePair->value = value;
	return keyValuePair;
}


Class* DICTIONARY_CLASS = NULL;
int DICTIONARY_DEFAULT_SIZE = 32;

Class* Dictionary_Class() {
	if (DICTIONARY_CLASS == NULL) {
		DICTIONARY_CLASS = Class_new(String_new("Dictionary"), Object_Class);
	}
}

Dictionary* Dictionary_new(int size) {
	Dictionary* dictionary = (Dictionary*)malloc(sizeof(Dictionary));
	dictionary->class = Dictionary_Class;
	dictionary->keys = Array_new(size);
	dictionary->bins = Array_new(size);
	dictionary->size = size;

	int i;
	for (i=0; i<size; i++) {
		Array_set(dictionary->bins, i, (Object*)List_new());
	}

	return dictionary;
}

Object* Dictionary_at(Dictionary* dictionary, String* key) {
	unsigned long index = String_hash(key) % dictionary->size;
	List* bin = (List*)Array_at(dictionary->bins, index);
	ListNode* node = bin->head;
	while (node != NULL) {
		KeyValuePair* pair = (KeyValuePair*)node->value;
		if (String_equals(key, pair->key)) {
			return pair->value;
		}
		node = node->child;
	}
	return NULL;
}

Object* Dictionary_set(Dictionary* dictionary, String* key, Object* value) {
	unsigned long index = String_hash(key) % dictionary->size;
	List* bin = (List*)Array_at(dictionary->bins, index);
	ListNode* node = bin->head;
	while (node != NULL) {
		KeyValuePair* pair = (KeyValuePair*)node->value;
		if (String_equals(key, pair->key)) {
			Object* oldValue = pair->value;
			pair->value = value;
			return oldValue;
		}
		node = node->child;
	}
	Array_append(dictionary->keys, (Object*)key);
	KeyValuePair* pair = KeyValuePair_new(key, value);
	List_append(bin, (Object*)pair);
	return NULL;
}

void Dictionary_destroy(Dictionary* dictionary) {
	Array_destroy(dictionary->keys);
	Array_destroy(dictionary->bins);
	free(dictionary);
}
