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

//***************************************************************************
// Constructor:  Calculator
//
// Description: Create object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Calculator::Calculator() {

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
Calculator::~Calculator() {
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
double Calculator::add(int lhs, int rhs){
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
double Calculator::add(int rhs){
	if (nullptr == mpRunningTotal) {
		throw std::invalid_argument("No running total");
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
double Calculator::getTotal() const {
	if (nullptr == mpRunningTotal) {
		throw std::invalid_argument("No running total");
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
void Calculator::clear()  {
	if (nullptr == mpRunningTotal) {
		delete mpRunningTotal;
		mpRunningTotal = nullptr;
	}
}
