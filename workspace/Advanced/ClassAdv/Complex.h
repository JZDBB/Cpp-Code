#pragma once
#include<iostream>
using namespace std;
class Complex
{
public:
	Complex();
	Complex(double r, double i);
	
	~Complex();

	//Complex operator + (const Complex &c2) const;
	//Complex operator - (const Complex &c2) const;
	friend Complex operator + (const Complex &c1, const Complex &c2);
	friend Complex operator - (const Complex &c1, const Complex &c2);
	friend ostream & operator << (ostream &out, const Complex &c);
	void display() const;

private:
	double real, imag;
};

