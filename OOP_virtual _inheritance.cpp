// OOP_virtual _inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


class A
{
public:
	A() : k(10) {}
	void printK()
	{
		std::cout << k << std::endl;
	}

protected:
    int k;
};
 
class B: public /*virtual*/ A 
{
public:
	void fB()
	{
		k++; 
	}
};
 
class C: public /*virtual*/ A 
{
public:
	void fC()
	{
		k--;
	}
};
 
class D: public B, public C 
{
public:
	void f()
	{
		fB();
		fC();
	}
};



int main()
{
	D tmp_d;
	tmp_d.f();
	//tmp_d.printK();  //error C2385: ambiguous access of 'printK'

	return 0;
}

