//***************************************************************************
// File name:   main.cpp
// Author:      chadd williams
// Date:        1/30/25
// Class:       CS 485
// Assignment:  Unit Test Paired Work
// Purpose:     Make sure Calculator.cpp compiles
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include "../include/Calculator.h"

//***************************************************************************
// Function:    main
//
// Description: Run some calculations
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main()
{
	Calculator cCalc;

	std::cout << cCalc.add(1, 2) << std::endl;
	std::cout << cCalc.add(3) << std::endl;
	std::cout << cCalc.multiply(4) << std::endl;
	std::cout << cCalc.divide(5) << std::endl;
	std::cout << cCalc.getTotal() << std::endl;

  return EXIT_SUCCESS;
}
