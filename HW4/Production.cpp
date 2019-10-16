/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Production.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include<cmath>
#include "Grid.h"
#include "Doodlebug.h"
#include "Ant.h"
#include "Cell.h"

//default value
int gridSize = 20;
int numDoodlebugs = 5;
int numAnts = 100;
int timestepsLeft = 100; //initialize available timesteps 10
int seed = 1;
int pause = 0;


Production::Production(int argc, char* argv[]) {
	// TODO Auto-generated constructor stub

	//change argv to int
	if(argc > 1){
		char* ptr0 = 0;
		long nr_l0 = strtol(argv[1], &ptr0, 10);
		gridSize = (int)nr_l0;
	}
	if(argc > 2){
		char* ptr1 = 0;
		long nr_l1 = strtol(argv[2], &ptr1, 10);
		numDoodlebugs = (int)nr_l1;
	}
	if(argc > 3){
		char* ptr2 = 0;
		long nr_l2 = strtol(argv[3], &ptr2, 10);
		numAnts = (int)nr_l2;
	}
	if(argc > 4){
		char* ptr3 = 0;
		long nr_l3 = strtol(argv[4], &ptr3, 10);
		timestepsLeft = (int)nr_l3;
	}
	if(argc > 5){
		char* ptr4 = 0;
		long nr_l4 = strtol(argv[5], &ptr4, 10);
		seed = (int)nr_l4;
	}
	if(argc > 6){
		char* ptr5 = 0;
		long nr_l5 = strtol(argv[6], &ptr5, 10);
		pause = (int)nr_l5;
	}

	srand(seed);
	//if the grid is too small to accommodate given number of bugs and ants
	if(pow(gridSize,2) < numAnts + numDoodlebugs){
		puts("The grid is too small, please input the grid size again");
		std::cin >> gridSize;
	}


}

bool Production::runProduction()
{
	int time = 0;//times of run at the end
	int initialTime = timestepsLeft;
	int newAnt = 0;//the number of new Ant generated
	int newBug = 0;//the number of new Bug generated
	int remainAnt = 0;//the number of ant remained at the end
	int remainBug = 0;//the number of bug remained at the end
	bool result = true;
	Grid* grid = new Grid(gridSize);
	//generate given number of ants and bugs in the random cell of the grid
	grid->randOrgan(numAnts,true);
	grid->randOrgan(numDoodlebugs,false);
	puts("\nAt the beginning:");
	grid->printGrid();
	//avoiding check the same organism twice, put everything we've checked in an array
	Ant* currentAnt;
	Doodlebug* currentBug;
	int bugsVisited = 0; //keep this as the amount of bugs you have visited
	Ant* antArr[gridSize*gridSize] = {nullptr};
	int antVisited = 0;
	Doodlebug* bugArr[gridSize*gridSize] = {nullptr};

	while(timestepsLeft > 0){
		//bug move
		for(int row = 0; row < gridSize; row++){
			for(int col = 0; col < gridSize; col++){
				if(grid->getCellOccupant(row, col) == doodlebug){
					bool ifCheck = false;//does it in the list we've checked
					for(int i = 0; i < bugsVisited; i++){
						if(grid->getCellOrganism(row, col) == bugArr[i]){
							ifCheck = true;
							break;
						}
					}
					if(!ifCheck){
						currentBug = (Doodlebug*)grid->getCellOrganism(row, col);
						bugArr[bugsVisited++] = currentBug;
						currentBug->move(grid);

					}
				}
			}

		}
		//bug breed
		for(int row = 0; row < gridSize; row++){
			for(int col = 0; col < gridSize; col++){
				if(grid->getCellOccupant(row, col) == doodlebug){
					//bug starvation
					if(grid->getCellOrganism(row, col)->starvation(grid)){
						delete(grid->getCellOrganism(row, col));//remove it
					}else if(grid->getCellOrganism(row, col)->breed(grid)){
						newBug++;
					}
				}
			}
		}
		//clear the visited list
		for(int i = 0; i < bugsVisited; i++){
			bugArr[i] = nullptr;
		}
		bugsVisited = 0;
		//ant move
		for(int row = 0; timestepsLeft>0 && row < gridSize; row++){
			for(int col = 0; timestepsLeft>0 && col < gridSize; col++){
				if(grid->getCellOccupant(row, col) == ant){
					bool ifCheck = false;//does it in the list we've checked
					for(int i = 0; i < antVisited; i++){
						if(grid->getCellOrganism(row, col) == antArr[i]){
							ifCheck = true;
							break;
						}
					}
					if(!ifCheck){
						currentAnt = (Ant*)grid->getCellOrganism(row, col);
						antArr[antVisited++] = currentAnt;
						currentAnt->move(grid);

					}
				}
			}
		}
		//ant breed
		for(int row = 0; row < gridSize; row++){
			for(int col = 0; col < gridSize; col++){
				if(grid->getCellOccupant(row, col) == ant &&
						grid->getCellOrganism(row, col)->breed(grid)){
					newAnt++;
				}
			}
		}
		//clear the visited list
		for(int i = 0; i < antVisited; i++){
			antArr[i] = nullptr;
		}
		antVisited = 0;
		timestepsLeft--;
		time++;
		//pause everything given number time
		if(pause > 0 && (time % pause == 0)){
			grid->printGrid();
			puts("Paused waiting for input.");
			getc(stdin);
		}

	}
	//get the numbers of remainning ants and bugs at the end
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridSize; j++){
			if(grid->getCellOccupant(i, j) == ant)
				remainAnt++;
			else if(grid->getCellOccupant(i,j) == doodlebug)
				remainBug++;
		}
	}
	//print the information
	std::cout << "The original commend line: " << gridSize << " "<< numDoodlebugs <<" "<<
			numAnts << " "<< initialTime << " " << seed << " "<< pause << std::endl;
	std::cout << "Simulated " << time << " steps." <<std::endl;
	std::cout << "There are " << numAnts + newAnt<< " ants in total duing the simulation." << std::endl;
	std::cout << "There are " << remainAnt<< " ants remainning." << std::endl;
	std::cout << "There are " << numAnts + newBug<< " doodlebugs in total duing the simulation." << std::endl;
	std::cout << "There are " << remainBug << " doodlebugs remainning." << std::endl;
	std::cout << "Final grid:" << std::endl;
	grid->printGrid();


	return result;
}





Production::~Production() {
	// TODO Auto-generated destructor stub
}

