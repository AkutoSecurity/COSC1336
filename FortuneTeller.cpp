//This program predicts the user's future using
//random numbers and an if/else if statement.
#include <iostream>
#include <string> //Needed to use strings
#include <cstdlib> //Needed for random numbers
#include <ctime>
using namespace std;

int main() {
	//Strings to hold user-entered careers
	string career1, career2, career3;

	int randomNum; //Will hold the randomly generated integer

	//Seed the random generator
	unsigned seed = time(0);
	srand(seed);

	//Explain the game and get the player's career choices
	cout << "I am a fortune teller. Look into my crystal screen \n"
		<< "and enter 3 careers you would like to have.Example: \n\n"
		<< "           chef \n           astronaut \n           CIA agent \n\n"
		<< "Then I will predict what you will be. \n\n";

	cout << "Career choice 1: ";
	getline(cin, career1);
	cout << "Career choice 2: ";
	getline(cin, career2);
	cout << "Career choice 3: ";
	getline(cin, career3);

	//Randomly generate an integer between 1 and 4.
	randomNum = 1 + rand() % 4;

	//Use branching logic to output the prediction
	if (randomNum == 1)
		cout << "\nYou will be a " << career1 << ". \n";
	else if (randomNum == 2)
		cout << "\nYou will be a " << career2 << ". \n";
	else if (randomNum == 3)
		cout << "\nYou will be a " << career3 << ". \n";
	else
		cout << "\nSorry, you will not be any of these. \n";

	return 0;
}
