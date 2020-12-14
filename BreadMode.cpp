//This program calculates the mode of 21 people's
//bread consumption.
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

int getMode(int[], int);

int main() {

	int bread[21];
	int size = 21;

	//Welcome users
	cout << "Welcome to Bread Mode. You will be asked to enter the amount \n"
		<< "of bread consumed by each of 21 people and be given the mode. \n"
		<< "MODE: The most occurring value in a set of numbers.\n";
	cout << "*****************************************************************\n";

	//Get bread amounts
	cout << "Please enter the amount of bread loaves each person eats in a year: \n";
	for (int i = 0; i < 21; ++i) {
		do {
			cout << "Person " << (i + 1) << ": ";
			cin >> bread[i];
			if (bread[i] < 0) { //Appears when user enters a negative number of loaves
				cout << "ERROR: You have entered a value less than zero. Please re-enter: ";
				cin >> bread[i];
			}
		} while (bread[i] < 0);
	}

	//Display result
	cout << "\n**********************************************************\n"
		<< "The results are in!\nThe most common number of bread loaves eaten in one year was " << getMode(bread, size) << "!" << endl;

	return 0;
}

//Calculate the mode of the bread array
int getMode(int bread[], int size) {
	int number = bread[0];
	int mode = number;
	int countMode = 0;
	int count = 1;

	for (int i=1; i<size; i++){
    if (bread[i] == number)
    {
        count++; //Adds to the number of times a number reoccurred
    }
    else
    {
        if (count > countMode) //Sets new mode
        {
            countMode = count;
            mode = number;
        }
        count = 1;
        number = bread[i]; //Sets most occurring number as mode
    }
	}

	return mode;
}
