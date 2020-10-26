//This program calculates a person's BMI and tells their
//weight group.
#include <iostream>
using namespace std;

int main() {
	//Variables
	float weight = 0,
		height = 0,
		bmi = 0;

	//Get weight and height
	cout << "                  Welcome to the BMI calculator.\n"
		<< "      Please enter your weight in pounds and height in inches."
		<< endl << endl;
	cin >> weight >> height;

	//Calculate BMI
	bmi = weight * 703 / (height * height);

	//Display BMI and weight group
	if (bmi >= 18.5 && bmi =< 25) {
		cout << "Your BMI is " << bmi << ". This is optimal!\n";
	}
	else if (bmi < 18.5) {
		cout << "Your BMI is " << bmi << ". This is underweight.\n";
	}
	else if (bmi > 25) {
		cout << "Your BMI is " << bmi << ". This is overweight.\n";
	}
	cout << endl;


	return 0;

}
