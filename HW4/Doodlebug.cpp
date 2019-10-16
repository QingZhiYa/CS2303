/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include "Doodlebug.h"
#include <stdlib.h>
#include "Grid.h"
#include "Cell.h"

Doodlebug::Doodlebug()
:Organism(false){
	// TODO Auto-generated constructor stub
	//default value
	row = -1;
	col = -1;

}


Doodlebug::Doodlebug(int r, int c)
:Organism(false) {
	row = r;
	col = c;

}
/**
 * doodlebug move
 * check if there's any ant first, if there is, eat it and replace its position,
 * if there is not, move
 * randomly select from "eatable cell" first, then from "moveable cell"
 * @param grid the grid doodlebug is in
 * @return true when doodlebug move
 * @return false when there is no available position to move for doodlebug
 */
bool Doodlebug::move(Grid* grid)
{
	bool status = true;
	survive++;
	//check surrounded ant first
	Cell* eatChoice = randPosition(grid, ant);
	//when no ant
	if(eatChoice == nullptr){
		noEat++;
		//check empty neighbor
		Cell* moveChoice = randPosition(grid, empty);
		//when no available space
		if(moveChoice == nullptr){
			status = false;
			return status;
		}else{
			//move but not eat
			moveChoice->setOrganism(this);
			moveChoice->setOccupant(doodlebug);
			grid->setCellOrganism(row,col,nullptr);
			// Must set occupationStatus of old and new cells.
			grid->setCellOccupant(row,col,empty);
			// Must update row and col in this Doodlebug.
			row = moveChoice->getRow();
			col = moveChoice->getCol();
			return status;
		}
	}else{
		//eat
		eatChoice->setOrganism(this);
		eatChoice->setOccupant(doodlebug);
		grid->setCellOrganism(row, col, nullptr);
		// Must set occupationStatus of old and new cells.
		grid->setCellOccupant(row, col,empty);
		// Must update row and col in this Doodlebug.
		row = eatChoice->getRow();
		col = eatChoice->getCol();
		return status;
	}
}

/**
 * check if the cell is this occupationStatus
 * @param r row of cell
 * @param c column of cell
 * @param grid the grid
 * @param o the occupationStatus we want
 * @return true if the given cell is this occupationStatus
 * @return false otherwise
 */
bool Doodlebug::ifThisType(int r, int c, Grid* grid, occupationStatus o){
	//not out off grid and the occupationStatus is right
	if(r < (*grid).getSize() &&
			c < (*grid).getSize() &&
			r >= 0 &&
			c >= 0 &&
			(*grid).getCellOccupant(r,c) == o){
		return true;
	}return false;
}

/**
 * randomly select from neighbor cells that have this occupationStatus
 * @param grid the grid
 * @param the occupationStatus we want
 * @return a cell we randomly selected
 */
Cell* Doodlebug::randPosition(Grid* grid, occupationStatus o){
	//create an array and put all neighbor cells have occupationStatus o
	int availableNum = 0;
	Cell* availableCell[4];
	if(ifThisType(row+1,col, grid, o)){
		availableCell[availableNum] = grid->getCell(row+1, col);
		availableNum ++;
	}
	if(ifThisType(row,col-1, grid, o)){
		availableCell[availableNum] = grid->getCell(row,col-1);
		availableNum ++;
	}
	if(ifThisType(row-1,col, grid, o)){
		availableCell[availableNum] = grid->getCell(row-1,col);
		availableNum ++;
	}
	if(ifThisType(row,col+1, grid, o)){
		availableCell[availableNum] = grid->getCell(row,col+1);
		availableNum ++;
	}
	//no available
	if(availableNum == 0){
		return nullptr;
	}
	int idx = rand()%availableNum;
		if(idx < 0)
			idx += availableNum;
		return (availableCell[idx]);

}

/**
 * if the ant breed or not(survive at least eight time steps)
 * @param grid the grid
 * @return true if it breed
 * @return false otherwise
 */
bool Doodlebug::breed(Grid* grid)
{
	bool status = false;
	if(survive == 8){
		//position for the new-born doodlebug
		Cell* babyPos = randPosition(grid, empty);
		if(babyPos != nullptr){
			Doodlebug* baby = new Doodlebug(babyPos->getRow(),babyPos->getCol());
			(*babyPos).setOrganism(baby);
			(*babyPos).setOccupant(doodlebug);
			survive = 0;
			status = true;
		}
	}
	return status;
}

/**
 * set the survive value(for testing)
 * @param n the number we want to set
 */
void Doodlebug::setSurvive(int n){
	survive = n;
}

/**
 * set the noEat value(for testing)
 * @param n the number we want to set
 */
void Doodlebug::setNoEat(int n){
	noEat = n;
}
/**
 * if the doodlebug is starving or not(not eat within 3 steps)
 * @return true is the doodlebug is starving
 * @return false otherwise
 */
bool Doodlebug::starvation(Grid* grid)
{
	bool status = false;
	if(noEat>= 3){
		status = true;
		grid->setCellOrganism(row, col, nullptr);
		grid->setCellOccupant(row, col, empty);

	}
	return status;
}
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

