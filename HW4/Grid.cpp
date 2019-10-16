/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: student
 */

#include <iostream>
#include <iomanip>
#include "Grid.h"
#include "Cell.h"
#include "Doodlebug.h"
#include "Ant.h"

int n=0; //this initial value will be changed when the program is invoked
Cell** myGridCells_ptr_array = (Cell**)nullptr;

Grid::Grid() {
	// TODO Auto-generated constructor stub
	Grid(10); //calls general constructor with default value
}
/**
 * set the size of grid and generate the grid
 * @param nSquaresOnASide the row and column of the grid
 */
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid

	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			myGridCells_ptr_array[r][c].setRowAndColumn(r, c);
		}
	}


}

/**
 * get the grid size
 * @return the grid size
 */
int Grid::getSize(){
	return n;
}
/**
 * set the occupantStatus of a specific cell
 * @param r the row
 * @param c the column
 * @param g the occupantStatus
 * @return true after setting
 */
bool Grid::setCellOccupant(int r, int c, occupationStatus g)
{
	return myGridCells_ptr_array[r][c].setOccupant(g);
}

/**
 * get the occupantStatus in a given position
 * @param r the row
 * @param c the column
 * @return the occupantStatus in the given position
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}

/** Puts the pointer to an Organism into the Cell at the row and column.
 * @param r the row
 * @param c the column
 * @param organ the pointers points to an Organism
 */
void Grid::setCellOrganism(int r, int c, Organism* organ) {
	 myGridCells_ptr_array[r][c].setOrganism(organ);
}

/**
 * get the pointer to an Organism in the given cell
 * @param r the row of the cell
 * @param c the column of the cell
 * @return the pointer to an Organism in the cell
 */
Organism* Grid::getCellOrganism(int r, int c){
	return myGridCells_ptr_array[r][c].getOrganism();
}

/**
 * get the specified cell
 * @param r the row
 * @param c the column
 * @return Pointer to specified Cell
 */
Cell* Grid::getCell(int r, int c){
	return &myGridCells_ptr_array[r][c];
}

/**
 * generate given number of organisms in random position(ant or doodlebug)
 * @param num the number
 * @param ifAnt if the organisms is ant or not
 */
void Grid::randOrgan(int num, bool ifAnt){
	for(int i = 0; i < num; i++){
		int row = -1;
		int col = -1;
		//if already occupied or out off grid, get another pair of random location
		while(row == -1 ||
				col == -1 ||
				myGridCells_ptr_array[row][col].getOccupant() != empty){
		row = rand()%n;
		if(row < 0)
			row += n;
		col = rand()%n;
		if(col < 0)
			col += n;
		}
		if(ifAnt){
			Ant* org = new Ant(row,col);
			myGridCells_ptr_array[row][col].setOrganism((Organism*)(org));
			myGridCells_ptr_array[row][col].setOccupant(ant);

		}else{
			Doodlebug* org = new Doodlebug(row,col);
			myGridCells_ptr_array[row][col].setOrganism((Organism*)(org));
			myGridCells_ptr_array[row][col].setOccupant(doodlebug);
		}
	}
}

/**
 * print the Grid
 * @param gridSize the size of the grid
 * @param grid the grid
 */
void Grid::printGrid(){
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			occupationStatus o = getCellOccupant(row, col);
			if(o == empty)
				std::cout << " ";
			else if(o == ant)
				std::cout << "o";
			else
				std::cout << "x";
		}std::cout << "\n";
	}
	puts("============================");
}
Grid::~Grid() {

	for(int r=0; r < n; r++)
	{
		for(int c=0; c < n; c++)
		{
			//cout << "Before freeing" << r << c << endl;
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
	//myGridCells_ptr_array = (Cell**)nullptr;
}

