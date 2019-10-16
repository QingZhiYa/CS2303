/*
 * tests.c
 *
 *  Created on: Jan 24, 2019
 *      Author: student
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystring.h"

bool tests(void)
{
	bool ok = false;
	bool ok1 = testMystrlen1();

	if (ok1) {
		puts("mystrlen1() passed.");
	}

	bool ok2 = testMystrlen2();
	if (ok2) {
		puts("mystrlen2() passed.");
	}

	bool ok3 = testMystrdup();
	if (ok3) {
		puts("mystrdup() passed.");
	}

	bool ok4 = testMystrncpy();
	if (ok4) {
		puts("mystrncpy() passed.");
	}

	bool ok5 = testMystrcpy();
	if (ok5) {
		puts("mystrcpy() passed.");
	}

	bool ok6 = testMystrncat();
	if (ok6) {
		puts("mystrncat() passed.");
	}

	bool ok7 = testMystrcat();
	if(ok7){
		puts("mystrcat() passed.");
	}

	bool ok8 = testMystrndup();
	if(ok8){
		puts("mystrndup() passed.");
	}
	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8; // Did all tests pass?
	return ok;
}

/**
 * Tests the mystrlen1() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen1(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen1(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen1(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}


/**
 * Tests the mystrlen2() function by comparing it to how the standard strlen() works..
 * @return true if it passes all tests.
 */
