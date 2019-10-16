/*
 * tests.c
 *
 *  Created on: Feb 4, 2019
 *      Author: ciaraldi
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

bool tests(void)
{
	bool ok = false;

	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed.");
	}

	bool ok2 = testMakeEmployee();
	if (ok2) {
		puts("makeEmployee() passed.");
	}

	bool ok3 = testRandEmployee();
	if(ok3){
		puts("randEmployee() passed.");
	}

	bool ok4 = testEmployeeArray();
	if(ok4){
		puts("employeeArray() passed.");
	}

	bool ok5 = testDuplicate();
	if(ok5){
		puts("duplicate() passed.");
	}

	bool ok6 = testDeepCopy();
	if(ok6){
		puts("deepCopy() passed");
	}
	ok = ok1 && ok2 && ok3 && ok4 && ok5 && ok6; // Did all tests pass?
	return ok;
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */

bool testPrintEmployee() {

	struct Employee e; // Variable to hold employee
	e.birth_year = 1952; // Put data into numeric fields
	e.start_year = 1999;
	// Copy into string field. Be sure not to overflow it.
	strncpy(e.name, "Mike Ciaraldi", MAX_NAME);
	e.name[MAX_NAME] = '\0'; // Be sure string is terminated.

	printEmployee(&e);

	return true;
}


/** Test the make Employee() function by making an employee with known data and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee() {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);

	return true;
}

/**
 * Test RandEmployee() by printing it out
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testRandEmployee(){
	struct Employee* e;
	e = randEmployee();
	printEmployee(e);
	return true;
}

/**
 * Test employeeArray() and printArray() by printing it out
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testEmployeeArray(){
	struct Employee** arrayPtr = employeeArray(3);
	printArray(arrayPtr, 3);
	return true;
}

/**
 * test duplicate() by duplicating an array and check if the pointer point to the same struct
 * @return true if test pass
 * @return false otherwise
 */
bool testDuplicate(){
	struct Employee** arrayptr1 = employeeArray(5);
	struct Employee** arrayptr2 = duplicate(arrayptr1,5);
	for(int i = 0; i < 5; i++){
		if(*arrayptr2 != *arrayptr1)
			return false;
		arrayptr1++;
		arrayptr2++;
	}return true;
}

/**
 * test deepCopy() by copy an array and check if they points to different struct, but the
 * contents of struct are the same
 * @return true if test pass
 * @return false otherwise
 */
bool testDeepCopy(){
	struct Employee** arrayptr1 = employeeArray(5);
	struct Employee** arrayptr2 = deepCopy(arrayptr1,5);
	//strcut should be different(address), but the contents(birth,start,name) should be the same
	for(int i = 0; i < 5; i++){
		if((*arrayptr2)->birth_year != (*arrayptr1)->birth_year ||
				(*arrayptr2)->start_year != (*arrayptr1)->start_year ||
				strcmp((*arrayptr2)->name,(*arrayptr1)->name)
				|| *arrayptr2 == *arrayptr1)
			return false;
		arrayptr1++;
		arrayptr2++;
	}return true;
}
