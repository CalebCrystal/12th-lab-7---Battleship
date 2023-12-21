/*
Caleb Crystal
C++
Lab 7 - Battleship game - 12th attempt

Description / Task: For placing the user’s ships, the user should be able to choose a xy coordinate and a
direction to place the ship. Again, the program should check to make sure the ship
placement is valid. The grid and coordinate system should be setup with x in the
horizontal direction and y in the vertical direction as follows:
For each turn of the game, the computer should randomly choose locations to fire and
the results should be shared and tracked on the screen. An example output on the
computer’s turn would show the computer firing and giving the coordinates, display the
result of “HIT!” and display an updated grid with ships and the locations of all of the
computer’s hits and misses. When displaying the grid, you must have the grid or each turn of the game, the computer should randomly choose locations to fire and
the results should be shared and tracked on the screen. An example output on the
computer’s turn would show the computer firing and giving the coordinates, display the
result of “HIT!” and display an updated grid with ships and the locations of all of the
computer’s hits and misses. When displaying the grid

*/



# include "Battleship1.h" // including the header file 

int main() { // main function
	int h1tCount = 0; // count for hits on the board
	Board b; // class board 
	ComputerBoard c; // class computer bpard 

	char board1[BoardSize][BoardSize]; // declares argument board1
	char board2[BoardSize][BoardSize]; // declares argument board2
	char board3[BoardSize][BoardSize]; // declares argument board3
	char board4[BoardSize][BoardSize]; // declares argument board4

	b.initializeBoard(board1, board4); // initializes boards 1 and 4
	b.PrintBoard(board1); // prints the board for user to see
	b.PlaceShip(board1); // deals with placeing the 5 ships 
	b.playerQuit(); // asks if the player wants to quit 

	c.initializeBoardComputer(board2, board3); // initializes boards 2 and 3
	c.PrintShips(board2);
	c.PrintBoardComputer(board2); // starts the ship printing function and prints all ships 

	do { // this is the game being played 
		c.playerfire(board2, board3); // first the player fires dealing with the computer ships and the players view
		b.computerFire(board4, board1);// the computer fires dealing damage to the players board and displying it on the computers sheet
		c.PrintBoardPlayerView(board3); // prints the players view of their boards
		b.playerQuit(); // asks if the player wants to quit
	} while ( h1tCount != 17); // runs untill the count is full of the ships being destroyed

	return 0; // returns zero;
}
