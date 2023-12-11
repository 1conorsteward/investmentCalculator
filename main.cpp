#include "InvestmentCalculator.h"
#include "InvestmentReport.h"
/*
Conor Steward
11/21/23
This file is used to que the user to input their varying data inputs for the report calculations
conor.steward@snhu.edu
*/

#include <iostream>

int main() {
    // Get user input
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int numberOfYears;

    std::cout << "*************************************" << std::endl;
    std::cout << "***********  Data Input  ************" << std::endl;

    std::cout << "* Enter Initial Investment Amount:    ";
    std::cin >> initialInvestment;

    std::cout << "* Enter Monthly Deposit:              ";
    std::cin >> monthlyDeposit;

    std::cout << "* Enter Annual Interest (Compounded): ";
    std::cin >> annualInterestRate;

    std::cout << "* Enter Number of Years:              ";
    std::cin >> numberOfYears;

    // Create an instance of InvestmentCalculator
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, numberOfYears);

    // Calculate and display investment details
    calculator.calculateInvestment();

    // Display static reports
    InvestmentReport::displayStaticReports(calculator);

    // Wait for user input before closing the console
    std::cout << "**** Press any key to continue... ****";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
