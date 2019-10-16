/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>


Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10;
	return results;
}

/**
 * test the grid
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	myGrid.~Grid();
	result = ok1 && ok2;
	if(result)
		puts("GridTest Passed!");
	return result;
}

/**
 * test the makeAnts
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4);
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, ant);
	myGrid_p->setCellOrganism(3, 4, a1);
	if(myGrid_p->getCellOccupant(3, 4)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	if(result)
		puts("MakeAntTest Passed!");
	return result;
}

/**
 * test the antsMove
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::antsMoveTest()
{
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	std::cout << "Running the move ants test" << std::endl;

	//when there is no neighbor
	Grid* myGrid = new Grid(9);
	Ant* a1 = new Ant(1,1);
	myGrid->setCellOrganism(1, 1, a1);
	myGrid->setCellOccupant(1, 1, ant);
	a1->move(myGrid);
	if(myGrid->getCellOrganism(0,1) == a1 ||
			myGrid->getCellOrganism(1, 0) == a1 ||
			myGrid->getCellOrganism(1, 2) == a1 ||
			myGrid->getCellOrganism(2, 1) == a1){
		ok1 = true;
	}
	//when there is a neighbor
	myGrid = new Grid(9);
	Ant* a2 = new Ant(1,1);
	myGrid->setCellOrganism(1, 1, a2);
	myGrid->setCellOccupant(1, 1, ant);
	Ant* a3 = new Ant(0,1);
	myGrid->setCellOrganism(0, 1, a3);
	myGrid->setCellOccupant(0, 1, ant);
	a2->move(myGrid);
	if(myGrid->getCellOrganism(0, 1) == a3 &&(
			myGrid->getCellOrganism(1, 0) == a2 ||
			myGrid->getCellOrganism(1, 2) == a2 ||
			myGrid->getCellOrganism(2, 1) == a2)){
		ok2 = true;
	}
	//when it is surrounded
	myGrid = new Grid(9);
	Ant* a4 = new Ant(1,1);
	myGrid->setCellOrganism(1, 1, a4);
	myGrid->setCellOccupant(1, 1, ant);
	Ant* a5 = new Ant(0,1);
	myGrid->setCellOrganism(0, 1, a5);
	myGrid->setCellOccupant(0, 1, ant);
	Ant* a6 = new Ant(1,0);
	myGrid->setCellOrganism(1, 0, a6);
	myGrid->setCellOccupant(1, 0, ant);
	Ant* a7 = new Ant(2,1);
	myGrid->setCellOrganism(2, 1, a7);
	myGrid->setCellOccupant(2, 1, ant);
	Ant* a8 = new Ant(1,2);
	myGrid->setCellOrganism(1, 2, a8);
	myGrid->setCellOccupant(1, 2, ant);
	a4->move(myGrid);
	if(myGrid->getCellOrganism(0, 1) == a5 &&
			myGrid->getCellOrganism(1, 0) == a6 &&
			myGrid->getCellOrganism(1, 2) == a8 &&
			myGrid->getCellOrganism(2, 1) == a7 &&
			myGrid->getCellOrganism(1, 1) == a4){
		ok3 = true;
	}
	result = ok1 && ok2 &&ok3;
	delete(a1);
	delete(a2);
	delete(a3);
	delete(a4);
	delete(a5);
	delete(a6);
	delete(a7);
	delete(a8);
	delete(myGrid);
	if(result)
		puts("AntMoveTest Passed!");
	return result;
}
/**
 * test the antsBreed
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::antsBreedTest()
{
	bool result = false;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	std::cout << "Running the breed ants test" << std::endl;
	//when all 4 neighbors are empty
	Grid* myGrid = new Grid(3);
	Ant* a1 = new Ant(1,1);
	myGrid->setCellOrganism(1, 1, a1);
	myGrid->setCellOccupant(1, 1, ant);
	a1->setSurvive(3);
	a1->breed(myGrid);
	if(myGrid->getCellOccupant(0, 1) == ant ||
			myGrid->getCellOccupant(1, 0) == ant ||
			myGrid->getCellOccupant(1, 2) == ant ||
			myGrid->getCellOccupant(2, 1) == ant){
		ok1 = true;
	}
	//when it is in the corner and has one neighbor
	myGrid = new Grid(3);
	Ant* a2 = new Ant(0,0);
	myGrid->setCellOrganism(0, 0, a2);
	myGrid->setCellOccupant(0, 0, ant);
	Ant* a3 = new Ant(1,0);
	myGrid->setCellOrganism(1, 0, a3);
	myGrid->setCellOccupant(1, 0, ant);
	a2->setSurvive(3);
	a2->breed(myGrid);
	if(myGrid->getCellOccupant(0, 1) == ant)
		ok2 = true;
	//when it has no available position
	myGrid = new Grid(3);
	Ant* a4 = new Ant(0,0);
	myGrid->setCellOrganism(0, 0, a4);
	myGrid->setCellOccupant(0, 0, ant);
	Ant* a5 = new Ant(1,0);
	myGrid->setCellOrganism(1, 0, a5);
	myGrid->setCellOccupant(1, 0, ant);
	Ant* a6 = new Ant(0,1);
	myGrid->setCellOrganism(0, 1, a6);
	myGrid->setCellOccupant(0, 1, ant);
	a4->setSurvive(3);
	if(!a4->breed(myGrid))
		ok3 = true;
	result = ok1 && ok2 && ok3;
	delete(myGrid);
	delete(a1);
	delete(a2);
	delete(a3);
	delete(a4);
	delete(a5);
	delete(a6);
	if(result)
		puts("AntBreedTest Passed!");
	return result;
}
/**
 * test the antsDie
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	Grid* myGrid = new Grid(3);
	Doodlebug* d1 = new Doodlebug(1,1);
	myGrid->setCellOccupant(1, 1, doodlebug);
	myGrid->setCellOrganism(1, 1, d1);
	Ant* a1 = new Ant(0,1);
	myGrid->setCellOrganism(0, 1, a1);
	myGrid->setCellOccupant(0, 1, ant);
	d1->move(myGrid);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(myGrid->getCellOrganism(i, j)==a1)
				result = false;
		}
	}
	if(result)
		puts("AntsDietest Passed!");
	return result;
}
/**
 * test the makeDoodles
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	bool ok1 = true;
	bool ok2 = true;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, doodlebug);
	if(myGrid_p->getCellOccupant(1, 2)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok1 = false;
	}
	Doodlebug* d1 = new Doodlebug(3,4);
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	myGrid_p->setCellOrganism(3, 4, d1);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	delete d1;
	delete myGrid_p;
	result = ok1 && ok2;
	if(result)
		puts("MakeDoodlesTest Passed!");
	return result;
}
/**
 * test the doodleMove
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;

	//when there is no neighbor
	Grid* myGrid = new Grid(9);
	Doodlebug* d1 = new Doodlebug(1,1);
	myGrid->setCellOrganism(1, 1, d1);
	myGrid->setCellOccupant(1, 1, doodlebug);
	d1->move(myGrid);
	if(myGrid->getCellOrganism(0,1) == d1 ||
			myGrid->getCellOrganism(1, 0) == d1 ||
			myGrid->getCellOrganism(1, 2) == d1 ||
			myGrid->getCellOrganism(2, 1) == d1){
		ok1 = true;
	}
	//when there is a neighbor
	myGrid = new Grid(9);
	Doodlebug* d2 = new Doodlebug(1,1);
	myGrid->setCellOrganism(1, 1, d2);
	myGrid->setCellOccupant(1, 1, doodlebug);
	Doodlebug* d3 = new Doodlebug(0,1);
	myGrid->setCellOrganism(0, 1, d3);
	myGrid->setCellOccupant(0, 1, doodlebug);
	d2->move(myGrid);
	if(myGrid->getCellOrganism(0, 1) == d3 &&(
			myGrid->getCellOrganism(1, 0) == d2 ||
			myGrid->getCellOrganism(1, 2) == d2 ||
			myGrid->getCellOrganism(2, 1) == d2)){
		ok2 = true;
	}
	//when it is surrounded
	myGrid = new Grid(9);
	Doodlebug* d4 = new Doodlebug(1,1);
	myGrid->setCellOrganism(1, 1, d4);
	myGrid->setCellOccupant(1, 1, doodlebug);
	Doodlebug* d5 = new Doodlebug(0,1);
	myGrid->setCellOrganism(0, 1, d5);
	myGrid->setCellOccupant(0, 1, doodlebug);
	Doodlebug* d6 = new Doodlebug(1,0);
	myGrid->setCellOrganism(1, 0, d6);
	myGrid->setCellOccupant(1, 0, doodlebug);
	Doodlebug* d7 = new Doodlebug(2,1);
	myGrid->setCellOrganism(2, 1, d7);
	myGrid->setCellOccupant(2, 1, doodlebug);
	Doodlebug* d8 = new Doodlebug(1,2);
	myGrid->setCellOrganism(1, 2, d8);
	myGrid->setCellOccupant(1, 2, doodlebug);
	d4->move(myGrid);
	if(myGrid->getCellOrganism(0, 1) == d5 &&
			myGrid->getCellOrganism(1, 0) == d6 &&
			myGrid->getCellOrganism(1, 2) == d8 &&
			myGrid->getCellOrganism(2, 1) == d7 &&
			myGrid->getCellOrganism(1, 1) == d4){
		ok3 = true;
	}
	result = ok1 && ok2 &&ok3;
	delete(d1);
	delete(d2);
	delete(d3);
	delete(d4);
	delete(d5);
	delete(d6);
	delete(d7);
	delete(d8);
	delete(myGrid);
	if(result)
		puts("DoodlebugMoveTest Passed!");
	return result;
}
/**
 * test the doodleBreed
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	bool ok1 = false;
	bool ok2 = false;
	bool ok3 = false;
	//when all 4 neighbors are empty
	Grid* myGrid = new Grid(3);
	Doodlebug* d1 = new Doodlebug(1,1);
	myGrid->setCellOrganism(1, 1, d1);
	myGrid->setCellOccupant(1, 1, doodlebug);
	d1->setSurvive(8);
	d1->breed(myGrid);
	if(myGrid->getCellOccupant(0, 1) == doodlebug ||
			myGrid->getCellOccupant(1, 0) == doodlebug ||
			myGrid->getCellOccupant(1, 2) == doodlebug ||
			myGrid->getCellOccupant(2, 1) == doodlebug){
		ok1 = true;
	}
	//when it is in the corner and has one neighbor
	myGrid = new Grid(3);
	Doodlebug* d2 = new Doodlebug(0,0);
	myGrid->setCellOrganism(0, 0, d2);
	myGrid->setCellOccupant(0, 0, doodlebug);
	Doodlebug* d3 = new Doodlebug(1,0);
	myGrid->setCellOrganism(1, 0, d3);
	myGrid->setCellOccupant(1, 0, doodlebug);
	d2->setSurvive(8);
	d2->breed(myGrid);
	if(myGrid->getCellOccupant(0, 1) == doodlebug)
		ok2 = true;
	//when it has no available position
	myGrid = new Grid(3);
	Doodlebug* d4 = new Doodlebug(0,0);
	myGrid->setCellOrganism(0, 0, d4);
	myGrid->setCellOccupant(0, 0, doodlebug);
	Doodlebug* d5 = new Doodlebug(1,0);
	myGrid->setCellOrganism(1, 0, d5);
	myGrid->setCellOccupant(1, 0, doodlebug);
	Doodlebug* d6 = new Doodlebug(0,1);
	myGrid->setCellOrganism(0, 1, d6);
	myGrid->setCellOccupant(0, 1, doodlebug);
	d4->setSurvive(3);
	if(!d4->breed(myGrid))
		ok3 = true;
	result = ok1 && ok2 && ok3;
	delete(myGrid);
	delete(d1);
	delete(d2);
	delete(d3);
	delete(d4);
	delete(d5);
	delete(d6);
	if(result)
		puts("DoodlebugBreedTest Passed!");
	return result;
}
/**
 * test the doodleEat
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	Grid* myGrid = new Grid(3);
	Doodlebug* d1 = new Doodlebug(1,1);
	myGrid->setCellOccupant(1, 1, doodlebug);
	myGrid->setCellOrganism(1, 1, d1);
	Ant* a1 = new Ant(0,1);
	myGrid->setCellOrganism(0, 1, a1);
	myGrid->setCellOccupant(0, 1, ant);
	d1->move(myGrid);
	if(myGrid->getCellOccupant(0, 1) == doodlebug)
		result = true;
	if(result)
		puts("DoodleEatTest Passed!");
	return result;
}
/**
 * test the doodleDie
 * @return true if all tests passed
 * @return false otherwise
 */
bool Tests2::doodleDietest()
{
	bool result = false;
	std::cout << "Running the doodlebug dies test" << std::endl;
	Grid* myGrid = new Grid(3);
	Doodlebug* d1 = new Doodlebug(1,1);
	myGrid->setCellOccupant(1, 1, doodlebug);
	myGrid->setCellOrganism(1, 1, d1);
	d1->setNoEat(3);
	if(d1->starvation(myGrid))
		result = true;
	if(result)
		puts("DoodleDieTest Passed!");
	return result;
}

Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

