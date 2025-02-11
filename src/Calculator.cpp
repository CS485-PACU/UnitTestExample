//***************************************************************************
// File name:   Calculator.cpp
// Author:      chadd williams
// Date:        1/27/25
// Class:       CS 485
// Assignment:  Unit test example
// Purpose:     Provide a class to unit test
//***************************************************************************


#include "../include/Calculator.h"
#include <stdexcept>
using namespace CS485_Calc;


//***************************************************************************
// Constructor:  Calculator
//
// Description: Create object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Calculator::Calculator () {

}

//***************************************************************************
// Destructor:  Calculator
//
// Description: Destroy object & dynamic memory
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Calculator::~Calculator () {
	if (nullptr != mpRunningTotal) {
		delete mpRunningTotal;
	}
}

//***************************************************************************
// Function:    Add
//
// Description: Add two ints and set the running total
//
// Parameters:  lhs - the left operand
//							rhs - the right operand
//
// Returned:    The new running total
//***************************************************************************
double Calculator::add (int lhs, int rhs) {
	if (nullptr == mpRunningTotal) {
		mpRunningTotal = new double;
	}
	*mpRunningTotal = lhs + rhs;

	return *mpRunningTotal;
}

//***************************************************************************
// Function:    Add
//
// Description: Add one int to the running total
//
// Parameters:  rhs - the right operand
//							
// Throws:			Throws exception if no running total exists
//
// Returned:    The new running total
//***************************************************************************
double Calculator::add (int rhs) {
	if (nullptr == mpRunningTotal) {
		throw std::invalid_argument ("No running total");
	}

	*mpRunningTotal += rhs;

	return *mpRunningTotal;
}

//***************************************************************************
// Function:    getTotal
//
// Description: Return the current running total
//
// Parameters:  None
//							
// Throws:			Throws exception if no running total exists
//
// Returned:    The current running total
//***************************************************************************
double Calculator::getTotal () const {
	if (nullptr == mpRunningTotal) {
		throw std::invalid_argument ("No running total");
	}

	return *mpRunningTotal;
}

//***************************************************************************
// Function:    clear
//
// Description: Destroy the current running total
//
// Parameters:  None
//							
// Throws:			None
//
// Returned:    None
//***************************************************************************
void Calculator::clear () {
	if (nullptr != mpRunningTotal) {
		delete mpRunningTotal;
		mpRunningTotal = nullptr;
	}
}
/*
Calculator& Calculator::operator+= (int rhs) {
	this->add (rhs);

	return *this;
}

Calculator& Calculator::operator+= (const Calculator& rcRHS) {

	this->add (rcRHS.getTotal ());
	return *this;
}
*/
Calculator& Calculator::operator= (double value) {
	if (nullptr == mpRunningTotal) {
		mpRunningTotal = new double;
	}
	*mpRunningTotal = value;
	return *this;
}

CS485_Calc::Calculator& CS485_Calc::operator+= (CS485_Calc::Calculator &rcLHS, 
																								int rhs) {
	rcLHS.add (rhs);
	return rcLHS;
}

CS485_Calc::Calculator& CS485_Calc::operator+= (CS485_Calc::Calculator &rcLHS, 
																		const CS485_Calc::Calculator& rcRHS) {
	rcLHS.add (rcRHS.getTotal ());
	return rcLHS;
}