#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
using std::stringstream;



class Complex
{
    friend ostream &operator<<(ostream &output, Complex &theComplex);
    friend istream &operator>>(istream &input, Complex &theComplex);
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
    friend Complex operator-(const Complex& lhs, const Complex& rhs);
    friend Complex operator*(const Complex& lhs, const Complex& rhs);
    friend Complex operator/(const Complex& lhs, const Complex& rhs);

    public:
        Complex(double re = 0.0, double im = 0.0);
        void setReal(double& re);
        void setImaginary(double& im);
        double getReal(void);
        double getImaginary(void) const {return imag;}
        void convertStringToComplex(const string& complexString);
    

    private:
        double real;
        double imag;

};

#endif