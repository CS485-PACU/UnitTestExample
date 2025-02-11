//***************************************************************************
// File name:   Calculator.h
// Author:      chadd williams
// Date:        1/27/25
// Class:       CS 485
// Assignment:  Unit test example
// Purpose:     Provide a class to unit test
//***************************************************************************

#pragma once

namespace CS485_Calc {

class Calculator {

public:
	Calculator ();

	Calculator (const Calculator& rcCalc) = delete;
	Calculator& operator= (const Calculator& rcCalc) = delete;
	Calculator& operator= (double value);

	~Calculator ();

	double add (int lhs, int rhs);
	double add (int rhs);

	//Calculator& operator+= (int rhs);
	//Calculator& operator+= (const Calculator& rcRHS);

	double getTotal () const;
	void clear ();

private:
	double* mpRunningTotal = nullptr;
};

Calculator& operator+= (Calculator &rcLHS, int rhs);
Calculator& operator+= (Calculator &rcLHS, const Calculator& rcRHS);

}