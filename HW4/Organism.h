/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
class Grid;

class Organism {
public:
	Organism();
	Organism(bool b);
	bool isPrey();
	virtual bool move(Grid* grid)=0;
	virtual bool breed(Grid* grid)=0;
	virtual bool starvation(Grid* grid) = 0;
	void setAmAnt(bool b);
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
