/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"
#include "Organism.h"

class Grid {
public:
	Grid();
	Grid(int nSquaresOnASide);
//	Ant* getAntArr();
	bool setCellOccupant(int r, int c, occupationStatus g);
	int getSize();
	occupationStatus getCellOccupant(int r, int c);
	Organism* getCellOrganism(int r, int c);
	void setCellOrganism(int r, int c, Organism* organ);
	void randOrgan(int num, bool ifAnt);
	void printGrid();
	virtual ~Grid();
	Cell* getCell(int r, int c);
};

#endif /* GRID_H_ */
