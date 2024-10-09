#include "InvestmentCalculator.h"
#include "InvestmentReport.h"
#include <iostream>

/*
Programmer: Conor Steward
Contact: 1conorsteward@gmail.com
Date: 10/8/24
Version: 2.0
Purpose: This file handles user input to calculate and generate various investment reports, including regular investments, Dividend Reinvestment Plan (DRP), and high-risk vs low-risk strategy comparisons.
Issues: No known issues.
*/

// Main function to handle user input and generate reports
// Purpose: Queues user input and generates reports based on investment strategies.
// Complexity: O(n) for all major operations where n is the number of years (related to reports).
int main() {
    // Declare variables for user input
    double initialInvestment, monthlyDeposit, annualInterestRate;
    double highRiskRate, lowRiskRate, dividendYield, stockPriceGrowthRate;
    int numberOfYears;

    std::cout << "*************************************" << std::endl;
    std::cout << "***********  Data Input  ************" << std::endl;

    // Get user input for general investment
    std::cout << "* Enter Initial Investment Amount:    ";
    std::cin >> initialInvestment;

    std::cout << "* Enter Monthly Deposit:              ";
    std::cin >> monthlyDeposit;

    std::cout << "* Enter Annual Interest Rate (%):     ";
    std::cin >> annualInterestRate;

    // Get user input for high-risk and low-risk strategy
    std::cout << "* Enter High-Risk Rate (%):           ";
    std::cin >> highRiskRate;

    std::cout << "* Enter Low-Risk Rate (%):            ";
    std::cin >> lowRiskRate;

    // Get user input for Dividend Reinvestment Plan
    std::cout << "* Enter Dividend Yield (%):           ";
    std::cin >> dividendYield;

    std::cout << "* Enter Stock Price Growth Rate (%):  ";
    std::cin >> stockPriceGrowthRate;

    // Get the number of years for the investment plan
    std::cout << "* Enter Number of Years:              ";
    std::cin >> numberOfYears;

    std::cout << "\n*************************************\n" << std::endl;

    // Create an instance of InvestmentCalculator using the overloaded constructor
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, highRiskRate, lowRiskRate, numberOfYears);

    // Calculate and display regular investment details
    std::cout << "Investment Details (With Monthly Deposits):" << std::endl;
    calculator.calculateInvestment();

    // Display static reports
    std::cout << "\nGenerating Static Reports..." << std::endl;
    InvestmentReport::displayStaticReports(calculator);

    // Display the Dividend Reinvestment Plan report
    std::cout << "\nGenerating Dividend Reinvestment Plan (DRP) Report..." << std::endl;
    InvestmentReport::displayDividendReinvestment(calculator, dividendYield, stockPriceGrowthRate);

    // Display high-risk vs low-risk strategy comparison
    std::cout << "\nComparing High-Risk vs Low-Risk Strategies..." << std::endl;
    InvestmentReport::displayRiskComparison(calculator);

    // Wait for user input before closing the console
    std::cout << "\n**** Press any key to continue... ****" << std::endl;
    std::cin.ignore();
    std::cin.get();

    return 0;
}
