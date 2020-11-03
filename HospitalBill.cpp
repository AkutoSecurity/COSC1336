//This program calculates the total charge of a patient's hospital visit.
#include <iostream>
#include <iomanip>
using namespace std;

//Prototypes
double calc(int, double, double, double);
double calc(double, double);
void valid(int, int, double, double, double);

int main() {
	//Variables
	int inOut = 0, days = 0;
	double dailyRate = 0,
		servChrg = 0,
		medChrg = 0;

	//Ask if user was an in/out-patient
	cout << "Welcome to the hospital charge calculator.\n";
	do {
		cout << "Please enter if your patient was admitted as an in-patient (0) or out-patient (1): ";
		cin >> inOut;
	} while (inOut != 1 && inOut != 0); //Makes sure user enters 0 or 1
	valid(inOut, days, dailyRate, servChrg, medChrg);

	return 0;
}

void valid(int inOut, int days, double dailyRate, double servChrg, double medChrg) {
	switch (inOut)
	{
	case 0: //In-patient data
		cout << "Please enter the number of days spent in the hospital: ";
		cin >> days;
		cout << endl << "Please enter the hospital's daily rate: ";
		cin >> dailyRate;
		cout << endl << "Please enter the medical service fee: ";
		cin >> servChrg;
		cout << endl << "Please enter the medication fee: ";
		cin >> medChrg;
		cout << endl << "The hospital charges for this patient are: $" 
			<< calc(days, dailyRate, servChrg, medChrg)
			<< endl;
		break;

	case 1: //Out-patient data
		cout << endl << "Please enter the medical service fee: ";
		cin >> servChrg;
		cout << endl << "Please enter the medication fee: ";
		cin >> medChrg;
		cout << endl << "The hospital charges for this patient are: $" 
			<< calc(servChrg, medChrg) << endl;
		break;
	} while ((days < 0) || (dailyRate < 0) || (servChrg < 0) || (medChrg < 0));
}

//Calculates total charge based on in-patient data
double calc(int days, double dailyRate, double servChrg, double medChrg) {
	return (days * dailyRate) + calc(servChrg, medChrg);
}

//Calculates total charge based on out-patient data
double calc(double servChrg, double medChrg) {
	return servChrg + medChrg;
}
