#include "Battleship1.h" // header file 
#include <iostream> // open io stream library 
#include <iomanip> // opens the io man ip library
#include <cstdlib> // opens for the random number generator library
#include <ctime> // time string is open

using namespace std; // using the name space libray for easy access and quickness

ComputerBoard::ComputerBoard() // constructor 
{
    srand(time(NULL));

}

ComputerBoard::~ComputerBoard(){} // destructor

void ComputerBoard::initializeBoardComputer(char board2[BoardSize][BoardSize], char board3[BoardSize][BoardSize]) // this function initializes the board for the computer to 
{ // write on, both the board that the computer is placing and the board that the player is firing onto
    for (int row = 0; row < BoardSize; row++) // sets all row values
        for (int col = 0; col < BoardSize; col++) // sets all col values
            board2[row][col] = '~'; // all cells are filled with the ~ for water
    for (int row = 0; row < BoardSize; row++) // sets all row values
        for (int col = 0; col < BoardSize; col++)// sets all col values
            board3[row][col] = '~'; // all cells are filled with the ~ for water
}
void ComputerBoard::PrintBoardComputer(char board2[BoardSize][BoardSize]) // print the board that the computer is place ships on so I could tell if it was working 
{
    for (int i = 0; i < BoardSize; ++i) { // prints the header 1-10 on top of the board 
        std::cout << i + 1 << " "; // adds one to adjust for the zero index
    }
    std::cout << std::endl; // ends the line on the grid for the next function

    // Print board with cell values 
    for (int row = 0; row < BoardSize; ++row) {  // prints the rows with values 
        for (int col = 0; col < BoardSize; ++col) { // prints the col with respective values 
            std::cout << board2[row][col] << " "; // gets the board values
        }
        std::cout << std::endl; // ends the line 
    }
}
void ComputerBoard::PrintShips(char board2[BoardSize][BoardSize]) // prints the computers ships 
{
    int row, col, direction, shipL; // dec's the local varibles for the program, the rows, col, direc and ship length

    for (int associatedNum = 2; associatedNum <= 5; associatedNum++) { // the counter also acts like the ships length 



        row = ranNum10(); // random number chooses row 
        col = ranNum10(); // random number chooses col 

        board2[row][col] = '#'; // sets the starting point of the ship


        shipL = associatedNum - 1; // minus one for the starting point already on the ship

        direction = ranNum4(); // ran number generator chooses one of 4 directions for the ship

        switch (direction) // switch based off the random number
        {
        case 1: { // this case moves the ship up 
            for (int g = 0; g < shipL; ++g) { // goes off the counter for the length 
                board2[row - 1][col] = '#'; // outputs the next part of the ship 
                row = row - 1; // moves the row to squar it just printed so it can print the rest 
            }
            break;} // breaks the switch statment
        case 2: { //this case moves the ship down
            for (int g = 0; g < shipL; ++g) { // outputs the next part of the ship 
                board2[row + 1][col] = '#'; // outputs the next part of the ship 
                row = row + 1;
            }
            break;} // breaks the switch statment
        case 3: { // moves the ship right 
            for (int g = 0; g < shipL; ++g) { // outputs the next part of the ship 
                board2[row][col + 1] = '#'; // outputs the next part of the ship 
                col = col + 1; 
            }

            break;} // breaks the switch statment
        case 4: { // moves the ship left
            for (int g = 0; g < shipL; ++g) { // outputs the next part of the ship 
                board2[row][col - 1] = '#'; // outputs the next part of the ship 
                col = col - 1; 
            }
            //PrintBoardComputer(board2); used for error checking 
            int row = 0; // resets the row to zero
            int col = 0; // resets the col to zero
        }
        }

    }

}
void Board::computerFire(char board4[BoardSize][BoardSize], char board1[BoardSize][BoardSize]) // the computer can fire with random number gen
{
    int col, row; // the ints are col and row
   
    
    row = ranNum101(); // sets row to random num
    col = ranNum101(); // sets the col to random num

    cout << "the Computer chose row was: " << row << endl << "and the computer chose col: " << col << endl; // couts the row and col the ship is firing at.
    if (board1[row][col] == '#') // checks to board one if the selected spot is a # or not
    {
        cout << "HIT!!!!" << endl; // couts hit to the user 
        board4[row][col] = 'H'; // places a H on the computers board 
        board1[row][col] = 'H'; // places a H on the players board that hold the ships
       
    }
    else
    {
        cout << "Miss..." << endl; // couts that the computer missed
        board4[row][col] = 'M'; // places a M on the board of the computer
        board1[row][col] = 'M'; // places an M on the users board for them to see
    }
}
void ComputerBoard::PrintBoardPlayerView(char board3[BoardSize][BoardSize]) // prints the board where the player is shooting 
{
    for (int i = 0; i < BoardSize; ++i) { // prints the header 1- 10 
        std::cout << i + 1 << " "; // sets a space between numbers 
    }
    std::cout << std::endl; // end the lines of the final grid line 

    // Print board with cell values
    for (int row = 0; row < BoardSize; ++row) { // prints the row values
        for (int col = 0; col < BoardSize; ++col) { // prints the col values
            std::cout << board3[row][col] << " "; // prints 
        }
        std::cout << std::endl; // ends the line of the final grid line 
    }
}

