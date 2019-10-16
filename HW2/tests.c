/*
 * tests.c
 *
 *  Created on: Nov 3, 2018
 *      Author: student
 */
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for strncmp

/**
 * test the program
 * @return true if all tests pass
 * @return false otherwise
 */
bool tests(void)
{
	bool results=false;
	puts("During tests");
	bool ok1 = testReadInput();
	if(ok1)puts("Found and read the test file.");
	bool ok2 = testMakeArrays();
	if(ok2)puts("Was able to allocate the arrays ok.");
	bool ok3 = testPlayOne();
	if(ok3)puts("playOne is ok.");
	testPrintThis();
	bool ok4 = testSameContent();
	if(ok4)puts("sameContent is ok.");
	bool ok5 = testAnyX();
	if(ok5)puts("anyX is ok.");
	puts("end of tests");
	results = ok1 && ok2 && ok3 && ok4 && ok5;
	printf("tests returning %d.\n",results);
	return results;
}

/**
 * test if we could read the file
 * @return true if we successfully read the file
 * @return false otherwise
 */
bool testReadInput(void)
{
	//the plan is:
	//create a file
	//make sure it can be opened.
	//try a file that should not exist
	//check that we notice it does not exist

	bool results = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	//
	//Here goes: create a file
	FILE* fp;
	fp = fopen("/tmp/LifeInput.txt", "w"); //we write it first for later reading
	if (fp != false)
	{//it opened, yay!
		//file containing a sequence of lines,
		//each consisting of a sequence of 'x' and 'o' characters,
		//indicating the occupied and unoccupied cells
		//of the initial configuration, e.g.
		//oxo
		//xox
		//xox
		//oxo
		int w1 = fprintf(fp, "oxo\n");//returns the number of chars excluding null
		int w2 = fprintf(fp, "xox\n");
		int w3 = fprintf(fp, "xox\n");
		int w4 = fprintf(fp, "oxo\n");
		if ((w1 == w2) && (w2 == w3) && (w3 == w4) && (w4 == 4))
		{
			ok1 = true;
		}
		fclose(fp);
	}
	fp = fopen("/tmp/LifeInput.txt", "r"); //we try to read it
	if (fp != false)
	{//it opened, yay!
		ok2 = true;
		//can we read the correct data?
		char oRow[4]; //test case, we know a string of 3 chars terminated by null
		int count =  fscanf(fp, "%s", oRow);
//		printf("First row is %s\n", oRow);
		if(0==strncmp(oRow, "oxo", 4))//0 means match
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Second row is %s\n", oRow);
		if(0==strncmp(oRow, "xox", 4))
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Third row is %s\n", oRow);
		if(0==strncmp(oRow, "xox", 4))
		{//got the right data
			ok3 = true;
		}
		fscanf(fp, "%s", oRow);
		//printf("Fourth row is %s\n", oRow);
		if(0==strncmp(oRow, "oxo", 4))
		{//got the right data
			ok3 = true;
		}
	}
	results = ok1 && ok2 && ok3;
	return results;
}

/**
 * test if we make correct arrays
 * @return true if we make the array right
 * @return false otherwise
 */
bool testMakeArrays(void)
{
	bool results = false;
	bool ok1 = false;
	//we need to allocate and populate arrays
	//In this test case we set our arrays to 4 rows x3 columns
	int nRows = 4;
	int nCols = 4;
	char boardBefore[4][4]={
			{'o','x','o','\0'},
			{'x','o','x','\0'},
			{'x','o','x','\0'},
			{'o','x','o','\0'}
	};

	char boardAfter[nRows][nCols];
	//here's the test
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			boardAfter[row][col]=boardBefore[row][col];
		}
	}
	ok1 = true;
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if (boardAfter[row][col]!=boardBefore[row][col])
			{
				ok1=false;
			}
		}
	}

	results = ok1;
	return results;
}

/**
 * test function PlayOne
 * @return true if we get the right answer after called PlayOne
 * @return false otherwise
 */
bool testPlayOne(void)
{
	bool results = false;
	bool ok1 = false;
	bool ok2 = false;


	int nRows = 4;
	int nCols = 3;

	//no change after called PlayOne
	char boardBefore[4][3]={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};
	char correctBoardAfter[4][3]={
			{'o','x','o'},
			{'x','o','x'},
			{'x','o','x'},
			{'o','x','o'}
	};

	char boardAfter[nRows][nCols];
	//here's the invocation
	PlayOne(nRows, nCols, (char*)boardBefore, (char*)boardAfter);
	//here's the check
	ok1 = true; //no errors found yet
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if(boardAfter[row][col]!=correctBoardAfter[row][col])
			{//error found
				ok1 = false;
			}
		}
	}

	nRows = 4;
	nCols = 4;
	//changed after called PlayOne
	char boardBefore2[4][4]={
			{'o','x','o','o'},
			{'o','x','o','o'},
			{'o','x','o','o'},
			{'o','o','o','o'}
	};
	char correctBoardAfter2[4][4]={
			{'o','o','o','o'},
			{'x','x','x','o'},
			{'o','o','o','o'},
			{'o','o','o','o'}
	};

	char boardAfter2[nRows][nCols];
	//here's the invocation
	PlayOne(nRows, nCols, (char*)boardBefore2, (char*)boardAfter2);
	//here's the check
	ok2 = true; //no errors found yet
	for(int row=0;row<nRows;row++)
	{
		for(int col=0; col<nCols; col++)
		{
			if(boardAfter2[row][col]!=correctBoardAfter2[row][col])
			{//error found
				ok2 = false;
			}
		}
	}
	results = ok1 && ok2;
	return results;
}

/**
 * test function printThis, see if the console print the given board
 */
void testPrintThis(void){
	char board[3][3]={
				{'o','x','o'},
				{'o','x','o'},
				{'o','x','o'}
		};
	printThis(3,3,(char*)board);
}

/**
 * test function sameContent
 * @return true if sameContent return true when 2 boards have same content
 * @return false otherwise
 */
bool testSameContent(void){
	bool results = false;
	char board1[3][3]={
					{'o','x','o'},
					{'o','x','o'},
					{'o','x','o'}
			};
	char board2[3][3]={
					{'o','o','o'},
					{'o','x','o'},
					{'o','x','o'}
			};
	//same
	bool ok1 = sameContent((char*)board1, (char*)board1,3,3);
	//not same
	bool ok2 = sameContent((char*)board1, (char*)board2,3,3);
	if(ok1 && !ok2){
		results = true;
	}
	return results;
}

/**
 * test function anyX
 * @return true if anyX return true when there is x in the board
 * @return false otherwise
 */
bool testAnyX(void){
	bool results = false;
	char board1[3][3]={
						{'o','x','o'},
						{'o','o','o'},
						{'o','o','o'}
				};
	char board2[3][3]={
						{'o','o','o'},
						{'o','o','o'},
						{'o','o','o'}
				};
	//with x
	bool ok1 = anyX((char*)board1, 3,3);
	//without x
	bool ok2 = anyX((char*)board2, 3,3);
	if(ok1 && !ok2){
		results = true;
	}
	return results;
}

