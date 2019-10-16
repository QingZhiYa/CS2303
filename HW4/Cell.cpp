/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include "Cell.h"
#include "Organism.h"

Cell::Cell() {
	//default value
	row = -1;
	col = -1;
	guest = empty;
	ptr = (Organism*) nullptr;
}

/**
 * set the occupant of a cell
 * @param g the occupantStatus
 * @return true after setting
 */
bool Cell::setOccupant(occupationStatus g)
{
	bool result = true;
		guest = g;

	return result;
}

/**
 * get the occupantStatus
 * @return the occupantStatus of the cell
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}

/**
 * get the pointer points to the organism in the cell
 * @return the pointer points to the organism in the cell
 */
Organism* Cell::getOrganism(){
	return ptr;
}

/**
 * set the row and column of a cell
 * @param r the row
 * @param c the column
 */
void Cell::setRowAndColumn(int r, int c){
	row = r;
	col = c;
}

/**
 * get the row of the cell
 * @return the row
 */
int Cell::getRow(){
	return row;
}

/**
 * get the column of the cell
 * @return the column
 */
int Cell::getCol(){
	return col;
}
/**
 * set the pointer points to the organism in the cell
 * @param organ the pointer points to the organism in the cell
 */
void Cell::setOrganism(Organism* organ){
	ptr = organ;
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
	ptr = nullptr;
}

