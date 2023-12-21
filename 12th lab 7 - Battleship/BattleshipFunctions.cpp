#include "Battleship1.h" // includes the header file 
#include <iostream> // include the i/o stream
#include <iomanip> // includes the io man ip library 
#include <string> // includes string I tried using them for enums 
using namespace std; // using the std library 

Board::Board() {} // constructor 

Board::~Board(){} // destructor 

void Board::initializeBoard(char board1[BoardSize][BoardSize], char board4[BoardSize][BoardSize]) // function to intialize the board, with the 1st and 3rd board 
{
    for (int row = 0; row < BoardSize; row++) // for loop that initailizes the players board for placement
        for (int col = 0; col < BoardSize; col++) // sets the rows
            board1[row][col] = '~'; // sets all row and col to ~ for water 
    for (int row = 0; row < BoardSize; row++) // sets board 4 that the computer is firing at 
        for (int col = 0; col < BoardSize; col++) // sets the rows 
            board4[row][col] = '~'; // all cells are set to ~

}
void Board::PrintBoard(char board1[BoardSize][BoardSize]) // prints the player board 
{
    for (int i = 0; i < BoardSize; ++i) { // prints the numbered boarder top 
        std::cout << i + 1 << " "; // accounts for the 0 start for the grid 
    }
    std::cout << std::endl; // ends the line 

    // Print board with cell values
    for (int row = 0; row < BoardSize; ++row) { // for loop prints the rows while the inner for loop prints col
        for (int col = 0; col < BoardSize; ++col) { // prints the col's
            std::cout << board1[row][col] << " "; // prints cell values
        }
        std::cout << std::endl; // ends the line to finish off the grid 
    }
}
void Board::PlaceShip(char board1[BoardSize][BoardSize]) // the place ship function arrguments are on board one
{
    int row, col, associatedNum; // declares the local varibles for the function
    char direction; // char is the directional choice 


    for (int place = 0; place < 5; place++) // runs 5 times to place 5 ships 
    {
        bool test = false; // the bool test is for error checking it lets the program down softly and doesn't exit the program or throw a juck value
        do { // do while allows the error checking to only be triggered at the end 
            cout << "enter a row to place a Ship" << endl << "(1 - " << BoardSize << ")" << endl; // asks the user to enter the row to place a ship
            cin >> row; // user enters row 
            row = row--; // subtracts one row to convert to the zero base on C++
            test = false; // sets the test to false in case the error was triggered 
            if (row >= BoardSize || row < 0) // checks the row input to make sure it's in range 
            {
                cout << "wrong input, try again" << endl; // couts the error messege 
                test = true; // sets the error message to true and triggers the while loop
            }
        } while (test == true);// keep the row in a while loop if the user inputs a wrong value
        do {// deals with the col checking seperatly so the user doesn't have to input the value twice 
            cout << "enter the col to place a ship" << endl << "(1 - " << BoardSize << ")" << endl; // sends a message to the user to give them paraeters 
            cin >> col; // enters in the col for placeing the ship
            col = col--; // converts for the zero base
            test = false; // bool is set to false for the same reasons as the row error checking 
            if (col >= BoardSize || col < 0) // sets parameters 
            {
                cout << "wrong input, try again" << endl; // sends the error message 
                test = true; // activates the while loop to keep the loop going 
            }
        } while (test == true); // if the while loop is true the error will keep going 

        board1[row][col] = '#'; // once all of the error checking is complete it wil print the start of the ship



        bool valid = true;

        do { // starts the error checking loop

            bool valid = true; // sets another error checking loop for the direction choosing by the user, and is true at the start of every loop

            std::cout << "enter the direction the ship should face" << std::endl; // presents what the users needs to do 
            std::cout << "enter U for up, D for down, R for right and L for left: "; // gives the parameters with what the user must enter in 
            std::cin >> direction; // enters in the direction 
            std::cout << "which ship would you like to place?"; // the user must input the length of the ship, I know this is a down fall I was having trouble with my logic
            cout << "enter 2,3,3,4, or a 5 " << endl; // this is what solves the issue for the time I tried to use an enum but I couldn't get a string to work to set equal
            // to a enum type even with the help of bard was being useless and told me nothing was wrong with my code but it didn't work

            cin >> associatedNum; // the user enters in the num of the length of the ship

            associatedNum = associatedNum - 1; // the ship is printed with already one square already on the board so this takes care of that 

            switch (direction) // using a switch statment for the direction of the ships 
            {
            case 'U': { // this case is for printing Up 
                for (int g = 0; g < associatedNum; ++g) { // prints the length of the ship in the direction that is choosen
                    board1[row - 1][col] = '#'; // prints in the choosen direction in incriments
                    row = row - 1; //sets row to current location
                }
                break;} // breaks the switch statment
            case 'D': { // down case 
                for (int g = 0; g < associatedNum; ++g) { // prints the length of the ship in the direction that is choosen
                    board1[row + 1][col] = '#'; // prints in the choosen direction in incriments
                    row = row + 1; //sets row to current location
                }
                break;} // breaks the switch statment
            case 'R': { // right case
                for (int g = 0; g < associatedNum; ++g) { // prints the length of the ship in the direction that is choosen
                    board1[row][col + 1] = '#'; // prints in the choosen direction in incriments
                    col = col + 1; //sets col to current location
                }

                break;} // breaks the switch statment
            case 'L': { // left case 
                for (int g = 0; g < associatedNum; ++g) { // prints the length of the ship in the direction that is choosen
                    board1[row][col - 1] = '#'; // prints in the choosen direction in incriments
                    col = col - 1; //sets col to current location
                }
                break;} // breaks the switch statment
            default: { // if the user entered in the wrong case
                valid = false; // sets the bool to false and runs the while loop
                cout << "wrong Input please try again" << endl; // error message 
                break;} // breaks the switch as a percausion



            }
        } while (valid == false); // error checker

        PrintBoard(board1); // prints the board after each valid ship is placed

        int row = 0; // sets the row back to zero
        int col = 0; // sets the col back to zero
        int associatedNum = 0; // sets the ship length back to zero\

        // I never found a way to validate the ship direction was okay, I simple ran out of time i had 
        // too many issues in my last program trying to solve the issue I simple destroyed my previous one
        // and I started from scratch to make this one on the 20th I know there are some kinks but everything works the way
        // it was supposed too but a few things don't have any checks happaning 
    }
}
void ComputerBoard::playerfire(char board2[BoardSize][BoardSize], char board3[BoardSize][BoardSize]) { // apart of the computer class for better access of the boards 

    int col, row, hitCount; // declars local Varibles 
    hitCount = 0; // sets hit count to 0 
    bool test = false; // sets a test variable to flase 
    do { // do while loop is the test to ensure that the inputs are valid
        cout << "enter a row to fire at the Computers Board" << endl << "(1 - " << BoardSize << ")" << endl; // asks for in row input to be fired on 
        cin >> row; // enters row 
        row = row--; // sets row to zero index
        test = false; // sets test false if there was an error that occurted earlier 
        if (row > BoardSize || row < 0) // parameter for the input 
        {
            cout << "wrong input, try again" << endl; // error messege 
            test = true; // starts the while loop
        }
    } while (test == true); // in the while loop untill correct input is given
    do { // do while loop is the test to ensure that the inputs are valid
        cout << "enter a colum to fire at the Computers Board" << endl << "(1 - " << BoardSize << ")" << endl; // enters the col to be fired in
        cin >> col; // enters col
        col = col--; // adjust for zero index
        test = false; // sets test to false 
        if (col > BoardSize || col < 0) // parameters for entering in a num
        {
            cout << "wrong input, try again" << endl; // error message
            test = true; // starts the while loop 
        }
    } while (test == true); // keeps running until the user enters in the correct numbers

    if (board2[row][col] == '#') // if statment checking if a ship is in the corrdinate that was specified by the user 
    {
        cout << "HIT!!!!" << endl; // if it was it cout's hit
        board3[row][col] = 'H'; // updates the board the player can see
        hitCount++; // adds one to the hit count 
    }
    else // anything else updates board to be a miss 
    {
        cout << "Miss..." << endl; // couts miss
        board3[row][col] = 'M'; // updates the board to be a 'M' for miss
    }



}