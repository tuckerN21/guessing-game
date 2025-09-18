// Tucker Neikirk
// 9/20/2024
// Guessing Game

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Seed random number generator
    
    srand(time(0));
    
    bool playAgain = true; // Decides if user wants to play again   
    char userChoice; // Holds the user's choice for playing again
    int numPlays = 1; // Holds the number of times the game is played        
    
    // Welcome the player to the game
    
    cout << "Greetings, my name is Jarvis, I will attempt to guess your number!" << endl;

    while (playAgain == true) {
        
        // Initalize variables for game
        
        int computerGuess = -1; // Holds computer's guess     
        int numberOfGuesses = 0; // Holds number of computer's guesses     
        int myNumber; // Holds user's number         
        int min = 1; // Minimum number user can enter                
        int max = 25; // Maximum number user can enter              
        int range = max - min + 1; // Range for computer's guess  
        int i = 0; // Initalize i for for-loops

        do { // Do-while loop for user input
            cout << "What is your number? (1-25) ";
            cin >> myNumber;
        
            if ((myNumber < min) || (myNumber > max)) { // User inputs invalid number
                cout << "Please enter a number that fits the parameters." << endl;
            }
        } while ((myNumber < min) || (myNumber > max)); // Loops if user inputs invalid number

        cout << "You entered: " << myNumber << endl;

        while (computerGuess != myNumber) { // While loop for computer's guesses
            cout << endl << "I am going to guess from one of these numbers..." << endl;
            
            for (i = min; i <= max; i++) { // List of numbers that computer is guessing from
                if (i < max) { // If-else statement to output commas in number list
                    cout << i << ", "; 
                }
                else if (i == max) {
                    cout << i;         
                }
            }
            
            numberOfGuesses++;
            
            range = max - min + 1;
            
            computerGuess = rand() % range + min; // Random computer guess from 1-25
            
            cout << endl << "Guess #" << numberOfGuesses << " is: " << computerGuess << endl; // Output computer's guess and number of guesses so far
            
            if (computerGuess < myNumber) { // Computer guesses too low
                cout << "Looks like I guessed too low!" << endl;
                min = computerGuess + 1; 
            }
            else if (computerGuess > myNumber) { // Computer guesses too high
                cout << "Looks like I guessed too high!" << endl;
                max = computerGuess - 1; 
            }
            else if (computerGuess == myNumber ) { // Computer guesses correctly
                cout << "Guessed it! Your number was " << myNumber << endl;
                cout << "It took me " << numberOfGuesses << " tries. ";
                if (numberOfGuesses < 4) { // If-else statement to determine how the computer did
                    cout << "I did great!" << endl; // The computer did great
                }
                else if ((numberOfGuesses >= 4) && (numberOfGuesses <= 5)) { // The computer did good
                    cout << "I did good." << endl;
                }
                else if (numberOfGuesses > 5) { // The computer did bad
                    cout << "I did bad." << endl;
                }
                
                do { // Do-while loop for user input
                    cout << "Would you like to play again? (Y or N) ";
                    cin >> userChoice;
                    
                    if (userChoice == 'Y' || userChoice == 'y') { // User chooses to play again
                        playAgain = true;
                        numPlays++; 
                    }
                    else if (userChoice == 'N' || userChoice == 'n') { // User chooses not to play again
                        cout << "Thanks for playing!" << endl;
                        playAgain = false; 
                    }
                    else { // User enters invalid input
                        cout << "Invalid input! Please enter Y or N." << endl;
                    }
                    
                } while (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n');  // Loops if user enters invalid input
            }

        }
    }

    return 0; 
}
