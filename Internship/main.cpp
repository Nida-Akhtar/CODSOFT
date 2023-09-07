#include <iostream>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding the random number generator
using namespace std;
int main() {
    
  srand(static_cast<unsigned int>(time(nullptr)));
  
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int numberOfGuesses = 0;
   cout << "                    Welcome!    \n";
   cout << "------------ Number Guessing Game ---------------      \n";
   
   
   cout << "Rule or Guess: The number is between 1 and 100. Try to guess it.\n";
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        numberOfGuesses++;
        if (userGuess > randomNumber)
        {
        cout << "Too high! Try again.\n";
        }
        else if (userGuess < randomNumber)
        {
        cout << "Too low! Try again.\n";
        }
        else {
        cout << "Congratulations! You guessed the number in " << numberOfGuesses << " guesses.\n";
        }
    }
    while (userGuess != randomNumber);
    return 0;
}



