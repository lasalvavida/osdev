#include <stdio.h>
#include "core/Class.h"
#include "core/Object.h"
#include "core/String.h"
#include "core/Dictionary.h"

void print(String* str) {
	char* chars = str->chars;
	printf("%s\n", chars);
}

int main() {
	Dictionary* dict = Dictionary_new(DICTIONARY_DEFAULT_SIZE);
	String* a = String_new("a");
	String* b = String_new("b");
	String* c = String_new("c");
	String* d = String_new("d");

	Dictionary_set(dict, a, (Object*)String_new("Hello"));
	Dictionary_set(dict, b, (Object*)String_new("World"));
	Dictionary_set(dict, c, (Object*)String_new("!"));
	Dictionary_set(dict, d, (Object*)String_new("Friend"));
	Dictionary_set(dict, a, (Object*)String_new("Destroy the"));

	print((String*)Dictionary_at(dict, a));
	print((String*)Dictionary_at(dict, b));
}
