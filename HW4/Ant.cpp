/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#include <stdlib.h>
#include "Ant.h"
#include "Grid.h"
#include "Cell.h"

Ant::Ant()
:Organism(true)
{
	row = -1;//default value
	col = -1;
}


Ant::Ant(int r, int c)
:Organism(true)
{
	row = r;
	col = c;
}


/**
 * ant move
 * @param grid the grid
 * @return true if it moved
 * @return false otherwise
 */
bool Ant::move(Grid* grid)
{
	bool status = true;
	survive++;
	Cell* choice = randPosition(grid);
	if(choice == nullptr){
		//no available space
		status = false;
	}else{
		choice->setOrganism(this);
		choice->setOccupant(ant);
		grid->setCellOrganism(row, col, nullptr);
		// Must set occupationStatus of old and new cells.
		grid->setCellOccupant(row, col, empty);
		// Must update row and col in this Ant.
		row = choice->getRow();
		col = choice->getCol();

	}

	return status;
}


/**
 * randomly select from available neighbor cells
 * @param grid the grid
 * @return Pointer to a cell we randomly selected
 */
Cell* Ant::randPosition(Grid* grid){
	//create an array and put all neighbor cells
	int availableNum = 0;
	Cell* availableCell[4];
	if(moveable(row+1,col, grid)){
		availableCell[availableNum] = grid->getCell(row+1, col);
		availableNum ++;
	}
	if(moveable(row,col-1, grid)){
		availableCell[availableNum] = grid->getCell(row,col-1);
		availableNum ++;
	}
	if(moveable(row-1,col, grid)){
		availableCell[availableNum] = grid->getCell(row-1,col);
		availableNum ++;
	}
	if(moveable(row,col+1, grid)){
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
 * if an ant could move to the given cell
 * @param r the row of the cell
 * @param c the column of the cell
 * @param grid the grid
 * @return true if the given cell is empty('moveable')
 * @return false otherwise
 */
bool Ant::moveable(int r, int c, Grid* grid){
	//not out of grid
	if(r < (*grid).getSize() &&
			c < (*grid).getSize() &&
			r >= 0 &&
			c >= 0 &&
			(*grid).getCellOccupant(r,c) == empty){
		return true;
	}else{
		return false;
	}
}

/**
 * if the ant should breed or not(survive at least three time steps)
 * @param grid the grid
 * @return true if it breed
 * @return false otherwise
 */
bool Ant::breed(Grid* grid)
{
	bool status = false;
	if(survive >= 3){
		//position for the new-born ant
		Cell* babyPos = randPosition(grid);
		if(babyPos != nullptr){
			Ant* baby = new Ant(babyPos->getRow(),babyPos->getCol());
			(*babyPos).setOrganism(baby);
			(*babyPos).setOccupant(ant);
			survive = 0;
			status = true;
		}
	}
	return status;
}

/**
 * set the survive value(for testing)
 * @param n the number we'd like to set
 */
void Ant::setSurvive(int n){
	survive = n;
}

/**
 * if the ant is starve or not(never be true, implement the pure virtual function)
 * @return false
 */
bool Ant::starvation(Grid* grid){
	return false;
}


Ant::~Ant() {
	// TODO Auto-generated destructor stub

}



