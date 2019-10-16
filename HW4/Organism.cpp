/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Organism.h"

bool amAnt = false;


Organism::Organism() {
	// TODO Auto-generated constructor stub

}
Organism::Organism(bool b) {
	amAnt = b;

}

/**
 * check if the gust a prey(ant)
 * @return true if it is a prey
 * @return false otherwise
 */
bool Organism::isPrey()
{
	return amAnt;
}

/**
 * set an organism an ant or not
 * @param b if the organism is an ant
 */
void Organism::setAmAnt(bool b)
{
	amAnt = b;
}

Organism::~Organism() {
	// TODO Auto-generated destructor stub

}