bool testMystrlen2(void) {
	bool ok = false; // True if all tests passed
	bool ok1 = false; // Individual test results
	bool ok2 = false;

	char* s1 = "Some sample string."; // String we will take the length of.
	size_t l1a = strlen(s1); // Get the lengths with the two functions.
	size_t l1b = mystrlen2(s1);
	if (l1a == l1b) {
		ok1 = true;
	}

	char* s2 = ""; // Empty string.
	size_t l2a = strlen(s2); // Get the lengths with the two functions.
	size_t l2b = mystrlen2(s2);
	if (l2a == l2b) {
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
	return ok;
}

/**
 * Test mystrdup() function by comparing it to the standard strdup().
 * @return true if it passes all tests.
 */
bool testMystrdup() {
	bool ok1 = false;

	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strdup(s1); // Copy it using standard function
	char* s3 = mystrdup(s1); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	char* s4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok1, on stack:   %p\n", &ok1);
	printf("Address of original string, on stack:        %p\n", s1);
	printf("Address of first duplicate string, on heap:  %p\n", s2);
	printf("Address of second duplicate string, on heap: %p\n", s3);
	printf("Address of other string, on heap?:           %p\n", s4);

	bool ok = ok1;
	return ok;
}

/**
 * Test mystrcpy() function.
 * @return true if pass, false if fail.
 */
bool testMystrcpy() {
	bool ok1 = false;
	bool ok2 = false;

	char s1[] = "Some sample string."; // String we will copy.
	char s2[30]; // Empty string we will copy into

	char* s3 = mystrcpy(s2, s1); // Copy the string
	if (strcmp(s1, s2) == 0) { // Does original equal copy?
		ok1 = true; // Yes!
	}

	if (s3 == s2) { // Is the return value correct?
		ok2 = true; // Yes!
	}

	bool ok = ok1 && ok2;
	return ok;
}

/**
 * Test mystrncpy() function.
 * @return true if pass, false if fail.
 */

bool testMystrncpy() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	//when the n is equal the length
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it.
	char* s3a = strncpy(s1a, s2a, 6); // The result

	printf("In testMystrncpy(): s3a = /%s/\n", s3a);
	printf("In testMystrncpy(): s2a = /%s/\n", s2a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it.
	char* s3b = mystrncpy(s1b, s2b, 6); // The result

	if (strcmp(s3a, s3b) == 0) {
		ok1 = true;
	}

	//when the n is less than the length
	char s4a[] = "012345678901234567890123456789";
	char s5a[] = "ABCDEF";
	char* s6a = strncpy(s4a, s5a, 3);
	char s4b[] = "012345678901234567890123456789";
	char s5b[] = "ABCDEF";
	char* s6b = mystrncpy(s4b, s5b, 3);
	if (strcmp(s6a, s6b) == 0) {
		ok2 = true;
	}
	printf("s6a = /%s/\n", s6a);
	printf("s6b = /%s/\n", s6b);

	//when the n is larger than the length
	char s7a[] = "012345678901234567890123456789";
	char s8a[] = "ABCDEF";
	char* s9a = strncpy(s7a, s8a, 8);
	char s7b[] = "012345678901234567890123456789";
	char s8b[] = "ABCDEF";
	char* s9b = mystrncpy(s7b, s8b, 8);
	if (strcmp(s9a, s9b) == 0) {
		ok3 = true;
	}
	printf("s9a = /%s/\n", s9a);
	printf("s9b = /%s/\n", s9b);

	return ok1 && ok2 && ok3;
}

/**
 * Test mystrncat() function.
 * @return true if pass, false if fail.
 */
bool testMystrncat() {
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	bool ok4 = false;
	//when the n is equal the length
	char s1a[] = "012345678901234567890123456789"; // A long string
	char s2a[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1a, s2a);
	char* s4a =	strncat(s1a, s2a, 6); // The result

	printf("In testMystrncat(): s1a = /%s/\n", s1a);
	printf("In testMystrncat(): s4a = /%s/\n", s4a);

	char s1b[] = "012345678901234567890123456789"; // A long string
	char s2b[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s1b, s2b);
	char* s4b = mystrncat(s1b, s2b, 6); // The result
	if (strcmp(s1a, s1b) == 0) {
		ok1 = true;
	}

	if (strcmp(s4a, s4b) == 0) {
		ok2 = true;
	}
	//when the n is larger than the length
	char s5a[] = "012345678901234567890123456789"; // A long string
	char s6a[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s5a, s6a);
	char* s8a = strncat(s5a, s6a, 8);

	char s5b[] = "012345678901234567890123456789"; // A long string
	char s6b[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s5b, s6b);
	char* s8b = mystrncat(s5b, s6b, 8);
	if (strcmp(s8a, s8b) == 0) {
		ok3 = true;
	}

	//when the n is less than the length
	char s9a[] = "012345678901234567890123456789"; // A long string
	char s10a[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s9a, s10a);
	char* s11a = strncat(s9a, s10a, 3);

	char s9b[] = "012345678901234567890123456789"; // A long string
	char s10b[] = "ABCDEF"; // A short string we will copy into it twice.
	strcpy(s9b, s10b);
	char* s11b = mystrncat(s9b, s10b, 3);
	if (strcmp(s11a, s11b) == 0) {
		ok4 = true;
	}
	printf("s11a = /%s/\n", s11a);
	printf("s11b = /%s/\n", s11b);
	return ok1 && ok2 && ok3 && ok4;
}

/**
 * Test mystrcat() function.
 * @return true if pass, false if fail.
 */
bool testMystrcat(){
	bool ok1 = false;
	char s1a[] = "012345678901234567890123456789";
	char s2a[] = "ABCDEF";
	strcpy(s1a, s2a);
	char* s3a = strcat(s1a, s2a);
	printf("s3a = /%s/\n", s3a);

	char s1b[] = "012345678901234567890123456789";
	char s2b[] = "ABCDEF";
	strcpy(s1b,s2b);
	char* s3b = mystrcat(s1b, s2b);
	printf("s3b = /%s/\n", s3b);

	if(strcmp(s3a,s3b) == 0){
		ok1 = true;
	}
	return ok1;
}

/**
 * Test mystrndup() function.
 * @return true if pass, false if fail.
 */
bool testMystrndup(){
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	//n is less than string length
	char s1[] = "Some sample string."; // String we will duplicate.
	char* s2 = strndup(s1, 5); // Copy it using standard function
	char* s3 = mystrndup(s1, 5); // Copy it using my function

	if (strcmp(s2, s3) == 0) { // Same result!
		ok1 = true;
	}

	char* s4 = "Some other string."; // Another string for testing
	printf("Address of a local variable ok1, on stack:   %p\n", &ok1);
	printf("Address of original string, on stack:        %p\n", s1);
	printf("Address of first duplicate string, on heap:  %p\n", s2);
	printf("Address of second duplicate string, on heap: %p\n", s3);
	printf("Address of other string, on heap?:           %p\n", s4);

	//n is equal the string length
	char s5[] = "12345"; // String we will duplicate.
	char* s6 = strndup(s5, 5); // Copy it using standard function
	char* s7 = mystrndup(s5, 5); // Copy it using my function
	if (strcmp(s6, s7) == 0) { // Same result!
		ok2 = true;
	}
	printf("In testMystrndup, s6 = /%s/\n", s6);
	printf("In testMystrndup, s7 = /%s/\n", s7);
	//n is larger than the string length
	char s8[] = "12345"; // String we will duplicate.
	char* s9 = strndup(s8, 7); // Copy it using standard function
	char* s10 = mystrndup(s8, 7); // Copy it using my function
	if (strcmp(s9, s10) == 0) { // Same result!
		ok3 = true;
	}
	printf("In testMystrndup, s9 = /%s/\n", s9);
	printf("In testMystrndup, s10 = /%s/\n", s10);
	bool ok = ok1 && ok2 && ok3;
	return ok;
}
