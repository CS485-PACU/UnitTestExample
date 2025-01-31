//***************************************************************************
// File name:   Calculator.h
// Author:      chadd williams
// Date:        1/27/25
// Class:       CS 485
// Assignment:  Unit test example
// Purpose:     Provide a class to unit test
//***************************************************************************

#pragma once

class Calculator {

	public:
		Calculator();

		~Calculator();

		double add(int lhs, int rhs);
		double add(int rhs);

		double subtract(int lhs, int rhs);
		double subtract(int rhs);

		double multiply(int lhs, int rhs);
		double multiply(int rhs);

		double divide(int lhs, int rhs);
		double divide(int rhs);

		double getTotal() const;

		void clear();

	private:
		double *mpRunningTotal = nullptr;

};
