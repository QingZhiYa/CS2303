/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: student
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"
#include "Grid.h"
#include "Cell.h"

class Ant: public Organism {
private:
	int row = 0;
	int col = 0;
	int survive = 0;
	bool moveable(int r, int c, Grid* grid);
	Cell* randPosition(Grid* grid);

public:
	Ant();
	Ant(int r=0, int c = 0);
	void setSurvive(int n);//for testing
	bool move(Grid* grid);
	bool breed(Grid* grid);
	bool starvation(Grid* grid);
	 ~Ant();
};

#endif /* ANT_H_ */
