#include <cstdio>
#include <iostream>
#include <ctime>
#include <random>


using namespace std;

int main() {

	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1,1000 };

	int guess{ 0 };
	int number{ 0 };
	bool play{ true };
	bool guessed{ false };
	char option{ 'a' };



	while (play) {

		cout << "Guess the number game!" << endl << "I have a number between 1 and 1000." << endl <<
			"Can you guess my number?" << endl << "Please, type your first guess: ";

		number = randomInt(engine);
		

		while (!guessed) {
			cin >> guess;
			if (guess == number) {
				guessed = true;
				cout << "Excellent! You guessed the number! \nWould you like to play again(y or n)? ";
				cin >> option;
				if (option == 'y')
					play = true;
				else if (option == 'n')
					return 0;
			}
			else if (guess < number) {
				cout << "Too low. Try again: ";
			}
			else if (guess > number) {
				cout << "Too high. Try again: ";
			}
		}

		guessed = false;
		cout << "\n\n\n\n\n\n\n\n\n";
	}

	
}