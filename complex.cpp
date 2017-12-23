#include "complex.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
using std::stringstream;

ostream &operator<<(ostream& output, Complex& theComplex)//Overload output operator to display the custom output
{
	output << fixed << showpoint;
	output << setprecision(2);
	output << "(";
	output << theComplex.real;
	output << " + ";
	output << theComplex.imag;
	output << "i)";
	cout << endl;

	return output; //return the ostream object
}

istream &operator>>(istream& input, Complex& theComplex)//Overload input operator to input a string and send it to the function to convert it into a double value.
{
	string complexStr;

	input >> complexStr;
	theComplex.convertStringToComplex(complexStr);
	

	return input; //return the istream object
}

void Complex::convertStringToComplex(const string& complexString)//Function to break string apart and convert it into double values.
{
	//cout << endl;
	//cout << complexString << "  String before Convertion" << endl;

	stringstream initialString(complexString);//Insert string into string steam and use it to break the input string apart
	double x = 0;
	char y;
	string z;
	

	initialString >> x;
	initialString >> y;
	initialString >> z;
	

	//cout << x << " Value for X" << endl;

	//cout << y << " Value for Y" << endl;

	//cout << z << " Value for Z" << endl;

	initialString.str("");
	initialString.clear();//Clear the string steam



	double u = stod(z);//convert the last part of the stringstream into a double value

	//cout << u << " Value for U" << endl;
	
	setReal(x);//Send the real number to set function

	if (y == '+')//Determine if the complex number was positive or negative
	{
		setImaginary(u);
	}
	else
	{
		u = -1 * u;
		setImaginary(u);
	}
	

}

Complex::Complex(double re, double im)//Constructor and initialize real and imag variables
{
    real = re;
    imag = im;
}


void Complex::setReal(double& re)//Functin to set real number
{
    
    this->real = re;

    //cout << real1 << " setReal1" << endl;
}

void Complex::setImaginary(double& im)//Function to set imaginary number
{
    
    this->imag = im;

    //cout << real1 << " setReal1" << endl;
}

double getReal(void)//Function to get real number
{
	double real;
    return  real;
}


Complex operator+( const Complex& lhs, const Complex& rhs )//Overload addition operator
{
	Complex addAnswer;

  	addAnswer.real = lhs.real + rhs.real;

  	addAnswer.imag = lhs.imag + rhs.imag;

  return addAnswer;
}

Complex operator-( const Complex& lhs, const Complex& rhs )//Overload subtraction operator
{
	Complex subAnswer;

  	subAnswer.real = lhs.real - rhs.real;

  	subAnswer.imag = lhs.imag - rhs.imag;

  return subAnswer;
}

Complex operator*( const Complex& lhs, const Complex& rhs )//Overload multiplication operator
{
	Complex multiAnswer;

	double a = lhs.real;
	double b = lhs.imag;
	double c = rhs.real;
	double d = rhs.imag;

	multiAnswer.real = ((a*c) - (b*d));
	multiAnswer.imag = (b - d);

	//multiAnswer.real = ((lhs.real * rhs.imag) - (lhs.imag * rhs.imag));
	//multiAnswer.imag = (lhs.imag - rhs.imag);

	return multiAnswer;
}

Complex operator/( const Complex& lhs, const Complex& rhs )//overload division operator
{
	Complex divAnswer;

	double a = lhs.real;
	double b = lhs.imag;
	double c = rhs.real;
	double d = rhs.imag;

	divAnswer.real = ( ((a*c) + (b*d)) / ((c*c) + (d*d)) );
	divAnswer.imag = ( ((b*c) + (a*d)) / ((c*c) + (d*d)) );

	//divAnswer.real = (lhs.real * rhs.real) / ((rhs.real*rhs.real) + (rhs.imag*rhs.imag));
	//divAnswer.imag = (lhs.imag - rhs.imag);

  	
  	return divAnswer;
}