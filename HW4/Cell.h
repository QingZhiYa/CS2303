/*
 * Cell.h
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#ifndef CELL_H_
#define CELL_H_

class Organism;

enum occupationStatus { empty, ant, doodlebug};

class Cell {

private:
	occupationStatus guest; // Type of Organism currently in this cell
	Organism* ptr; // Pointer to the Organism object currently in this Cell
	int row;
	int col;

public:

	Cell();
	void setRowAndColumn(int r, int c);
	int getRow();
	int getCol();
	bool setOccupant(occupationStatus g);
	occupationStatus getOccupant();
	Organism* getOrganism();
	void setOrganism(Organism* organ);
	virtual ~Cell();
};

#endif /* CELL_H_ */
