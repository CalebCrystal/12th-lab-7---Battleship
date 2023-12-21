#include <iostream>
#include <cctype>
#include <ctime>
#include <iomanip> 

#ifndef BATTLESHIP7LAB_H
#define BATTLESHIP7LAB_H

static const int BoardSize = 10; // using a Constant for the size of the board in case the board size needs to be changed 
// this is also incorperated into the message outputs so if it ever did change you can see the change there too


class Board //Board class is dealing with the ship placement and the board itself, this includes the board the player places the ships on and 
{ // the board that the computer is firing on
public:

	Board(); // constructor 
	~Board(); // destructor 

	char board1[BoardSize][BoardSize]; // sets the H and W of the players board with places ships including the const BoardSize
	char board4[BoardSize][BoardSize]; // sets the H and W of the computers board that the computer fires onto 

	void initializeBoard(char board1[BoardSize][BoardSize], char board4[BoardSize][BoardSize]); // this function starts the board with the ~ symbols for water on both boards
	void PrintBoard(char board1[BoardSize][BoardSize]); // this prints the board that the player is placing ships on 

	void PlaceShip(char board1[BoardSize][BoardSize]); // this function allows the ships to be placed a downfall of this funcion is that the player must enter in the lengh of the ship
	// I attempted to use a Enum to fix the problem and assign them as values but the string was not working and I could get Bard to give me a differnt version of my code to fix the problem
	void computerFire(char board4[BoardSize][BoardSize], char board1[BoardSize][BoardSize]); // allows the computer to fire at the enemys board, this was here for easy access to the other boards 

	void playerQuit(){ // the quit function allows the user at incrimetned times to quit the program 
		char play; // a char character of the yes no question
		std::cout << "Quit Y/N?" << std::endl; // asks the user to enter Y for yes and N for no
		std::cin >> play; // user enters the char
		if (play == 'Y' || play == 'y') // works with either the uppercase Y and lowercase y
		{
			std::cout << "Thanks for Playing!"; // if he user chooses yes than the program terminates 
			return; // returns and ends program
		}
		
	}

	int ranNum101() { // random number generator for 0-9
		srand(time(NULL)); //sets time stand to Null for the random number 
		int randomNum10 = rand() % 10; // generates the random number from 0-9 and sets that equall to the randomNum10;
		return randomNum10; // returns the value that the random number choose
	}

};

class ComputerBoard // this class deals with all of the computer functions, the placements and the firing at the ships; 
{

public:// public function, I had made a private but i could get my get or set functions to work 

	ComputerBoard(); // constructor 
	~ComputerBoard(); // destructor 

	char board2[BoardSize][BoardSize]; // this board the computer places it's ships on 
	char board3[BoardSize][BoardSize]; // this board the computer fires on 


	void initializeBoardComputer(char board2[BoardSize][BoardSize], char board3[BoardSize][BoardSize]); // initializes both boards for the computer the placments and to be firing at 
	void PrintBoardComputer(char board2[BoardSize][BoardSize]); // prints the computer board that places it's ships 
	void PrintBoardPlayerView(char board4[BoardSize][BoardSize]);

	void PrintShips(char board2[BoardSize][BoardSize]); // this places the ships for the computer 

	int ranNum10() { // random number generator for the grid on the board to choose a starting point on the grid 
		srand(time(NULL)); // sets the time strand to Null
		int randomNum10 = rand() % 10; // sets the random number to randomNum10
		return randomNum10; // return the random value 
	}

	int ranNum4() { // random number that chooses the direction of the ship up, down, right left
		srand(time(NULL)); // sets time strand to Null
		int randomNum4 = rand() % 4; // sets the random number to randomNum4 
		return randomNum4; // returns random number to the called function
	}

	void playerfire(char board2[BoardSize][BoardSize], char board3[BoardSize][BoardSize]); // this allows the player to fire at the boards within the class of the Computer 

};


#endif
