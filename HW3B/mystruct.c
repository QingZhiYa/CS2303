/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"



/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee *ptr = malloc(sizeof(struct Employee*));
	ptr->birth_year = birth;
	strcpy(ptr->name, name);
	ptr->start_year = start;
	return ptr;
}

/**
 * print the information of given employee
 * @param e the employee
 */
void printEmployee(struct Employee *e) {
	printf("Birth year = %d\n",e->birth_year);
	printf("Starting year = %d\n", e->start_year);
	printf("Name = %s\n", e->name);
}

/**
 * generate an employee with random data
 * @return the employee generated
 */
struct Employee* randEmployee(){
	int birthYear = randNum();
	int start = randNum();
	char* name = randStr();
	struct Employee* randomE = makeEmployee(birthYear,start,name);
	return randomE;

}

/**
 * generate a random number between 1900-2020
 * @return the random number
 */
int randNum(){
	int r = rand()%120;
	if(r < 0)
		r+=120;
	r+=1900;//between 1900-2020
	return r;
}

/**
 * generate printable name with length 10
 * @return the string
 */
char* randStr(){
	static int MAX_LENGTH = 10;
	char* string = malloc(MAX_LENGTH);
	for(int i = 0; i < MAX_LENGTH; i++){
		*(string++) = randChar();
	}
	*string = '\0';//null-terminate
	string -= MAX_LENGTH;
	return string;
}

/**
 * generate a random character using numeric code
 * @return a random character
 */
char randChar(){
	int numCode = rand()%26;
	if(numCode < 0)
		numCode += 26;
	numCode += 97;//lower-case letter
	char character = (char)numCode;
	return character;
}

/**
 * generate an array of random employees
 * @param count the number of employees we need to generate
 * @return the array of pointer points to employees
 */
struct Employee** employeeArray(int count){
	struct Employee** arrayptr = malloc(sizeof(struct Employee*)*count);
	for(int i = 0; i < count; i++){
		*(arrayptr++) = randEmployee();
	}
	arrayptr-=count;
	return arrayptr;
}

/**
 * print an array of pointers point to Employee
 * @param eArr array of pointers point to Employee
 * @param count the size of array
 */
void printArray(struct Employee** eArr, int count){
	for(int i = 0; i < count; i++){
		printEmployee(*(eArr++));
	}
}

/**
 * duplicate an array of pointers
 * @param eArr the array of pointers point to Employee
 * @param count the size of the array
 * @return new array of pointers after duplicated
 */
struct Employee** duplicate(struct Employee** eArr, int count){
	struct Employee** arrayptr = malloc(sizeof(struct Employee**)*count);
	for(int i = 0; i < count; i++){
		*(arrayptr++) = *(eArr++);
	}
	arrayptr-=count;
	return arrayptr;
}

/**
 * free an array of pointers point to Employee, and everything those pointers point to
 * Do not call it if the array has not been malloc
 * @param eArr the array of pointers point to Employee
 * @param count the size of the array
 */
void freeThem(struct Employee** eArr, int count){
	//free pointers
	for(int i = 0; i < count; i++){
		free(*(eArr++));
	}
	//free array itself
	eArr-=count;
	free(eArr);
}

/**
 * copy an array of poiners, also duplicate the strcut
 * @param eArr the array of pointers point to Employee
 * @param count the size of the array
 * @return new array of pointers after duplicated
 */
struct Employee** deepCopy(struct Employee** eArr, int count){
	struct Employee** arrayptr = malloc(sizeof(struct Employee**)*count);
	for(int i = 0; i < count; i++){
		//make a new Employee each time, and put the value into it
		*(arrayptr++) = makeEmployee((*eArr)->birth_year, (*eArr)->start_year, (*eArr)->name);
		eArr++;
	}
	arrayptr-=count;
	return arrayptr;
}
