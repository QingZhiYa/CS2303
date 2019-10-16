/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include "Cell.h"

class Doodlebug: public Organism {

private:
	int row = 0;
	int col = 0;
	int survive = 0;
	int noEat = 0;
	bool ifThisType(int r, int c, Grid* grid, occupationStatus o);
	Cell* randPosition(Grid* grid, occupationStatus o);

public:
	Doodlebug();
	Doodlebug(int r, int c);
	void setSurvive(int n); //for testing
	void setNoEat(int n);//for testing
	bool move(Grid* grid);
	bool breed(Grid* grid);
	bool starvation(Grid* grid);
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
