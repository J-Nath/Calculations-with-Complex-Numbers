/*
Ahmad Gonzalez
CPS 272 Machine Problem 1 Part 1

Program to read two complex number from the user as one string and do arithmatic on them.
*/

#include "complex.cpp"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
using std::stringstream;

int main()
{

	cout << endl;

	Complex comp(12.3, 23.4);//Object one with arguments to the constructor
	Complex userComp1(33.0, 42.3);//Object two with arguments to the constructor
	Complex userComp2;
	

	cout << "Enter the first complex number with no spaces and no parentheses: ex." << comp;

	cin >> comp;

	cout << "Enter the second complex number with no spaces and no parentheses: ex." << userComp1;

	cin >> userComp1;

	cout << endl;

	userComp2 = comp + userComp1;

	cout << "The addition of complex numbers: " << userComp2;


	userComp2 = comp - userComp1;

	cout << "The subtraction of complex numbers: " << userComp2;


	userComp2 = comp * userComp1;

	cout << "The multiplication of complex numbers: " << userComp2;


	userComp2 = comp / userComp1;

	cout << "The division of complex numbers: " << userComp2;



	return 0;
}