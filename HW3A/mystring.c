/*
 * mystring.c
 *
 *  Created on: Jan 24, 2019
 *      Author: student
 */
#include <stdlib.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}
/**
 * Calculate the length of the string
 * excluding the terminating null byte ('\0')
 * @param const char* s
 * @return number of characters in the string pointed to by s
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/** Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}

/**
 * copy at most n bytes from string s and allocate memory to the new string
 * If s is longer than n, only n bytes are copied
 * add null-terminate at the end
 * @param s the string we copy
 * @param n the maximum bytes number we could copy
 * @return pointer to duplicated string
 * 		   Null if insufficient memory is available
 */
char* mystrndup(char* s, size_t n){
	char* newstr = (char*) malloc(n+1);
	if(newstr == NULL)
		return NULL;
	else{
		newstr = mystrncpy(newstr,s,n);
		return newstr;
	}

}

/**
 * copy the second string into the first string
 * @param dest the string we will copy into
 * @param src the string we will copy
 * @return pointer to destination string
 */
char* mystrcpy(char* dest, char* src) {
	char* copy = dest;
	while(*src != '\0'){
		*dest++ = *src++;
	}
	*dest = '\0';
	return copy;
}

/**
 * replace the first n character in dest with first n character in src
 * if n is larger than the size of src, copy src into dest, and original string in dest will
 * be discard
 * @param dest the string we copy into
 * @param src the string we copy
 * @param n the size we want to copy
 * @return Pointer to destination string
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	char* copy = dest;
	if(n > mystrlen1(src)){
		copy = src;
	}else{
		for(int i = 0; i < n && *src != '\0'; i++){
			*dest++ = *src++;
		}
	}
	return copy;

}

/** Appends the source string after the destination string,
 * @param dest Destination string
 * @param src source string
 * @return Pointer to destination string.
 */
char* mystrcat(char* dest, char* src){
	char* ptr = dest + mystrlen1(dest); // Find the terminator of the dest
	while(*src != '\0'){ // Copy src starting after dest
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return dest;
}
/**
 * append the first n character from src after dest
 * if n is larger than the length, only append the number of length characters
 * @param dest the string we need to append to
 * @param src the string we append from
 * @param n the number of character we need to append
 * @return the pointer to destination string
 */
char* mystrncat(char* dest, char* src, size_t n) {
	char* ptr = dest + mystrlen1(dest); //Find the terminator of the dest
	while(*src != '\0' && n--){
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return dest;
}

