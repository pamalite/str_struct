
#include "str_struct.h"

#include <stdio.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
	Str *str = Str_new();

	str->set(str, "this is a string.");
	printf("%s - %d\n", str->str, str->length);

	str->set(str, "this is also a string.");
	printf("%s - %d\n", str->str, str->length);

	str->set(str, "this is a super duper long string. the quick brown fox jumped over the lazy dog. bah bah black sheep have you any wool?");
	printf("%s - %d\n", str->str, str->length);

	Str_dispose(str);

	// ===

	Str *str2 = Str_newWith("%s %d", "some string", 626);

	printf("%s - %d\n", str2->str, str->length);

	Str_dispose(str2);

	// ===

	Str *str3 = Str_newWith("this is a super duper long string. the quick brown fox jumped over the lazy dog. bah bah black sheep have you any wool?");

	printf("%s - %d\n", str3->str, str->length);

	str3->toUpper(str3);
	printf("%s - %d\n", str3->str, str->length);

	str3->toLower(str3);
	printf("%s - %d\n", str3->str, str->length);

	Str_dispose(str3);

	// ===

	Str *str4 = Str_newWith("a string");
	Str *str5 = Str_newWith("a string");

	if (str4->isEqualsIgnoreCase(str4, str5)) {
		printf("matched!\n");
	} else {
		printf("no match!\n");
	}

	str5->set(str5, "a new thing");
	if (str5->isEqualsIgnoreCase(str5, str4)) {
		printf("matched!\n");
	} else {
		printf("no match!\n");
	}

	Str_dispose(str4);
	Str_dispose(str5);

	// ===

	Str *str6 = Str_newWith("   some texts go here   ");

	printf("_%s_ - %d\n", str6->str, str6->length);

	str6->trim(str6);
	printf("_%s_ - %d\n", str6->str, str6->length);

	Str_dispose(str6);

	// ===

	Str *str7 = Str_newWith("the quick brown fox jumped over the lazy dog");

	printf("%s - %d\n", str6->str, str6->length);

	Str *str8 = str7->sub(str7, 5, 8);
	printf("%s - %d\n", str8->str, str8->length);

	Str_dispose(str8);
	Str_dispose(str7);

	// ===

	Str *str9 = Str_newWith("the lazy dog");
	Str *str10 = Str_newWith("the quick brown fox");
	Str *str11 = Str_newWith(" slides under ");

	str9->append(str9, str11);
	str9->append(str9, str10);

	printf("%s - %d\n", str9->str, str9->length);

	Str_dispose(str10);
	Str_dispose(str11);
	Str_dispose(str9);

	// ===

	Str *fileName = Str_newWith("test_file.txt");
	Str *fileContents = Str_new();

	fileContents->set(fileContents, "lorem ipsum %d lorem %3.3f", 1277, 4.5667);

	FILE *handle = fopen(fileName->str, "w");
	fprintf(handle, "%s\n", fileContents->str);
	fprintf(handle, "number of characters written: %d", fileContents->length);
	fclose(handle);

	Str_dispose(fileContents);

	Str *readFileContents = Str_new();
	FILE *fp = fopen(fileName->str, "r");

	int c;
	while ((c = fgetc(fp)) != EOF) {
		readFileContents->append(readFileContents, Str_newWith("%c", c));
	}

	fclose(fp);

	printf("%s\n", readFileContents->str);

	Str_dispose(readFileContents);
	return 0;
}
