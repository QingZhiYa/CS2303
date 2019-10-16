In this program, each grid have an array which are cells. 
Each cell has an pointer to an Organism. The organism could be ant or doodlebug or empty.
Organism could be ant or doodlebug. It has pure virtual functions: starvation, breed, move.
The ant wont starve, so the method in ant just return false.

I use function called randPosition, it could return a random position from neighbors with
specified type. Both move and breed will use that function to help the ant/bug find cell to
eat/move/breed. 

When move\breed, we just change the pointer to Organism to the original ant, and set the old
pointer to empty.

The order is: Bug move, bug starve, bug breed, ant move, ant breed.

To run the program, just run it will use defalt value. Other than that, the user could type 
the value they'd like to set in the argument.

2 Test Cases:

1st:
argument:10 20 50 100 1 10

!!!Hello the classmates, it's time for fun with C++!!!
Running the grid test
GridTest Passed!
Running the make ants test
MakeAntTest Passed!
Running the move ants test
AntMoveTest Passed!
Running the breed ants test
AntBreedTest Passed!
Running the ants die test
AntsDietest Passed!
Running the make doodlebugs test
MakeDoodlesTest Passed!
Running the move doodlebugs test
DoodlebugMoveTest Passed!
Running the breed doodlebugs test
DoodlebugBreedTest Passed!
Running the eat ant test
DoodleEatTest Passed!
Running the doodlebug dies test
DoodleDieTest Passed!

At the beginning:
   x  o xo
o o  o ooo
ox oxooooo
oo x oooxo
xx xooxooo
o  x o x o
xoooxoo oo
 ooo ooxoo
 o  ox  xx
 oooo xox 
============================
o xo  o   
oo   o  o 
  o  o  o 
o     o   
oo     x x
o oo o    
o      o  
 oo oo    
  oo      
o    o    
============================
Paused waiting for input.

oooxoooooo
oooooooooo
ooooxoooo 
ooooooooo 
ooooooooo 
ooooooooo 
ooooooooo 
oooooooo  
ooooooo o 
oooooo o  
============================
Paused waiting for input.

ooooooo oo
ooooxoo x 
ooxoooxoo 
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
============================
Paused waiting for input.

ooooooooo 
ooxoooox x
xoxoxxox x
xoooooooo 
ooooooooo 
ooxooooooo
ooxoxooooo
ooooxoxxoo
oooooooooo
oooooooooo
============================
Paused waiting for input.

 x        
o  x   oo 
   xxoo   
xo xxx    
x x     x 
    x     
 x ooxx o 
x o  oooo 
oxxxoxooo 
oo ooxooox
============================
Paused waiting for input.

ooo ooo   
ooo  oo o 
oooo o o  
o oooo   o
o ooo ooo 
o   oo  o 
    oo  o 
          
     o  o 
          
============================
Paused waiting for input.

oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
============================
Paused waiting for input.

oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
============================
Paused waiting for input.

oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
============================
Paused waiting for input.

oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
============================
Paused waiting for input.

The original commend line: 10 20 50 100 1 10
Simulated 100 steps.
There are 443 ants in total duing the simulation.
There are 100 ants remainning.
There are 83 doodlebugs in total duing the simulation.
There are 0 doodlebugs remainning.
Final grid:
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
oooooooooo
============================

2nd:
argument:10 35 50 15 1 3 

!!!Hello the classmates, it's time for fun with C++!!!
Running the grid test
GridTest Passed!
Running the make ants test
MakeAntTest Passed!
Running the move ants test
AntMoveTest Passed!
Running the breed ants test
AntBreedTest Passed!
Running the ants die test
AntsDietest Passed!
Running the make doodlebugs test
MakeDoodlesTest Passed!
Running the move doodlebugs test
DoodlebugMoveTest Passed!
Running the breed doodlebugs test
DoodlebugBreedTest Passed!
Running the eat ant test
DoodleEatTest Passed!
Running the doodlebug dies test
DoodleDieTest Passed!

At the beginning:
  xxxxoxxo
o o xo ooo
ox oxooooo
ooxxxoooxo
xx xooxooo
ox xxoxx o
xoooxooxoo
 ooo ooxoo
 ox oxx xx
xoooo xoxx
============================
      xooo
x      xxo
x     oooo
    xx    
  x xx xxx
   x x x x
 x   xx   
  x   x x 
  xxx     
   oo  x  
============================
Paused waiting for input.

          
       x  
          
       x  
          
          
          
          
  xx      
          
============================
Paused waiting for input.

          
          
          
          
          
          
          
          
          
          
============================
Paused waiting for input.

          
          
          
          
          
          
          
          
          
          
============================
Paused waiting for input.

          
          
          
          
          
          
          
          
          
          
============================
Paused waiting for input.

The original commend line: 10 35 50 15 1 3
Simulated 15 steps.
There are 55 ants in total duing the simulation.
There are 0 ants remainning.
There are 50 doodlebugs in total duing the simulation.
There are 0 doodlebugs remainning.
Final grid:
          
          
          
          
          
          
          
          
          
          
============================
Production worked.

Production worked.